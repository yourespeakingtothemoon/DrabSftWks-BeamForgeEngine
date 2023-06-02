#pragma once
#include "GameObject.h"
#include "Body.h"


namespace dbf {
	class PhysicsObject: public GameObject
	{
	public:
	
		PhysicsObject(const Transform& transform) : GameObject{ transform } {}
		PhysicsObject(dbf::Body* body, dbf::Shape* shape) : m_body{ body }, m_shape{ shape } {
			m_body->shape = m_shape;
		}
		void Update();
	void Step(float timedelta);
	void Draw(class Renderer* renderer);
	//void OnCollision(PhysicsObject* other)

	void SetMass(float mass) { m_body->mass = mass; }

		dbf::Body* m_body = nullptr;
	private:
		// physics
		/*Vector2 m_velocity;
		float m_damping = 1;
		float m_mass = 1;
		float m_gravityScale = 1;*/
		class Shape* m_shape = nullptr;
	};
}