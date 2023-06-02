#pragma once
#include "../Framework/Body.h"

static class Integrator
{
public:
	static void ExplicitEuler(dbf::Body& body, float dt);
	static void SemiImplicitEuler(dbf::Body& body, float dt);
};


