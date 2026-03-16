// Rain.h
#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include "Shader.h"
#include "Particle.h"

class Rain
{
    public:
        Rain(unsigned int maxRain);
        ~Rain();
    
        void Update(float deltaTime, const glm::vec3& playerPos);
        void Render(const glm::mat4& view, const glm::mat4& projection, Shader& shader);
    
        void StartRain() { m_Active = true; m_Timer = m_Duration; }
        void StopRain() { m_Active = false; }
    
    private:
        void ResetParticle(Particle& p);
        bool IsOnGround(const Particle& p, float groundY) const;
        bool IsOutOfView(const Particle& p, const glm::vec3& playerPos, float radius) const;
        float RandomFloat(float min, float max);
    
        std::vector<Particle> m_Raindrops;
        float m_Timer = 0.0f;
        float m_Duration = 240.0f;
        bool m_Active = false;
    
        GLuint m_VAO = 0, m_VBO = 0;
        glm::vec3 m_Gravity{0.0f, -9.8f, 0.0f};
        glm::vec3 m_Wind{0.0f};
};
