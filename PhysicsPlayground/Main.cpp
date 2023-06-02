//#include "glm/glm.hpp"
#include "Engine.h"
#include <iostream>
#include "Tests/ParticleTest.h"
#include "Tests/JointTest.h"

//#define POINT_FORCE
//#define AREA_FORCE
#define DRAG_FORCE






int main(int argc, char* argv[])
{
	// create window
	dbf::g_renderer.CreateWindow("Physics Playground", 800, 800, false);

	dbf::g_renderer.SetClearColor(dbf::Color{ 0, 0, 0, 255 });

	// initialize systems
	dbf::g_renderer.Initialize();
	dbf::g_inputSystem.initialize();

	PhysicsSpace* m_world = new PhysicsSpace();
	bool quit = false;
	while (!quit) {
		dbf::g_inputSystem.update();
		//std::cout << dbf::g_inputSystem.getKeyState(SDL_SCANCODE_W) << std::endl;
		//std::cout << "n0 ballz";
		if (dbf::g_inputSystem.getKeyState(dbf::key_escape) == dbf::inpSystem::keyState::Pressed)
		{
			quit = true;
		}
		else {
			if (dbf::g_inputSystem.getButtonDown(dbf::button_left))
			{
				//glm::vec2 velocity = { dbf::randomf(-50,50),dbf::randomf(-50,50) };
				glm::vec2 velocity = { 0,0 };
				auto po = new dbf::PhysicsObject(new dbf::Body({ dbf::g_inputSystem.getMousePosition().x, dbf::g_inputSystem.getMousePosition().y }, velocity), new dbf::CircleShape(randomf(20, 80), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),.7f }));
				m_world->AddPhysicsObject(po);
				//dbf::PhysicsObject po = new PhysicsObject(new Body(dbf::g_inputSystem.GetMousePosition(), velocity), new CircleShape <random radius>, { <random color> }));
				std::cout << "new ballz";

			}
			/*	auto po = new dbf::PhysicsObject(new dbf::Body({ dbf::g_inputSystem.getMousePosition().x, dbf::g_inputSystem.getMousePosition().y }, velocity), new dbf::CircleShape(randomf(50, 100), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),.7f }));
				m_world->AddPhysicsObject(po);*/

			dbf::g_time.gameTick();
			m_world->Step(dbf::g_time.deltaTime);
			dbf::g_renderer.BeginFrame();
			m_world->Draw(&dbf::g_renderer);
			dbf::g_renderer.EndFrame();
		}
	}
		return 0;
}
	
		
	
	// create window
