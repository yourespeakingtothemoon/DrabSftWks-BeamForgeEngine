#include "AreaForce.h"
#include "../../Framework/Body.h"
#include <glm/gtx/quaternion.hpp>


void AreaForce::Apply(std::vector<dbf::Body*> bodies)
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

			glm::quat q = glm::angleAxis(glm::radians(m_angle), glm::vec3{ 0, 0, 1 });
			glm::vec2 force = q * glm::vec3{ 1, 0, 0 };

			body->ApplyForce(force * m_forceMagnitude);
		}
		
	}
}
