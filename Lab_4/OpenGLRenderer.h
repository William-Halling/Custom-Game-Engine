#pragma once
#include "Renderer.h"

class OpenGLRenderer : public Renderer
{
  public:
    void Init() override;
    void Clear(const glm::vec4& color) override;
    void SetViewport(int x, int y, int width, int height) override;
    void DrawMesh(const Mesh& mesh, const Shader& shader) override;
};
