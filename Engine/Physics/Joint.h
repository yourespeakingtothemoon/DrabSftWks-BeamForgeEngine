#pragma once
#include "../Framework/Body.h"
class Joint
{
public:
	Joint(dbf::Body* A, dbf::Body* B, float constant, float restLength) :
		m_bodyA{ A }, m_bodyB{ B }, m_springConstant{ constant }, m_restLength{ restLength }
	{
		if (!m_restLength) glm::distance(A->position, B->position);
	}


	void Step(float dt);
	void Draw(dbf::Renderer* graphics);
	dbf::Body* m_bodyA;
	dbf::Body* m_bodyB;

	float m_restLength{ 0 };
	float m_springConstant{ 0 };

};