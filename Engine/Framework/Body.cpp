#include "Body.h"
#include "../Physics/Integrator.h"
#include "Scene.h"
#include "Shape.h"
#include "../PhysicsSpace.h"
#include "../Physics/PhysicsData.h"
#include <iostream>

void dbf::Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void dbf::Body::Step(float dt)
{	
	if (type != DYNAMIC) return;

	//gravity
	//ApplyForce(dbf::gravity * gravityScale * mass);
	//std::cout << "hi";
	Integrator::SemiImplicitEuler(*this, dt);
	ClearForce();

	//damping
	velocity *= (1.0f / (1.0f + dt * damping));
}

void dbf::Body::Draw(dbf::Renderer* renderer)
{
	shape->Draw(renderer, position);
}

bool dbf::Body::Intersects(dbf::Body* body)
{
	glm::vec2 direction = position - body->position;
	float distance = glm::length(direction);
	//Shape* shape1 = shape;
	Shape* shape2 = body->shape;
	float radius = shape->GetRadius() + shape2->GetRadius();
	return distance <= radius;
}
