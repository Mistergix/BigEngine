#include "Entity.hpp"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::processWorldMatrix()
{
	Matrix4 temp;

	m_world.setIdentity();

	temp.setIdentity();
	temp.setScale(m_scale);
	m_world *= temp;


	temp.setIdentity();
	temp.setRotationX(m_rotation.x);
	m_world *= temp;

	temp.setIdentity();
	temp.setRotationY(m_rotation.y);
	m_world *= temp;

	temp.setIdentity();
	temp.setRotationZ(m_rotation.z);
	m_world *= temp;


	temp.setIdentity();
	temp.setTranslation(m_position);
	m_world *= temp;
}

void Entity::getWorldMatrix(Matrix4& world)
{
	world = m_world;
}

void Entity::setPosition(const  Vector3& position)
{
	m_position = position;
	processWorldMatrix();
}

void Entity::setRotation(const  Vector3& rotation)
{
	m_rotation = rotation;
	processWorldMatrix();
}

void Entity::setScale(const  Vector3& scale)
{
	m_scale = scale;
	processWorldMatrix();
}

Vector3 Entity::getPosition()
{
	return m_position;
}

Vector3 Entity::getRotation()
{
	return m_rotation;
}

Vector3 Entity::getScale()
{
	return m_scale;
}

void Entity::onCreate(){}
void Entity::onUpdate(float deltaTime){}
void Entity::release() {}