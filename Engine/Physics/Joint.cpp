#include "Joint.h"
#include "../Framework/Body.h"
#include "../Renderer/renderer.h"


void Joint::Step(float dt)
{
	
}

void Joint::Draw(dbf::Renderer* graphics)
{
	graphics->DrawLine(m_bodyA->position, m_bodyB->position, glm::vec4{1});
}
