#pragma once
#include <list>
#include <vector>
#include "Framework/Body.h"
#include "Framework/PhysicsObject.h"

class ForceGenerator
{
public:
	ForceGenerator() = default;
	ForceGenerator(dbf::Body* body) : m_body{ body } {}

	virtual void Apply(std::vector<dbf::Body*> bodies) = 0;
	virtual void Draw(dbf::Renderer* renderer);

	dbf::Body* m_body{ nullptr };
protected:
};