#include "Matrix4.hpp"

Matrix4::Matrix4() {
	setIdentity();
}


void Matrix4::setIdentity() {
	m_mat[0][0] = 1;
	m_mat[1][1] = 1;
	m_mat[2][2] = 1;
	m_mat[3][3] = 1;
}

void Matrix4::setTranslation(const  Vector3& translation) {
	m_mat[3][0] = translation.x;
	m_mat[3][1] = translation.y;
	m_mat[3][2] = translation.z;
}

void Matrix4::setScale(const  Vector3& scale) {
	m_mat[0][0] = scale.x;
	m_mat[1][1] = scale.y;
	m_mat[2][2] = scale.z;
}

void Matrix4::setRotationX(float x) {
	m_mat[1][1] = cos(x);
	m_mat[1][2] = sin(x);
	m_mat[2][1] = -sin(x);
	m_mat[2][2] = cos(x);
}

void Matrix4::setRotationY(float y) {
	m_mat[0][0] = cos(y);
	m_mat[0][2] = -sin(y);
	m_mat[2][0] = sin(y);
	m_mat[2][2] = cos(y);
}

void Matrix4::setRotationZ(float z) {
	m_mat[0][0] = cos(z);
	m_mat[0][1] = sin(z);
	m_mat[1][0] = -sin(z);
	m_mat[1][1] = cos(z);
}

float Matrix4::getDeterminant() {
	Vector4 minor, v1, v2, v3;
	float det = 0.0f;

	v1 = Vector4(this->m_mat[0][0], this->m_mat[1][0], this->m_mat[2][0], this->m_mat[3][0]);
	v2 = Vector4(this->m_mat[0][1], this->m_mat[1][1], this->m_mat[2][1], this->m_mat[3][1]);
	v3 = Vector4(this->m_mat[0][2], this->m_mat[1][2], this->m_mat[2][2], this->m_mat[3][2]);


	minor.cross(v1, v2, v3);
	det = -(this->m_mat[0][3] * minor.x + this->m_mat[1][3] * minor.y + this->m_mat[2][3] * minor.z +
		this->m_mat[3][3] * minor.w);
	return det;
}

void Matrix4::inverse() {
	int a = 0, i = 0, j = 0;
	Matrix4 out = {};
	Vector4 v = {}, vec[3] = {};
	float det = 0.0f;

	det = this->getDeterminant();
	if (!det) return;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j != i)
			{
				a = j;
				if (j > i) a = a - 1;
				vec[a].x = (this->m_mat[j][0]);
				vec[a].y = (this->m_mat[j][1]);
				vec[a].z = (this->m_mat[j][2]);
				vec[a].w = (this->m_mat[j][3]);
			}
		}
		v.cross(vec[0], vec[1], vec[2]);

		out.m_mat[0][i] = pow(-1.0f, i) * v.x / det;
		out.m_mat[1][i] = pow(-1.0f, i) * v.y / det;
		out.m_mat[2][i] = pow(-1.0f, i) * v.z / det;
		out.m_mat[3][i] = pow(-1.0f, i) * v.w / det;
	}

	this->setMatrix(out);
}

void Matrix4::setMatrix(const  Matrix4& m_matrix) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m_mat[j][i] = m_matrix.m_mat[j][i];
		}
	}
}

Vector3 Matrix4::getRightwardDirection() {
	return Vector3(m_mat[0][0], m_mat[0][1], m_mat[0][2]);
}

Vector3 Matrix4::getUpDirection() {
	return Vector3(m_mat[1][0], m_mat[1][1], m_mat[1][2]);
}

Vector3 Matrix4::getForwardDirection() {
	return Vector3(m_mat[2][0], m_mat[2][1], m_mat[2][2]);
}

Vector3 Matrix4::getTranslation() {
	return Vector3(m_mat[3][0], m_mat[3][1], m_mat[3][2]);
}

void Matrix4::setPerspectiveFovLH(float fov, float aspect, float znear, float zfar) {
	float yscale = 1.0f / tan(fov / 2.0f);
	float xscale = yscale / aspect;
	m_mat[0][0] = xscale;
	m_mat[1][1] = yscale;
	m_mat[2][2] = zfar / (zfar - znear);
	m_mat[2][3] = 1.0f;
	m_mat[3][2] = (-znear * zfar) / (zfar - znear);
	m_mat[3][3] = 0.0f;
}

void Matrix4::setOrthoLH(float width, float height, float near_plane, float far_plane) {
	setIdentity();
	m_mat[0][0] = 2.0f / width;
	m_mat[1][1] = 2.0f / height;
	m_mat[2][2] = 1.0f / (far_plane - near_plane);
	m_mat[3][2] = -(near_plane / (far_plane - near_plane));
}


void Matrix4::operator *=(const  Matrix4& m_matrix) {
	Matrix4 out;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			out.m_mat[i][j] =
				m_mat[i][0] * m_matrix.m_mat[0][j] + m_mat[i][1] * m_matrix.m_mat[1][j] +
				m_mat[i][2] * m_matrix.m_mat[2][j] + m_mat[i][3] * m_matrix.m_mat[3][j];
		}
	}
	setMatrix(out);
}


std::ostream& operator<<(std::ostream& os, const Matrix4& mat)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			os << mat.m_mat[i][j] << " ";
		}
		os << std::endl;
	}

	return os;
}
