#include "DragForce.h"
#include "../../Framework/Body.h"
#include <glm/gtx/norm.hpp>

void DragForce::Apply(std::vector<dbf::Body*> bodies)
{
	for (auto body : bodies)
	{
		//dont ask
		glm::vec2 direction = m_body->position - body->position;
		float distance = glm::length(direction);
		//Shape* shape1 = shape;
		//Shape* shape2 = body->shape;
		float radius = body->shape->GetRadius() + m_body->shape->GetRadius();

		if (radius >= distance) {

			if (body->velocity == glm::vec2{ 0, 0 }) continue;

			float f = 0.5f * glm::length2(body->velocity) * m_drag;
			glm::vec2 force = glm::normalize(body->velocity);

			body->ApplyForce(force * -f);
		}
	}
}
