#pragma once
#include <list>
#include <glm/glm.hpp>
#include <vector>
#include "Framework/PhysicsObject.h"
#include "Framework/Body.h"
#include "Physics/Joint.h"

	class PhysicsSpace
	{
	public:
		~PhysicsSpace();

		void Step(float dt);
		void Draw(class dbf::Renderer* renderer);

		void AddBody(dbf::Body* body);
		void RemoveBody(dbf::Body* body);

		void AddPhysicsObject(dbf::PhysicsObject* body);
		void RemovePhysicsObject(dbf::PhysicsObject* body);
		
		void AddJoint(Joint* joint);
		void RemoveJoint(Joint* joint);

		std::vector<dbf::Body*> GetBodies();

		void AddForceGenerator(class ForceGenerator* forceGenerator);
	public:
		static glm::vec2 gravity;

	private:
		//std::vector<int> m_bodies;
	//std::vector<dbf::Body*> m_bodies;
	std::vector<dbf::PhysicsObject*> m_bodies;
	std::vector<dbf::Body*> bodies;
	std::list<class Joint*> m_joints;
		std::vector<ForceGenerator*> m_forceGenerators;
	};
