#pragma once
#include "../Shape.h"
#include "../Scene.h"
namespace dbf {
	class CircleShape : public Shape
	{
	public:
		CircleShape(float radius, const glm::vec4& color, bool fill = true) :
			Shape(color, radius),
			filled{ fill }
		{}

		void Draw(dbf::Renderer* renderer, const glm::vec2& position) override;

	public:
		//float radius{ 1 };
		bool filled = true;

	};
}