//	dbf::g_renderer.CreateWindow("Physics ig", 800, 800, false);
//
//	dbf::g_renderer.SetClearColor(dbf::Color{ 0, 0, 0, 255 });
//
//	// initialize systems
//	dbf::g_renderer.Initialize();
//	dbf::g_inputSystem.initialize();
//	
//		PhysicsSpace* m_world = new PhysicsSpace();
//		//auto earth = new dbf::Body(new dbf::CircleShape(500, { 1,1,1,0.2f }), { 400,160 }, { 0,0 }, 0, dbf::Body::STATIC);
//		ForceGenerator* earth = new GravitationalGenerator(-981);
//		m_world->AddForceGenerator(earth);
//		
//		auto anchor = new dbf::PhysicsObject(new dbf::Body({ 400, 400 }, { 0, 0 }, 0, dbf::Body::KINEMATIC), new dbf::CircleShape(30, { 1,1,0,0.5f }));
//
//				dbf::Body* prev = anchor->m_body;
//		m_world->AddPhysicsObject(anchor);
//		for (int i = 0; i < 5; i++)
//		{
//			//auto body = new dbf::Body(new dbf::CircleShape(10, { 1,1,1,0.2f }), { 400, 400 }, { 0, 0 }, 0, dbf::Body::DYNAMIC);
//			auto a = new dbf::PhysicsObject(new dbf::Body({ randomf(0,800),randomf(0,800) }, {1, 1}, 0), new dbf::CircleShape(30, {1,0,1,0.5f}));
//			m_world->AddPhysicsObject(a);
//			auto joint = new Joint(prev, a->m_body, 200.0f,2.5f);
//			m_world->AddJoint(joint);
//			prev = a->m_body;
//			//m_world->AddPhysicsObject(body);
//		}
//		
//		bool quit = false;
//		while (!quit) {
//			dbf::g_inputSystem.update();
//		anchor->m_body->position = { dbf::g_inputSystem.getMousePosition().x, dbf::g_inputSystem.getMousePosition().y };
//			//std::cout << dbf::g_inputSystem.getKeyState(SDL_SCANCODE_W) << std::endl;
//			//std::cout << "n0 ballz";
//			if (dbf::g_inputSystem.getKeyState(dbf::key_escape) == dbf::inpSystem::keyState::Pressed)
//			{
//				quit = true;
//			}
//			else {
//				
//				if (dbf::g_inputSystem.getButtonDown(dbf::button_left))
//				{
//				}
//				
//
//				//straight line
//				
//			//						//glm::vec2 velocity = { dbf::randomf(-50,50),dbf::randomf(-50,50) };
//			//						glm::vec2 velocity = { 0,0 };
//			//						auto po = new dbf::PhysicsObject(new dbf::Body({ dbf::g_inputSystem.getMousePosition().x, dbf::g_inputSystem.getMousePosition().y }, velocity), new dbf::CircleShape(randomf(20, 80), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),.7f }));
//			//						
//			//						//m_world->AddPhysicsObject(po);
//			//						//dbf::PhysicsObject po = new PhysicsObject(new Body(dbf::g_inputSystem.GetMousePosition(), velocity), new CircleShape <random radius>, { <random color> }));
//			//						std::cout << "new ballz";
//			//	
//								
//			
//	/*		}
//			dbf::g_time.gameTick();
//			m_world->Step(dbf::g_time.deltaTime);
//			dbf::g_renderer.BeginFrame();
//			m_world->Draw(&dbf::g_renderer);
//			dbf::g_renderer.EndFrame();*/
//
//		//}
//
//	
//		
////		ForceGenerator* earth = new GravitationalGenerator(-981);
////		m_world->AddForceGenerator(earth);
////		
////		bool quit = false;
////#if defined(POINT_FORCE)
////		auto body = new dbf::Body(new dbf::CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, dbf::Body::STATIC)
////			;
////		ForceGenerator* forceGenerator = new PointForce(body, 2000);
////		m_world->AddForceGenerator(forceGenerator);
////#elif defined(AREA_FORCE)
////		auto body = new dbf::Body(new dbf::CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, dbf::Body::STATIC)
////			;
////		ForceGenerator* forceGenerator = new AreaForce(body, 2000, -90);
////		m_world->AddForceGenerator(forceGenerator);
////#elif defined(DRAG_FORCE)
////		auto body = new dbf::Body(new dbf::CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, dbf::Body::STATIC)
////			;
////		ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
////		m_world->AddForceGenerator(forceGenerator);
////#endif
////		while (!quit) {
////			dbf::g_inputSystem.update();
////			//std::cout << dbf::g_inputSystem.getKeyState(SDL_SCANCODE_W) << std::endl;
////			//std::cout << "n0 ballz";
////			if (dbf::g_inputSystem.getKeyState(dbf::key_escape) == dbf::inpSystem::keyState::Pressed)
////			{
////				quit = true;
////			}
////			else {
////				if (dbf::g_inputSystem.getButtonDown(dbf::button_left))
////				{
////					//glm::vec2 velocity = { dbf::randomf(-50,50),dbf::randomf(-50,50) };
////					glm::vec2 velocity = { 0,0 };
////					auto po = new dbf::PhysicsObject(new dbf::Body({ dbf::g_inputSystem.getMousePosition().x, dbf::g_inputSystem.getMousePosition().y }, velocity), new dbf::CircleShape(randomf(20, 80), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),.7f }));
////					m_world->AddPhysicsObject(po);
////					//dbf::PhysicsObject po = new PhysicsObject(new Body(dbf::g_inputSystem.GetMousePosition(), velocity), new CircleShape <random radius>, { <random color> }));
////					std::cout << "new ballz";
////
////				}
////				/*	auto po = new dbf::PhysicsObject(new dbf::Body({ dbf::g_inputSystem.getMousePosition().x, dbf::g_inputSystem.getMousePosition().y }, velocity), new dbf::CircleShape(randomf(50, 100), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),.7f }));
////					m_world->AddPhysicsObject(po);*/
//
//				dbf::g_time.gameTick();
//				m_world->Step(dbf::g_time.deltaTime);
//				dbf::g_renderer.BeginFrame();
//				m_world->Draw(&dbf::g_renderer);
//				dbf::g_renderer.EndFrame();
//			}
//		}



	



