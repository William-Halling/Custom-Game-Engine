#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace LabPhysics
{
	    class AABB
    {
    public:

        AABB(const glm::vec3& size = glm::vec3(1.0f));

        void UpdatePosition(const glm::vec3& position);

        const glm::vec3& GetMin() const;
        const glm::vec3& GetMax() const;

        void SetMin(const glm::vec3& min);
        void SetMax(const glm::vec3& max);

        glm::vec3 GetSize() const;
        glm::vec3 GetCenter() const;

    private:

        glm::vec3 min;
        glm::vec3 max;
    };
}
