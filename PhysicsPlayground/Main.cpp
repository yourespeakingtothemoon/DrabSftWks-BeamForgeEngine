//#include "glm/glm.hpp"
#include "Engine.h"



int main(int argc, char* argv[])
{
	//Engine engine;
	//
	//dbf::g_renderer.Initialize();
	//dbf::g_inputSystem.initialize();
	//
	//
	//
	//dbf::g_renderer.BeginFrame();
	//for (int i = 0; i < 200; i++)
	//{
	//	dbf::g_renderer.DrawLine(glm::ivec2{ dbf::randomf(0, 800), dbf::randomf(0, 600) }, { dbf::randomf(0, 800), dbf::randomf(0, 600) },{dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),1});
	//}
	//
	bool quit = false;

// create window
dbf::g_renderer.CreateWindow("Physics ig", 800, 800, false);

dbf::g_renderer.SetClearColor(dbf::Color{ 0, 0, 0, 255 });
//FreeConsole();
// initialize systems
dbf::g_renderer.Initialize();
dbf::g_inputSystem.initialize();
while (!quit) {
	if (dbf::g_inputSystem.getButtonDown(dbf::key_escape))
	{
		quit = true;
	}
	else {
		dbf::g_renderer.BeginFrame();
		for (int i = 0; i < 200; i++)
		{
			dbf::g_renderer.DrawLine(glm::ivec2{ dbf::randomf(0, 800), dbf::randomf(0, 600) }, { dbf::randomf(0, 800), dbf::randomf(0, 600) }, { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),1 });
			dbf::g_renderer.DrawCircle(glm::ivec2{ dbf::randomf(0, 800), dbf::randomf(0, 600) }, dbf::randomf(0, 100), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),1 });
			dbf::g_renderer.DrawFilledCircle(glm::ivec2{ dbf::randomf(0, 800), dbf::randomf(0, 600) }, dbf::randomf(0, 100), { dbf::randomf(0,1),dbf::randomf(0,1),dbf::randomf(0,1),1 });
		}

		dbf::g_renderer.EndFrame();
	}
}

	return 0;
}