#include "CircleShape.h"

void dbf::CircleShape::Draw(dbf::Renderer* renderer, const glm::vec2& position)
{
	if (filled) {
		renderer->DrawFilledCircle(position, radius, color);
	}
	else {
		renderer->DrawCircle(position, radius, color);
	}
}
