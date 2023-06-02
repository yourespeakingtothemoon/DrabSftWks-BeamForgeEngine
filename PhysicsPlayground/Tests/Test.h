#pragma once
#include "Engine.h"
#include "PhysicsSpace.h"

class Test
{
public:
	Test();
	~Test();

	virtual void Initialize();
	virtual void Run();

	virtual void Update();
	virtual void FixedUpdate() = 0;

	virtual void PreRender();
	virtual void Render() = 0;
	virtual void PostRender();

	bool IsQuit() { return m_quit; }

	bool m_quit{ false };
protected:
	void UpdateEvents();

protected:
	float m_fixedTime{ 0 };

	dbf::Renderer* m_graphics;
	dbf::inpSystem* m_input;
	dbf::timeMgmt* m_time;
	PhysicsSpace* m_world;
};
