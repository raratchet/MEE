#pragma once
#include <cmath>
#include "MEE_Exports.h"

namespace MEE
{
	struct MEE_EXPORT Vector2
	{

		float x, y;

		Vector2();

		Vector2(float m_x, float m_y);

		Vector2(const Vector2& vec);

		static Vector2 Zero();

		Vector2 operator+(Vector2 v2);

		Vector2 operator-(Vector2 v2);

		Vector2 GetUnitVector(Vector2 vector);

		float GetVectorSize(Vector2 vector);

		float operator*(Vector2 v2);

		Vector2 operator*(float esc);

		Vector2 operator/(float esc);
	};


	struct MEE_EXPORT Transform
	{
		Transform();

		Transform(const Vector2& m_pos, const Vector2& m_scale, float m_rot);

		Vector2 position;
		Vector2 scale;
		float rotation;
	};

}

