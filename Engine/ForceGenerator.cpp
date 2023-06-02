#include "ForceGenerator.h"
#include "Framework/Body.h"

void ForceGenerator::Draw(dbf::Renderer* renderer)
{
	if (m_body) m_body->Draw(renderer);
}
