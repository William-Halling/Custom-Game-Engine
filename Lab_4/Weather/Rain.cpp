// Rain.cpp
#include "Rain.h"
#include <random>
#include <glm/gtc/matrix_transform.hpp>


Rain::Rain(unsigned int maxRain)
{
    m_Raindrops.resize(maxRain);
    for (auto& drop : m_Raindrops)
    {
        ResetParticle(drop);
    }
    
    // Setup VAO/VBO for a simple line
    float vertices[] = {0.0f, 0.0f, 0.0f, 0.0f, -0.1f, 0.0f}; // small line downwards
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


Rain::~Rain()
{
    glDeleteVertexArrays(1, &m_VAO);
    
    glDeleteBuffers(1, &m_VBO);
}


void Rain::Update(float deltaTime, const glm::vec3& playerPos)
{
    if (!m_Active) 
    {
        return;
    }
    
    m_Timer -= deltaTime;
    
    if (m_Timer <= 0.0f)
    {
        m_Active = false;
        
        return;
    }

    
    float groundY = 0.0f; // TODO: get actual terrain height
    float viewRadius = 100.0f;

    for (auto& drop : m_Raindrops)
    {
        drop.Position += (m_Gravity + m_Wind) * deltaTime;
        drop.Lifetime -= deltaTime;

        if (IsOnGround(drop, groundY) || IsOutOfView(drop, playerPos, viewRadius))
        {
            ResetParticle(drop);
        }
    }
}


void Rain::Render(const glm::mat4& view, const glm::mat4& projection, Shader& shader)
{
    if (!m_Active)
    {
        return;
    }

    
    shader.use();
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    glBindVertexArray(m_VAO);
    
    
    for (const auto& drop : m_Raindrops)
    {
        glm::mat4 model = glm::translate(glm::mat4(1.0f), drop.Position);
        model = glm::scale(model, glm::vec3(drop.Size));
        shader.setMat4("model", model);
        glDrawArrays(GL_LINES, 0, 2);
    }
    glBindVertexArray(0);
}


void Rain::ResetParticle(Particle& p)
{
    p.Position = glm::vec3(RandomFloat(-50.0f, 50.0f), RandomFloat(10.0f, 30.0f), RandomFloat(-50.0f, 50.0f));
    p.Velocity = glm::vec3(0.0f, -2.0f, 0.0f); // simplified
    p.Lifetime = RandomFloat(2.0f, 5.0f);
    p.Size = RandomFloat(0.05f, 0.2f);
}


bool Rain::IsOnGround(const Particle& p, float groundY) const
{
    return p.Position.y <= groundY;
}


bool Rain::IsOutOfView(const Particle& p, const glm::vec3& playerPos, float radius) const
{
    return glm::distance(p.Position, playerPos) > radius;
}


float Rain::RandomFloat(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);

    
    return dis(gen);
}
