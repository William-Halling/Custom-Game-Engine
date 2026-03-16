#pragma once
#include <glm/glm.hpp>
#include <memory>

class Shader;
class Mesh;


class Renderer
{
	public:
		virtual ~Renderer() = default;
		virtual void Init() = 0;
		virtual void Clear(const glm::vec4& color) = 0;
		virtual void SetViewport(int x, int y, int width, int height) = 0;
		virtual void DrawMesh(const Mesh& mesh, const Shader& shader) = 0;
};
