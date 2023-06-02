#include "Gravitational.h"
#include "../../Framework/Body.h"

void GravitationalForce::Apply(std::list<dbf::PhysicsObject*> bodies)
{
	for (auto body : bodies)
	{
		body->m_body->ApplyForce({ 0, -m_strength });
	}
}
