#pragma once
#include "../Math/Vector2.h"
#include "../Math/Color.h"
#include "Primitives.h"
#include "glm/glm.hpp"

struct SDL_Renderer;
struct SDL_Window;
struct SDL_WindowEvent;
//struct SDL_DisplayMode;

namespace dbf
{
	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

		void Initialize();
		void Shutdown();

		void CreateWindow(const char* name, int width, int height, bool resize);
		//void HideFlags();

		void BeginFrame();
		void EndFrame();
		void SetClearColor(const Color& color) { m_clearColor = color; }

		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawLine(const Vector2& v1, const Vector2& v2, const Color& color);
		void DrawPoint(float x, float y);
		void DrawPoint(const Vector2& v, const Color& color);

		void DrawPoint(const glm::ivec2& point, const glm::vec4& color);

		void DrawLine(const glm::ivec2& start, const glm::ivec2& end, const glm::vec4& color);

		void DrawCircle(const glm::ivec2& point, int radius, const glm::vec4& color);

		void DrawFilledCircle(const glm::ivec2& point, int radius, const glm::vec4& color);



		static glm::ivec4 ConvertColor(const glm::vec4& color);

		int GetWidth() { return m_width; }
		int GetHeight() { return m_height; }
		SDL_Renderer* getRenderer();
		//bool getWindowClose();

	private:
		int m_width = 0;
		int m_height = 0;
		int m_screenh = 1080;
		int m_screenw = 1920;

		Color m_clearColor{ 0, 0, 0, 255 };

		SDL_Renderer* m_renderer = nullptr;
		SDL_Window* m_window = nullptr;
		//SDL_WindowEvent* close = nullptr;
		//SDL_DisplayMode* m_displaymode = nullptr;
	};
}
