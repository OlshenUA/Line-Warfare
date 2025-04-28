#pragma once
#include "KVector2.h"

class KMatrix2
{
public:
    static KMatrix2 zero;
    static KMatrix2 identity;
public:
    double  _11, _12;
    double  _21, _22;

public:
    KMatrix2(double e11 = 1.0, double e12 = 0.0, double e21 = 0.0, double e22 = 1.0)
    {
        _11 = e11;
        _12 = e12;
        _21 = e21;
        _22 = e22;
    }
    ~KMatrix2() {}
    void Set(double e11, double e12, double e21, double e22)
    {
        _11 = e11;
        _12 = e12;
        _21 = e21;
        _22 = e22;
    }
    void SetRotation(double angle)
    {
        double c = cos(angle);
        double s = sin(angle);
        _11 = c;
        _12 = -s;
        _21 = s;
        _22 = c;
    }
};

inline KVector2 operator*(const KVector2& v, const KMatrix2& m)
{
    KVector2 temp;
    temp.x = v.x*m._11 + v.y*m._21;
    temp.y = v.x*m._12 + v.y*m._22;
    return temp;
}

inline KVector2 operator*(const KMatrix2& m, const KVector2& v)
{
    KVector2 temp;
    temp.x = m._11*v.x + m._12*v.y;
    temp.y = m._21*v.x + m._22*v.y;
    return temp;
}

inline KMatrix2 operator*(double scalar, const KMatrix2& m)
{
    KMatrix2 temp;
    temp._11 = scalar*m._11;
    temp._12 = scalar*m._12;
    temp._21 = scalar*m._21;
    temp._22 = scalar*m._22;
    return temp;
}
