#include "renderer.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace dbf
{
	void Renderer::Initialize()
	{
		SDL_DisplayMode dm;
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();
		SDL_GetDesktopDisplayMode(0, &dm);
		m_screenh = dm.h;
		m_screenw = dm.w;

	}

	void Renderer::Shutdown()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		TTF_Quit();
	}

	void Renderer::CreateWindow(const char* name, int width, int height, bool resize)
	{
		m_width = width;
		m_height = height;
		if (!resize) {
			m_window = SDL_CreateWindow(name,400, 300, width, height, SDL_WINDOW_SHOWN );

		}
		else
		{
			m_window = SDL_CreateWindow(name, 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		}
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
		SDL_ShowCursor(SDL_DISABLE);
		
	}


	void Renderer::BeginFrame()
	{
		SDL_SetRenderDrawColor(m_renderer, m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
		SDL_RenderClear(m_renderer);
	}

	void Renderer::EndFrame()
	{
		SDL_RenderPresent(m_renderer);
	}

	void Renderer::DrawLine(float x1, float y1, float x2, float y2)
	{
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		SDL_RenderDrawLineF(m_renderer, x1, y1, x2, y2);
	}

	void Renderer::DrawLine(const Vector2& v1, const Vector2& v2, const Color& color)
	{
		SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawLineF(m_renderer, v1.x, v1.y, v2.x, v2.y);
	}

	void Renderer::DrawPoint(float x, float y)
	{
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		SDL_RenderDrawPointF(m_renderer, x, y);
	}

	void Renderer::DrawPoint(const Vector2& v, const Color& color)
	{
		SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawPointF(m_renderer, v.x, v.y);
	}
	void Renderer::DrawPoint(const glm::ivec2& point, const glm::vec4& color)
	{
		SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawPointF(m_renderer, point.x, point.y);
	}
	void Renderer::DrawLine(const glm::ivec2& start, const glm::ivec2& end, const glm::vec4& color)
	{
		SDL_RenderDrawLine(m_renderer, start.x, start.y, end.x, end.y);
	}
	void Renderer::DrawCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
	{
		glm::ivec4 icolor = ConvertColor(color);

		circleRGBA(m_renderer, point.x, point.y, radius, icolor.r, icolor.g, icolor.b, icolor.a);
	}
	void Renderer::DrawFilledCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
	{
		glm::ivec4 icolor = ConvertColor(color);

		filledCircleRGBA(m_renderer, point.x, point.y, radius, icolor.r, icolor.g, icolor.b, icolor.a);
	}
	glm::ivec4 Renderer::ConvertColor(const glm::vec4& color)
	{
		return glm::ivec4(color.x * 255, color.y * 255, color.z * 255, color.w * 255);
		//return glm::ivec4();
	}
	SDL_Renderer* Renderer::getRenderer()
	{
		return this->m_renderer;
	}
	

		//return m_window;
	
}
