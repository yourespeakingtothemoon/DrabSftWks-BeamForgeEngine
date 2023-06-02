#include "PhysicsObject.h"

#include "Shape.h"

void dbf::PhysicsObject::Update() {
	
}

void dbf::PhysicsObject::Step(float timedelta)
{
	m_body->Step(timedelta);
}

void dbf::PhysicsObject::Draw(Renderer* renderer)
{
	if (m_body) m_shape->Draw(renderer, m_body->position);
}
