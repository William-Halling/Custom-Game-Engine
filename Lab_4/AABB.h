#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace LabPhysics
{
	class AABB
	{
        public:

            glm::vec3 boxSize;


            glm::vec3 min;
            glm::vec3 max;


            // Constructor
            AABB(const glm::vec3& boxSize = glm::vec3(1.0f, 1.0f, 1.0f))
                : boxSize(boxSize), min(-boxSize * 0.5f), max(boxSize * 0.5f) {}

            void updateAABBPosition(glm::vec3 position)
            {
                min = position - boxSize * 0.5f;
                max = position + boxSize * 0.5f;
            }

        private:
	};

}
