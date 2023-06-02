#include "Test.h"


Test::Test()
{
	//
}

Test::~Test()
{
	if (m_time) delete m_time;
	if (m_input) delete m_input;
	if (m_graphics) delete m_graphics;
	if (m_world) delete m_world;
}

void Test::Initialize()
{
	m_graphics = new dbf::Renderer();
	m_input = new dbf::inpSystem();
	m_graphics->CreateWindow("Beam Forge Test: PhysicsPlayground", 800, 600, false);
	m_graphics->SetClearColor({ 0, 0, 0, 1 });
	m_graphics->Initialize();
	m_input->initialize();
	m_time = new dbf::timeMgmt();
	m_time->SetFixedDeltaTime(1 / 60.0f);
	m_world = new PhysicsSpace();
}

void Test::Run()
{
	Update();
	//m_fixedTime += m_time->TimeDelta();
	FixedUpdate();

	// render
	m_world->Step(m_time->TimeDelta());
	PreRender();
	Render();
	PostRender();
	//m_world->Step(dbf::g_time.deltaTime);
	//			dbf::g_renderer.BeginFrame();
	//			m_world->Draw(&dbf::g_renderer);
	//			dbf::g_renderer.EndFrame();*/
}

void Test::Update()
{
	m_input->update();
	m_time->gameTick();
	UpdateEvents();

}


void Test::PreRender()
{
	//m_graphics->SetRenderColor({ 0, 0, 0, 0 });
	m_graphics->BeginFrame();
}


void Test::PostRender()
{
	m_graphics->EndFrame();
}

void Test::UpdateEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_quit = true;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			m_quit = true;
		}
	}
}
