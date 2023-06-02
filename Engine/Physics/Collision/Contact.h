#pragma once
#include <glm/glm.hpp>
#include "../../Framework/Body.h"

struct Contact
{
	dbf::Body* bodyA{ nullptr };
	dbf::Body* bodyB{ nullptr };

	float restitution{ 0 };
	float depth{ 0 };
	glm::vec2 normal{ 0, 0 };
};