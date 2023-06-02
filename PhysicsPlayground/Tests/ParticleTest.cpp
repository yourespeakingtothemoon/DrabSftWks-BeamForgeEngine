#include "ParticleTest.h"
#include <iostream>
#include "Engine.h"
#include "Framework/Body.h"
#include "Framework/Shapes/CircleShape.h"
#include "Framework/Shape.h"

void ParticleTest::Initialize()
{
	Test::Initialize();

}

void ParticleTest::Update()
{
	Test::Update();
	std::cout << "updat";
	//dbf::g_inputSystem.getButtonDown(dbf::button_left)
	if (m_input->getButtonDown(dbf::button_left))
	{
	std::cout << "click";
		glm::vec2 velocity = randomUnitCircle() * randomf(2, 3);
	//	auto shape = 
		auto body = new dbf::Body(new dbf::CircleShape(randomf(0.5f, 2), { randomf(0, 255), randomf(0, 255), randomf(0, 255),255 }), { m_input->getMousePosition().x,m_input->getMousePosition().y }, velocity);
		//std::string s = body->position.x;
		std::cout << std::to_string(body->position.x) << std::endl;
		body->damping = 1;
		//m_world->AddPhysicsObject(body);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Render()
{
	m_world->Draw(m_graphics);
}
