#include "PointForce.h"
#include "../../Framework/Body.h"


void PointForce::Apply(std::vector<dbf::Body*> bodies)
{
	for (auto body : bodies)
	{
		//if (!m_body->Intersects(body)) continue;
		//dont ask
		glm::vec2 direction = m_body->position - body->position;
		float distance = glm::length(direction);
		//Shape* shape1 = shape;
		//Shape* shape2 = body->shape;
		float radius = body->shape->GetRadius() + m_body->shape->GetRadius();

		if (radius >= distance) {


			glm::vec2 direction = body->position - m_body->position;
			glm::vec2 force = glm::normalize(direction);

			body->ApplyForce(force * m_forceMagitude);
		}
	}
}
