#pragma once
#include "../Math/Matrix4.hpp"
#include "../Math/Vector3.hpp"


class  Entity
{
protected:
	Matrix4 m_world;

	Vector3 m_position;
	Vector3 m_rotation;
	Vector3 m_scale = Vector3(1, 1, 1);

	void processWorldMatrix();

public:


	Entity();
	virtual ~Entity();

	void getWorldMatrix(Matrix4& world);
	void setPosition(const  Vector3& position);
	void setRotation(const  Vector3& rotation);
	void setScale(const  Vector3& scale);

	Vector3 getPosition();
	Vector3 getRotation();
	Vector3 getScale();

	virtual void onCreate();
	virtual void onUpdate(float deltaTime);
	virtual void release();
};