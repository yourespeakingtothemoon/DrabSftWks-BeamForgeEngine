#include "PhysicsSpace.h"
#include "Physics/Integrator.h"
#include "ForceGenerator.h"
#include "Framework/Body.h"
#include "Renderer/renderer.h"
#include "Physics/Joint.h"
#include "Physics/Collision/Contact.h"
#include "Physics/Collision/Collision.h"

PhysicsSpace::~PhysicsSpace()
{
}

void PhysicsSpace::Step(float dt)
{
	auto b = GetBodies();
	std::vector<dbf::Body*> bodies(b.begin(), b.end());
	//std::vector<dbf::Body*> bods(bodies.begin(), bodies.end());
	if (!m_bodies.empty() && !m_forceGenerators.empty())
	{
		for (auto generator : m_forceGenerators)
		{
			generator->Apply(bodies);
			
			
		}
	}

	for (auto body : m_joints)
	{
		body->Step(dt);
	}
	//for (auto joint : m_joints)
	//{
	//	//dont ask the sequel
	//	glm::vec2 direction = joint->m_bodyA->position - joint->m_bodyB->position;
	//	//if (direction == glm::vec2{ 0, 0 }) return;

	//	float length = glm::length(direction);

	//	float x = length - joint->m_restLength;
	//	float f = -joint->m_springConstant * x;

	//	joint->m_bodyA->ApplyForce(glm::normalize(direction) * f);
	//	joint->m_bodyB->ApplyForce(-glm::normalize(direction) * f);
	//	//joint->Step(dt);
	//}

	for (auto body : m_bodies)
	{
		body->Step(dt);
	}
	
	// collisions
	std::vector<Contact> contacts;
	collision::CreateContacts(bodies, contacts);
	collision::SeparateContacts(contacts);


}

void PhysicsSpace::Draw(dbf::Renderer* renderer)
{
	for (auto& body : m_bodies)
	{
		body->Draw(renderer);
	}
	for (auto& body : bodies)
	{
		body->Draw(renderer);
	}
	for (auto& generator : m_forceGenerators)
	{
		generator->Draw(renderer);
	}
	for (auto body : m_joints)
	{
		body->Draw(renderer);
	}

}

void PhysicsSpace::AddPhysicsObject(dbf::PhysicsObject* body)
{
	m_bodies.push_back(body);
}

void PhysicsSpace::RemovePhysicsObject(dbf::PhysicsObject* body)
{
	
		auto iter = std::find(m_bodies.begin(), m_bodies.end(), body);
		if (iter != m_bodies.end())
		{
			m_bodies.erase(iter);
		}
}
void PhysicsSpace::AddJoint(Joint* joint){
m_joints.push_back(joint);
}

void PhysicsSpace::RemoveJoint(Joint* joint)
{
	m_joints.remove(joint);
}

std::vector<dbf::Body*> PhysicsSpace::GetBodies()
{
	std::vector<dbf::Body*> ret;
	
	for (auto body : m_bodies)
	{
		ret.push_back(body->m_body);
	}
	
	return ret;
}

void PhysicsSpace::AddBody(dbf::Body* body)
{
	bodies.push_back(body);
}

void PhysicsSpace::RemoveBody(dbf::Body* body)
{
	bodies.push_back(body);
}

void PhysicsSpace::AddForceGenerator(ForceGenerator* forceGenerator)
{
	m_forceGenerators.push_back(forceGenerator);
}

glm::vec2 PhysicsSpace::gravity = { 0,-9.81f };
