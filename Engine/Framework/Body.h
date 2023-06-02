#pragma once
#include <glm/glm.hpp>
#include "../Renderer/renderer.h"
#include "../Framework/Shape.h"
namespace dbf {
	class Body
	{
	public:
		enum Type
		{
			STATIC,
			KINEMATIC,
			DYNAMIC
		};

	public:
		Body(dbf::Shape* shape, const glm::vec2& position, const glm::vec2& velocity = { 0,0 }, float mass = 1, Type type = Type::DYNAMIC) :
			shape{ shape },
			position{ position },
			velocity{ velocity },
			mass{ mass },
			type{ type }
		{
			if (type == STATIC) mass = 0;
			invMass = (mass == 0) ? 0 : 1 / mass;
		}


		Body(const glm::vec2& position, const glm::vec2& velocity = { 0,0 }, float mass = 1, Type type = Type::DYNAMIC) :

			position{ position },
			velocity{ velocity },
			mass{ mass },
			type{ type }
		{
			if (type == STATIC) mass = 0;
			invMass = (mass == 0) ? 0 : 1 / mass;
		}

		void ApplyForce(const glm::vec2& force);
		void Step(float dt);
		void Draw(dbf::Renderer* renderer);
		bool Intersects(dbf::Body* body);

		void ClearForce() { force = glm::vec2{ 0,0 }; }

	public:
		dbf::Shape* shape{nullptr};

		Type type{ Type::DYNAMIC };

		glm::vec2 position{ 0,0 };
		glm::vec2 velocity{ 0,0 };
		glm::vec2 force{ 0,0 };
		float restitution{ 0.25f };

		float gravityScale{ 1 };
		float mass{ 1 };
		float invMass{ 1 };
		float damping{ 1 };
	};
}