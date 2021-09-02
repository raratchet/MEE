#pragma once
#include <cmath>

namespace MEE
{
	struct Vector2
	{

		float x, y;

		Vector2() : x(0), y(0)
		{}

		Vector2(float m_x, float m_y) : x(m_x), y(m_y)
		{}

		Vector2(const Vector2& vec) : x(vec.x), y(vec.y)
		{}

		static Vector2 Zero()
		{
			static Vector2 zero;
			return zero;
		}

		Vector2 operator+(Vector2 v2)
		{
			Vector2 temp;
			temp.x = x + v2.x;
			temp.y = y + v2.y;
			return temp;
		}

		Vector2 operator-(Vector2 v2)
		{
			Vector2 temp;
			temp.x = x - v2.x;
			temp.y = y - v2.y;
			return temp;
		}

		Vector2 GetUnitVector(Vector2 vector)
		{
			float size = GetVectorSize(vector);
			Vector2 unit = Vector2(vector.x / size, vector.y / size);
			return unit;
		}

		float GetVectorSize(Vector2 vector) {
			float nx = vector.x;
			float ny = vector.y;
			return (float)sqrt((nx * nx) + (ny * ny));
		}

		float operator*(Vector2 v2)
		{
			float temp;
			temp = x * v2.x + y * v2.y;
			return temp;
		}

		Vector2 operator*(float esc) {
			Vector2 temp;
			temp.x = (x * esc);
			temp.y = (y * esc);
			return temp;
		}

		Vector2 operator/(float esc) {
			Vector2 temp;
			temp.x = (x / esc);
			temp.y = (y / esc);
			return temp;
		}
	};
}

