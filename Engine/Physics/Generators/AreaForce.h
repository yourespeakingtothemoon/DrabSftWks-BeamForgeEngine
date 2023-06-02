#pragma once
#include "../../ForceGenerator.h"
#include "../../Framework/PhysicsObject.h"

class AreaForce : public ForceGenerator
{
public:
	AreaForce(dbf::Body* body, float magnitude, float angle) :
		ForceGenerator(body),
		m_forceMagnitude{ magnitude },
		m_angle{ angle }
		{}

	virtual void Apply(std::vector<dbf::Body*> bodies) override;

private:
	float m_forceMagnitude{ 1 };
	float m_angle{ 0 };
};