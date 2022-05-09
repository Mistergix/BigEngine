#include "Vector4.hpp"

Vector4::Vector4() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}
Vector4::Vector4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const  Vector4& vector) :x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}

Vector4::Vector4(const  Vector3& vector) :x(vector.x), y(vector.y), z(vector.z), w(1.0) {}

void Vector4::cross(Vector4& v1, Vector4& v2, Vector4& v3)
{
	this->x = v1.y * (v2.z * v3.w - v3.z * v2.w) - v1.z * (v2.y * v3.w - v3.y * v2.w) + v1.w * (v2.y * v3.z - v2.z * v3.y);
	this->y = -(v1.x * (v2.z * v3.w - v3.z * v2.w) - v1.z * (v2.x * v3.w - v3.x * v2.w) + v1.w * (v2.x * v3.z - v3.x * v2.z));
	this->z = v1.x * (v2.y * v3.w - v3.y * v2.w) - v1.y * (v2.x * v3.w - v3.x * v2.w) + v1.w * (v2.x * v3.y - v3.x * v2.y);
	this->w = -(v1.x * (v2.y * v3.z - v3.y * v2.z) - v1.y * (v2.x * v3.z - v3.x * v2.z) + v1.z * (v2.x * v3.y - v3.x * v2.y));
}

std::ostream& operator<<(std::ostream& os, const Vector4& v)
{
	return os << "x: " << v.x << " y: " << v.y << " z: " << v.z << "w: " << v.w;
}