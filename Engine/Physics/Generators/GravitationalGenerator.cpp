#include "GravitationalGenerator.h"
#include "../../Framework/Body.h"

void GravitationalGenerator::Apply(std::vector<dbf::Body*> bodies)
{
	for (auto body : bodies)
	{
		body->ApplyForce({ 0, -m_strength });
	}
}
