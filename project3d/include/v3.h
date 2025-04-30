#pragma once

class V3d
{
public:
    float x, y, z;
    V3d();
    V3d(float x, float y, float z);
    V3d operator+(float value);
    V3d operator-(float value);
    V3d operator*(float value);
    V3d operator/(float value);
    V3d& operator+=(float value);
    V3d& operator-=(float value);
    V3d& operator*=(float value);
    V3d& operator/=(float value);
    V3d operator+(const V3d& v);
    V3d operator-(const V3d& v);
    V3d operator*(const V3d& v);
    V3d operator/(const V3d& v);
    V3d& operator+=(const V3d& v);
    V3d& operator-=(const V3d& v);
    V3d& operator*=(const V3d& v);
    V3d& operator/=(const V3d& v);
    bool operator==(const V3d& v);
    V3d operator!();
    void norm();
    float length();
    void rotateVector(float alfa, float beta, float gamma);
    static float angleBetween(const V3d& v1, const V3d& v2, bool a360=false);
};