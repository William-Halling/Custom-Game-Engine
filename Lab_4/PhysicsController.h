#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>      // for std::pair
#include <glm/glm.hpp>
#include "AABB.h"

    // Forward declarations for ECS components (simplified)
struct TransformComponent { glm::vec3 position; };
struct CollisionComponent { LabPhysics::AABB aabb; };
struct Entity { int id; };

class PhysicsController
{
public:
    struct CollisionBody
    {
        Entity entity;
        TransformComponent* transform;
        CollisionComponent* collision;
    };


    void update(float deltaTime, std::vector<CollisionBody>& bodies)
    {
        // 1. Update AABB positions based on transforms
        for (auto& body : bodies)
            body.collision->aabb.UpdatePosition(body.transform->position);

        // 2. Broad phase + narrow phase
        detectCollisions(bodies);

        // 3. Resolve collisions
        resolveCollisions();
    }

private:
    // Spatial hash grid (unorded_map from hash key to vector of bodies)
    std::unordered_map<size_t, std::vector<CollisionBody*>> m_hashGrid;
    std::vector<std::pair<CollisionBody*, CollisionBody*>> m_currentCollisions;

    // Cell size – choose a value suitable for your world scale
    static constexpr float CELL_SIZE = 10.0f;


    // Hash function for a cell coordinate
    static size_t cellHash(int x, int y, int z)
    {
        // Large primes to mix coordinates
        return (x * 73856093) ^ (y * 19349663) ^ (z * 83492791);
    }


    // Convert world position to cell coordinate
    static glm::ivec3 worldToCell(const glm::vec3& worldPos)
    {
        return glm::ivec3(
            static_cast<int>(std::floor(worldPos.x / CELL_SIZE)),
            static_cast<int>(std::floor(worldPos.y / CELL_SIZE)),
            static_cast<int>(std::floor(worldPos.z / CELL_SIZE))
        );
    }


    // AABB overlap test (static, const‑correct)
    static bool aabbOverlap(const LabPhysics::AABB& a, const LabPhysics::AABB& b)
    {
        return (a.GetMin().x <= b.GetMax().x && a.GetMax().x >= b.GetMin().x) &&
               (a.GetMin().y <= b.GetMax().y && a.GetMax().y >= b.GetMin().y) &&
               (a.GetMin().z <= b.GetMax().z && a.GetMax().z >= b.GetMin().z);
    }


    void detectCollisions(std::vector<CollisionBody>& bodies)
    {
        m_hashGrid.clear();
        m_currentCollisions.clear();

        // Insert bodies into hash grid
        for (auto& body : bodies)
        {
            glm::ivec3 minCell = worldToCell(body.collision->aabb.GetMin());
            glm::ivec3 maxCell = worldToCell(body.collision->aabb.GetMax());

            for (int x = minCell.x; x <= maxCell.x; ++x)
                for (int y = minCell.y; y <= maxCell.y; ++y)
                    for (int z = minCell.z; z <= maxCell.z; ++z)
                        m_hashGrid[cellHash(x, y, z)].push_back(&body);
        }

        // Use a set to track already‑processed pairs (by entity ID)
        std::unordered_set<std::pair<int, int>, pair_hash> processedPairs;

        // Check collisions within each cell
        for (const auto& [hash, bucket] : m_hashGrid)
        {
            for (size_t i = 0; i < bucket.size(); ++i)
            {
                for (size_t j = i + 1; j < bucket.size(); ++j)
                {
                    CollisionBody* a = bucket[i];
                    CollisionBody* b = bucket[j];
                    int idA = a->entity.id;
                    int idB = b->entity.id;
                    if (idA > idB) std::swap(idA, idB); // canonical order

                    if (processedPairs.insert({idA, idB}).second) // new pair
                    {
                        if (aabbOverlap(*a->collision, *b->collision))
                        {
                            m_currentCollisions.emplace_back(a, b);
                        }
                    }
                }
            }
        }
    }


    void resolveCollisions()
    {
        for (const auto& pair : m_currentCollisions)
        {
            onCollision(pair.first, pair.second);
            onCollision(pair.second, pair.first);
        }
        m_currentCollisions.clear();
    }


    // Override this in a derived class or use a callback for game‑specific response
    virtual void onCollision(CollisionBody* a, CollisionBody* b)
    {
        // Default: do nothing
    }


    // Hash functor for std::pair<int,int>
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const
        {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ (h2 << 1);
        }
    };
};
