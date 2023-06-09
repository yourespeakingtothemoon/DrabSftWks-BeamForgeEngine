#pragma once
#include "../Math/Transform.h"

namespace dbf
{
	class GameObject
	{
	public:
		GameObject() = default;
		GameObject(const Transform& transform) : m_transform{ transform } {}

		virtual void Update() = 0;
		
		Transform m_transform;
	protected:
	};
}
