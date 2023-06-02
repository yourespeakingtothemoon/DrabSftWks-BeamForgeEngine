#include "Integrator.h"
//
//
//	void Integrator::ExplicitEuler(dbf::Body& body, float dt)
//	{
//		body.position += body.velocity * dt;
//		body.velocity += (body.force * body.invMass) * dt;
//	}
//
//	void Integrator::SemiImplicitEuler(dbf::Body& body, float dt)
//	{
//		body.velocity += (body.force * body.invMass) * dt;
//		body.position += body.velocity * dt;
//	}
void Integrator::ExplicitEuler(dbf::Body& body, float dt)
{
	body.position += body.velocity * dt;
	body.velocity += (body.force * body.invMass) * dt;
}

void Integrator::SemiImplicitEuler(dbf::Body& body, float dt)
{
	body.velocity += (body.force * body.invMass) * dt;
	body.position += body.velocity * dt;
}

