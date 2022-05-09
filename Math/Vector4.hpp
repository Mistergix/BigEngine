#pragma once
#include <iostream>
#include "Vector3.hpp"

class  Vector4
{
public:
	float x, y, z, w;

	Vector4();

	Vector4(float x, float y, float z, float w);

	Vector4(const  Vector4& vector);

	Vector4(const  Vector3& vector);

	void cross(Vector4& v1, Vector4& v2, Vector4& v3);

	friend std::ostream& operator<<(std::ostream& os, const Vector4& v);


};