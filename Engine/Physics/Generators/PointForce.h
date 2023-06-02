#pragma once
#include "../../ForceGenerator.h"
#include "../../Framework/PhysicsObject.h"

class PointForce : public ForceGenerator
{
public:
	PointForce(dbf::Body* body, float forceMagnitude) :
		ForceGenerator{ body },
		m_forceMagitude{ forceMagnitude }
	{}

	virtual void Apply(std::vector<dbf::Body*> bodies) override;
protected:
	float m_forceMagitude{ 0 };
	
};