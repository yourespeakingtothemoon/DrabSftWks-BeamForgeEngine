#pragma once
//core
#include "Core/memMgmt.h"
#include "Core/File.h"
#include "Core/timeMgmt.h"
//maths
#include "Math/MathUtils.h"
#include "Math/Random.h"
//other
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

//physics stuff
#include "glm/glm.hpp"
#include "Renderer/Primitives.h"
#include "Core/Random.h"
//#include "Physics/PhysicsSystem.h"
#include "PhysicsSpace.h"
#include "Framework/Body.h"
#include "Framework/Shape.h"
#include "ForceGenerator.h"
#include "Physics/Integrator.h"
#include "Framework/PhysicsObject.h"
#include "Framework/Shapes/CircleShape.h"

#include "Physics/Generators/PointForce.h"
#include "Physics/Generators/DragForce.h"
#include "Physics/Generators/AreaForce.h"
#include "Physics/Generators/GravitationalGenerator.h"
#include "Physics/Joint.h"



namespace dbf
{
	extern Renderer g_renderer;
	extern inpSystem g_inputSystem;
	extern timeMgmt g_time;
	extern AudioSystem g_audio;
	//extern Random g_random;
}