//	// create window
//dbf::g_renderer.CreateWindow("DB Beam Forge: Physics Playground Demo", 800, 800, false);
//
//dbf::g_renderer.SetClearColor(dbf::Color{ 0, 0, 0, 255 });
//
//// initialize systems
//dbf::g_renderer.Initialize();
//dbf::g_inputSystem.initialize();
//{
//PhysicsSpace* m_world = new PhysicsSpace();
//	bool quit = false;
//	while (!quit) {
//		dbf::g_inputSystem.update();
//		//std::cout << dbf::g_inputSystem.getKeyState(SDL_SCANCODE_W) << std::endl;
//		//std::cout << "n0 ballz";
//		if (dbf::g_inputSystem.getKeyState(dbf::key_escape) == dbf::inpSystem::keyState::Pressed)
//		{
//			quit = true;
//		}
//		else {
//			if (dbf::g_inputSystem.getButtonDown(dbf::button_left))
//			{
//				//glm::vec2 velocity = randomUnitCircle() * dbf::randomf(-50,50);
//				glm::vec2 velocity = glm::vec2(0, -9.81f);
//				dbf::PhysicsObject* po = new dbf::PhysicsObject(new dbf::Body({ dbf::g_inputSystem.getMousePosition().x, dbf::g_inputSystem.getMousePosition().y }, velocity), new dbf::CircleShape(randomf(5, 50), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),.7f }));
//				po->SetMass(dbf::randomf(-5, -10));
//				
//				m_world->AddPhysicsObject(po);
//				//dbf::PhysicsObject po = new PhysicsObject(new Body(dbf::g_inputSystem.GetMousePosition(), velocity), new CircleShape <random radius>, { <random color> }));
//				std::cout << "new ballz";
//
//			}
//
//			dbf::g_time.gameTick();
//			m_world->Step(dbf::g_time.deltaTime);
//			dbf::g_renderer.BeginFrame();
//			m_world->Draw(&dbf::g_renderer);
//			dbf::g_renderer.EndFrame();
//		}
//	}
//}
//
//	return 0;
//	dbf::g_renderer.DrawFilledCircle(glm::ivec2{ dbf::randomf(0, 800), dbf::randomf(0, 600) }, dbf::randomf(0, 100), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),1 });
//for (int i = 0; i < 200; i++)
//{
//	dbf::g_renderer.DrawLine(glm::ivec2{ dbf::randomf(0, 800), dbf::randomf(0, 600) }, { dbf::randomf(0, 800), dbf::randomf(0, 600) }, { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),1 });
//	dbf::g_renderer.DrawCircle(glm::ivec2{ dbf::randomf(0, 800), dbf::randomf(0, 600) }, dbf::randomf(0, 100), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),1 });
//	//Engine engine;
//	//
//	//dbf::g_renderer.Initialize();
//	//dbf::g_inputSystem.initialize();
//	//
//	//
//	//
//	//dbf::g_renderer.BeginFrame();
//	//for (int i = 0; i < 200; i++)
//	//{
//	//	dbf::g_renderer.DrawLine(glm::ivec2{ dbf::randomf(0, 800), dbf::randomf(0, 600) }, { dbf::randomf(0, 800), dbf::randomf(0, 600) },{dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),1});
//	//}
//	//
//
//	
//
//// create window
//dbf::g_renderer.CreateWindow("Physics ig", 800, 800, false);
//
//dbf::g_renderer.SetClearColor(dbf::Color{ 0, 0, 0, 255 });
//
//// initialize systems
//dbf::g_renderer.Initialize();
//dbf::g_inputSystem.initialize();
//{
//PhysicsSpace* m_world = new PhysicsSpace();
//	bool quit = false;
//	while (!quit) {
//		dbf::g_inputSystem.update();
//		//std::cout << dbf::g_inputSystem.getKeyState(SDL_SCANCODE_W) << std::endl;
//		//std::cout << "n0 ballz";
//		if (dbf::g_inputSystem.getKeyState(dbf::key_escape) == dbf::inpSystem::keyState::Pressed)
//		{
//			quit = true;
//		}
//		else {
//			if (dbf::g_inputSystem.getButtonDown(dbf::button_left))
//			{
//				glm::vec2 velocity = { dbf::randomf(-100,10),dbf::randomf(-100,10) };
//				auto po = new dbf::PhysicsObject(new dbf::Body({ dbf::g_inputSystem.getMousePosition().x, dbf::g_inputSystem.getMousePosition().y }, velocity), new dbf::CircleShape(randomf(50, 300), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),.7f }));
//				m_world->AddPhysicsObject(po);
//				//dbf::PhysicsObject po = new PhysicsObject(new Body(dbf::g_inputSystem.GetMousePosition(), velocity), new CircleShape <random radius>, { <random color> }));
//				std::cout << "new ballz";
//
//			}
//
//
//			m_world->Step(dbf::g_time.deltaTime);
//			dbf::g_renderer.BeginFrame();
//			m_world->Draw(&dbf::g_renderer);
//			dbf::g_renderer.EndFrame();
//		}
//	}
//}
//
//	return 0;
//	dbf::g_renderer.DrawFilledCircle(glm::ivec2{ dbf::randomf(0, 800), dbf::randomf(0, 600) }, dbf::randomf(0, 100), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),1 });
//}