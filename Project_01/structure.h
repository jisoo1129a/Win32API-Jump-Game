#pragma once
#include <math.h>
#include <assert.h>

class Vec2
{
public:
	float x;
	float y;

public:
	float Length()
	{
		return (float)sqrt(x * x + y * y);
	}
	Vec2 Nomalize()
	{
		float len = Length();
		if (len != 0.f)
		{
			x /= len;
			y /= len;
		}
		return *this;
	}

public:
	Vec2& operator = (POINT _pt)
	{

		x = (float)_pt.x;
		y = (float)_pt.y;
	}
	Vec2& operator += (Vec2 _vec)
	{
		x += _vec.x;
		y += _vec.y;

		return *this;
	}

	Vec2 operator/(Vec2 _vec)
	{
		if (_vec.x == 0 || _vec.y == 0)
			assert(nullptr);

		return Vec2(x / _vec.x, y / _vec.y);
	}

	Vec2 operator/ (float _f)
	{
		assert(_f != 0.f);

		return Vec2(x / _f, y / _f);
	}

	Vec2 operator*(Vec2 _vec)
	{
		return Vec2(x * _vec.x, y * _vec.y);
	}

	Vec2 operator* (float _f)
	{
		return Vec2(x * _f, y * _f);
	}

	Vec2 operator - (Vec2 _other)
	{
		return Vec2(x - _other.x, y - _other.y);
	}

	Vec2 operator + (Vec2 _other)
	{
		return Vec2(x + _other.x, y + _other.y);
	}

public:
	Vec2()
		:x(0.f)
		, y(0.f)
	{}
	Vec2(int _x, int _y)
		:x((float)_x)
		, y((float)_y)
	{}
	Vec2(float _x, float _y)
		:x(_x)
		, y(_y)
	{}
	Vec2(const POINT& _pt)
		:x((float)_pt.x)
		, y((float)_pt.y)
	{}
};