// Camera.cpp
#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : m_Location(position),
      m_WorldUp(up),
      m_Yaw(yaw),
      m_Pitch(pitch),
      m_Zoom(Zoom) // use default Zoom from options
{
    updateVectors();
}


void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
    {
        m_Location += m_Direction * velocity;
    }
    
    if (direction == BACKWARD)
    { 
        m_Location -= m_Direction * velocity;
    }
    
    if (direction == LEFT)
    {
        m_Location -= m_Right * velocity;
    }
    
    if (direction == RIGHT)
    {
        m_Location += m_Right * velocity;
    }
}


void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    m_Yaw   += xoffset;
    m_Pitch += yoffset;

    
    if (constrainPitch)
    {
        if (m_Pitch > 89.0f)
        {
            m_Pitch = 89.0f;
        }
        
        if (m_Pitch < -89.0f)
        {
            m_Pitch = -89.0f;
        }
    }
    updateVectors();
}


void Camera::ProcessMouseScroll(float yoffset)
{
    Zoom -= yoffset;
    if (Zoom < 1.0f)
    {
        Zoom = 1.0f;
    }

    if (Zoom > 45.0f) 
    {
        Zoom = 45.0f;
    }
}


void Camera::updateVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Direction = glm::normalize(front);

    m_Right = glm::normalize(glm::cross(m_Direction, m_WorldUp));
    m_Up    = glm::normalize(glm::cross(m_Right, m_Direction));
}
