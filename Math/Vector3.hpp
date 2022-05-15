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


    Vector3 operator- (const Vector3& rhs) const {
        return {x - rhs.x, y - rhs.y, z - rhs.z};
    }
    Vector3 operator+ (const Vector3& rhs) const {
        return {x + rhs.x, y + rhs.y, z + rhs.z};
    }
    Vector3 operator* (const float& rhs) const {
        return {x * rhs, y * rhs, z * rhs};
    }
    friend Vector3 operator* (const float& lhs, const Vector3& rhs) {
        return rhs * lhs;
    }
    Vector3 operator/ (const float& rhs) const {
        return {x / rhs, y / rhs, z / rhs};
    }

    Vector3& operator+= (const Vector3& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    Vector3& operator-= (const Vector3& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    Vector3& operator*= (const float& rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }
    Vector3& operator/= (const float& rhs) {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }

    Vector3& operator= (const Vector3& rhs)  {
        //Check for self-assignment
        if (this == &rhs)
            return *this;
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }
    Vector3 operator- () const { return {-x, -y, -z}; }

    bool operator!= (const Vector3& rhs) const {
        return (*this - rhs).length() >= 1.0e-6;
    }
    bool operator== (const Vector3& rhs) const {
        return (*this - rhs).length() < 1.0e-6;
    };

    friend std::ostream& operator<<(std::ostream& os, const Vector3& v);

};

