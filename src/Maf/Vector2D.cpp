#include "Vector2D.h"

Vector2D& Vector2D::Add(const Vector2D& v)
{
	this->X += v.X;
	this->Y += v.Y;

	return *this;

}

Vector2D& Vector2D::Subtract(const Vector2D& v)
{
	this->X -= v.X;
	this->Y -= v.Y;

	return *this;

}

Vector2D& Vector2D::Multiply(const Vector2D& v)
{
	this->X *= v.X;
	this->Y *= v.Y;

	return *this;

}

Vector2D& Vector2D::Divide(const Vector2D& v)
{
	this->X /= v.X;
	this->Y /= v.Y;

	return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
	return v1.Add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
	return v1.Subtract(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
	return v1.Multiply (v2);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
	return v1.Divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
	return this->Add(v);
}

Vector2D& Vector2D::operator-=(const Vector2D& v)
{
	return this->Subtract(v);
}

Vector2D& Vector2D::operator*=(const Vector2D& v)
{
	return this->Multiply(v);
}

Vector2D& Vector2D::operator/=(const Vector2D& v)
{
	return this->Divide(v);
}

Vector2D& Vector2D::operator*(const int& i)
{
	this->X *= i;
	this->Y *= i;

	return *this;
}

Vector2D& Vector2D::Zero()
{
	this->X *= 0;
	this->Y *= 0;

	return *this;
}

std::ostream& operator <<(std::ostream& stream, const Vector2D& v)
{
	stream << "Vector(" << v.X << ", " << v.Y << ")";
	return stream;
}