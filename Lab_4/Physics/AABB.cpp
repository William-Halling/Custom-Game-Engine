// AABB.cpp
#include "AABB.h"

namespace LabPhysics
{
    AABB::AABB(const glm::vec3& size)
    {
        glm::vec3 half = size * 0.5f;
        min = -half;
        max = half;
    }

    void AABB::UpdatePosition(const glm::vec3& position)
    {
        glm::vec3 half = (max - min) * 0.5f;
        min = position - half;
        max = position + half;
    }


    const glm::vec3& AABB::GetMin() const 
    { 
        return min; 
    }
    const glm::vec3& AABB::GetMax() const 
    {
        return max; 
    }
    
    glm::vec3 AABB::GetSize() const 
    { 
        return max - min; 
    }

    glm::vec3 AABB::GetCenter() const 
    {
        return (min + max) * 0.5f; 
    }


    void AABB::SetMin(const glm::vec3& newMin) 
    {
        min = newMin; 
    }
    
    void AABB::SetMax(const glm::vec3& newMax) 
    {
        max = newMax; 
    }
}
