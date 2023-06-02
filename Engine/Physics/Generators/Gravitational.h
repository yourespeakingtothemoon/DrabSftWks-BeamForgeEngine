#pragma once
#include "../../ForceGenerator.h"
#include "../../Framework/PhysicsObject.h"

class GravitationalForce : public ForceGenerator
{
public:
	GravitationalForce(float strength) : m_strength{ strength } {}
	void Apply(std::list<dbf::PhysicsObject*> bodies);
private:
	float m_strength{ 0 };
};