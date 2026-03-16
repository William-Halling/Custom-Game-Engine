// Camera.h
#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement { FORWARD, BACKWARD, LEFT, RIGHT };

class Camera
{
public:
    // Constructor with default values
    Camera(glm::vec3 position = glm::vec3(0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f);


    // Getters
    const glm::vec3& GetLocation() const { return m_Location; }
    glm::vec3 GetDirection() const       { return m_Direction; }
    glm::vec3 GetRight() const           { return m_Right; }
    glm::vec3 GetUp() const              { return m_Up; }
    float GetPitch() const               { return m_Pitch; }
    float GetYaw() const                 { return m_Yaw; }
    float GetZoom() const                { return m_Zoom; }


    // Setters
    void SetLocation(const glm::vec3& loc) { m_Location = loc; }
    void SetPitch(float pitch)             { m_Pitch = pitch; updateVectors(); }
    void SetYaw(float yaw)                 { m_Yaw = yaw; updateVectors(); }
    void SetZoom(float zoom)               { m_Zoom = zoom; }


    // View matrix
    glm::mat4 GetViewMatrix() const { return glm::lookAt(m_Location, m_Location + m_Direction, m_Up); }


    // Process input
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
    void ProcessMouseScroll(float yoffset);


    // Options
    float MovementSpeed = 2.5f;
    float MouseSensitivity = 0.1f;
    float Zoom = 45.0f;


private:
    glm::vec3 m_Location;
    glm::vec3 m_Direction;
    glm::vec3 m_Up;
    glm::vec3 m_Right;
    glm::vec3 m_WorldUp;

    float m_Yaw;
    float m_Pitch;
    float m_Zoom;   // not used yet, but for FOV

    void updateVectors();
};
