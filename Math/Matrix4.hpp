#pragma once
#include <iostream>
#include "Vector3.hpp"
#include "Vector4.hpp"


class Matrix4 {
public:
	float m_mat[4][4] = {};

	Matrix4();

	void setIdentity();
	void setTranslation(const  Vector3& translation);
	void setScale(const  Vector3& scale);
	void setRotationX(float x);
	void setRotationY(float y);
	void setRotationZ(float z);
	float getDeterminant();
	void inverse();
	void setMatrix(const  Matrix4& m_matrix);
	Vector3 getRightwardDirection();
	Vector3 getUpDirection();
	Vector3 getForwardDirection();
	Vector3 getTranslation();
	void setPerspectiveFovLH(float fov, float aspect, float znear, float zfar);
	void setOrthoLH(float width, float height, float near_plane, float far_plane);

	void operator *=(const  Matrix4& m_matrix);

	friend std::ostream& operator<<(std::ostream& os, const Matrix4& mat);
};