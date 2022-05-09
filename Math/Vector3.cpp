#include "Vector3.hpp"

Vector3::Vector3() {
	x = 0;
	x = 0;
	x = 0;
}


Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const  Vector3& vector) {
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
} 

Vector3 Vector3::lerp(const  Vector3& end, float delta)
{
	Vector3 v;
	v.x = x * (1.0f - delta) + end.x * (delta);
	v.y = y * (1.0f - delta) + end.y * (delta);
	v.z = z * (1.0f - delta) + end.z * (delta);
	return v;
}

float Vector3::length() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}

float Vector3::dot(Vector3 v) {
	float res = x * v.x + y * v.y + z * v.z;
	return res;
}

Vector3 Vector3::cross(Vector3 v) {

	Vector3 res = Vector3();
	res.x = y * v.z - z * v.y;
	res.y = z * v.x - x * v.z;
	res.z = x * v.y - y * v.x;
	return res;
}

	
Vector3 Vector3::normalize() {
	Vector3 res;
	float len = sqrt((x * x) + (y * y) + (z * z));
	if (!len)
		return Vector3();

	res.x = x / len;
	res.y = y / len;
	res.z = z / len;

	return res;
}


Vector3& Vector3::operator+(Vector3 v) {
	float x = this->x + v.x;
	float y = this->y + v.y;
	float z = this->z + v.z;
	Vector3 res(x,y,z);
	return res;
}

Vector3& Vector3::operator-(Vector3 v) {
	float x = this->x - v.x;
	float y = this->y - v.y;
	float z = this->z - v.z;
	Vector3 res(x, y, z);
	return res;
}
Vector3& Vector3::operator*(float f) {
	float x = this->x * f;
	float y = this->y * f;
	float z = this->z * f;
	Vector3 res(x, y, z);
	return res;

}

Vector3& Vector3::operator/(float f) {

	float x = this->x / f;
	float y = this->y / f;
	float z = this->z / f;
	Vector3 res(x, y, z);
	return res;
}

Vector3 Vector3::operator-() {
	return Vector3(-x, -y, -z);
	
}

Vector3 Vector3::operator=(Vector3 v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

bool Vector3::operator !=(Vector3 v) {
	return (x != v.x && y != v.y && z != v.z);
}

bool Vector3::operator ==(Vector3 v) {
	return (x == v.x && y == v.y && z == v.z);
}

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
	return os << "x: " << v.x << " y: " << v.y << " z: " << v.z;;
}
