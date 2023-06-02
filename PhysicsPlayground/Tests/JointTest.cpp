#include "JointTest.h"
#include "Engine.h"
#include <vector>

#define SPRING_CONSTANT 200
#define SPRING_LENGTH 2.5
#define BODY_DAMPING 10
//#define CHAIN_SIZE 6
#define GRID_WIDTH 2
#define GRID_HEIGHT 4

void JointTest::Initialize()
{
	Test::Initialize();

	auto anchor = new dbf::Body(new dbf::CircleShape(0.7, { 1, 1, 0, .5f }), { 0, 0 }, { 0, 0 }, 0, dbf::Body::KINEMATIC);
	m_world->AddBody(anchor);

	auto prevBody = anchor;

#if defined (CHAIN_SIZE)
	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		auto body = new Body(new CircleShape(0.5, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::DYNAMIC);
		body->m_damping = BODY_DAMPING;
		m_world->AddBody(body);

		auto joint = new Joint(prevBody, body, SPRING_CONSTANT, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;
	}
#elif defined(GRID_WIDTH)
	std::vector<dbf::Body*> prevBodies;
	prevBodies.push_back(anchor);

	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		std::vector<dbf::Body*> bodies;
		for (int j = 0; j < GRID_WIDTH; j++)
		{
			auto body = new dbf::Body(new dbf::CircleShape(0.5, { 1, 1, 1, 1 }), { prevBody->position.x + j, prevBody->position.y + i }, { 0, 0 }, 1, dbf::Body::DYNAMIC);
			body->damping = BODY_DAMPING;
			m_world->AddBody(body);
			bodies.push_back(body);
		}
		for (int j = 0; j < prevBodies.size(); j++)
		{
			for (int k = 0; k < bodies.size(); k++)
			{
				auto joint = new Joint(prevBodies[j], bodies[k], SPRING_CONSTANT, SPRING_LENGTH);
				m_world->AddJoint(joint);
			}
		}
		for (int k = 0; k < bodies.size() - 1; k++)
		{
			auto joint = new Joint(bodies[k], bodies[k + 1], SPRING_CONSTANT, SPRING_LENGTH);
			m_world->AddJoint(joint);
		}
		prevBodies = bodies;
	}
#endif
}

void JointTest::Update()
{
	Test::Update();
	anchor->position = {m_input->getMousePosition().x, m_input->getMousePosition().y};
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	//m_graphics->DrawCircle({ m_input->getMousePosition().x, m_input->getMousePosition().y }, 10, { randomf(), randomf(), randomf(), 1 });
}

