#pragma once

#include "Vec2.h"

class BlockPos;
class Pos;

class Vec3
{
public:
    float x, y, z;

    Vec3() { x = y = z = 0.0 / 0.0; }
    Vec3(float x, float y, float z) : x(x), y(y), z(z) { }
    Vec3(BlockPos const&);
    Vec3(Pos const&);

    bool isNan() const;
    Vec2 xz() const;
    float minComponent() const;
    float maxComponent() const;
    std::string toString() const;
	void* toJsonString() const;

    static Vec3 clamp(const Vec3&, const Vec3&, const Vec3&);
    static Vec3 clampAlongNormal(const Vec3&, const Vec3&, const Vec3&, const Vec3&, Vec3&);

    static Vec3 directionFromRotation(const Vec2&);
    static Vec3 directionFromRotation(float, float);
    static Vec3 rotationFromDirection(const Vec3&);

    static Vec3 ZERO;
    static Vec3 ONE;
    static Vec3 UNIT_X;
    static Vec3 NEG_UNIT_X;
    static Vec3 UNIT_Y;
    static Vec3 NEG_UNIT_Y;
    static Vec3 UNIT_Z;
    static Vec3 NEG_UNIT_Z;
    static Vec3 MAX;
    static Vec3 MIN;

};

