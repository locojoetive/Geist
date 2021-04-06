#pragma once

#include <string>
#include <iostream>

struct Vector2D {
	float X;
	float Y;
	Vector2D() : X(0), Y(0) {};
	Vector2D(float x, float y) : X(x), Y(y) {};

	Vector2D& Add(const Vector2D&);
	Vector2D& Subtract(const Vector2D&);
	Vector2D& Multiply(const Vector2D&);
	Vector2D& Divide(const Vector2D&);

	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);


	Vector2D& operator+=(const Vector2D& v);
	Vector2D& operator-=(const Vector2D& v);
	Vector2D& operator*=(const Vector2D& v);
	Vector2D& operator/=(const Vector2D& v);

	friend std::ostream& operator <<(std::ostream& stream, const Vector2D& v);
};