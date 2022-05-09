#pragma once
#include <iostream>
#include <math.h>

class Vector3 {
public:

    float x;
    float y;
    float z;

    Vector3();
    Vector3(float x,float y, float z);
    Vector3(const  Vector3& vector);

    Vector3 lerp(const  Vector3& end, float delta);

    float length() const;

    Vector3 normalize();

    float dot(Vector3);
    Vector3 cross(Vector3 v);


    Vector3& operator+(Vector3);
    Vector3& operator-(Vector3);
    Vector3& operator*(float);
    Vector3& operator/(float);

    Vector3 operator=(Vector3);
    Vector3 operator-();

    bool operator !=(Vector3);
    bool operator ==(Vector3);

    friend std::ostream& operator<<(std::ostream& os, const Vector3& v);

};

