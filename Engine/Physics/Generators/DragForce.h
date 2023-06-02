#pragma once
#include "../../ForceGenerator.h"
#include "../../Framework/PhysicsObject.h"

class DragForce : public ForceGenerator
{
public:
	DragForce(dbf::Body* body,  float drag) :
		ForceGenerator{ body },
		m_drag{ drag }
		{}

	virtual void Apply(std::vector<dbf::Body*> bodies);

private:
	float m_drag{ 0 };

};