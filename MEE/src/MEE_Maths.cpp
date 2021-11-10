#include "MEE_Maths.h"

namespace MEE
{
	inline Vector2::Vector2() : x(0), y(0)
	{}

	inline Vector2::Vector2(float m_x, float m_y) : x(m_x), y(m_y)
	{}

	inline Vector2::Vector2(const Vector2 & vec) : x(vec.x), y(vec.y)
	{}

	inline Vector2 Vector2::Zero()
	{
		static Vector2 zero;
		return zero;
	}

	inline Vector2 Vector2::GetUnitVector(Vector2 vector)
	{
		float size = GetVectorSize(vector);
		Vector2 unit = Vector2(vector.x / size, vector.y / size);
		return unit;
	}

	inline float Vector2::GetVectorSize(Vector2 vector) {
		float nx = vector.x;
		float ny = vector.y;
		return (float)sqrt((nx * nx) + (ny * ny));
	}

	Vector2 Vector2::operator+(Vector2 v2)
	{
		Vector2 temp;
		temp.x = x + v2.x;
		temp.y = y + v2.y;
		return temp;
	}

	Vector2 Vector2::operator-(Vector2 v2)
	{
		Vector2 temp;
		temp.x = x - v2.x;
		temp.y = y - v2.y;
		return temp;
	}

	float Vector2::operator*(Vector2 v2)
	{
		float temp;
		temp = x * v2.x + y * v2.y;
		return temp;
	}

	Vector2 Vector2::operator*(float esc) {
		Vector2 temp;
		temp.x = (x * esc);
		temp.y = (y * esc);
		return temp;
	}

	Vector2 Vector2::operator/(float esc) {
		Vector2 temp;
		temp.x = (x / esc);
		temp.y = (y / esc);
		return temp;
	}
	inline Transform::Transform() : position(Vector2::Zero()), scale(Vector2(1, 1)),
		rotation(0) {}

	inline Transform::Transform(const Vector2& m_pos, const Vector2& m_scale, float m_rot)
		: position(m_pos),
		scale(m_scale),
		rotation(m_rot) {}
}
