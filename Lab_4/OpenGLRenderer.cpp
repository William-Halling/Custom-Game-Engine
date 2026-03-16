// OpenGLRenderer.cpp
#include "OpenGLRenderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void OpenGLRenderer::Init()
{
    glEnable(GL_DEPTH_TEST);
}


void OpenGLRenderer::Clear(const glm::vec4& color)
{
  glClearColor(color.r, color.g, color.b, color.a);
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void OpenGLRenderer::SetViewport(int x, int y, int width, int height)
{
  glViewport(x, y, width, height);
}


void OpenGLRenderer::DrawMesh(const Mesh& mesh, const Shader& shader)
{
    
}
