#pragma once
#include <glm/glm.hpp>

namespace dbf {
	class Shape
	{
	public:
		Shape() {}
		Shape(const glm::vec4& color, float radius) : color{ color }, radius{ radius } {}
		Shape(const glm::vec4& color) : radius{ radius } {}

		virtual void Draw(class Renderer* renderer, const glm::vec2& position) = 0;

		float GetRadius() { return radius; }
	public:
		float size{ 1 };
		float radius;
		glm::vec4 color{ 1,1,1,1 };
	};
}