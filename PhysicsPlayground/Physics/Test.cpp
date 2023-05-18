#include "Test.h"
#include "Graphics.h"
#include "Input.h"
#include "Time.h"
#include "Random.h"

Test::Test()
{
	//
}

Test::~Test()
{
	if (m_time) delete m_time;
	if (m_input) delete m_input;
	if (m_graphics) delete m_graphics;
}

void Test::Initialize()
{
	m_graphics = new Graphics();
	m_graphics->CreateWindow("Physics", 800, 600);
	m_input = new Input();
	m_time = new Time();
}

void Test::Run()
{
	UpdateEvents();

	m_input->Update();
	m_time->Update();

	m_graphics->SetColor({ 0, 0, 0, 0 });
	m_graphics->Clear();
	
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, {randomf(), randomf(), randomf(), 1});
	
	m_graphics->Present();
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
