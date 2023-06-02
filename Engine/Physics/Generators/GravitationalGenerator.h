#pragma once
#include "../../ForceGenerator.h"
#include "../../Framework/PhysicsObject.h"

class GravitationalGenerator : public ForceGenerator
{
public:
	GravitationalGenerator(float strength) : m_strength{ strength } {}

	virtual void Apply(std::vector<dbf::Body*> bodies) override;

private:
	float m_strength{ 0 };
};