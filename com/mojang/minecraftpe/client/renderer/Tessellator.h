#pragma once

#include "../MemoryTracker.h"

class Color;
class Vec2;
class Vec3;

namespace mce {
	class MaterialPtr;
	class TexturePtr;
}

class Tessellator : public MemoryTracker {
public:
	static Tessellator instance;

public:
	Tessellator(MemoryTracker *);
	virtual ~Tessellator();
	virtual void getStats() const;
	void _allocateIndices(int);
	void _tex(const Vec2 &, int);
	void addOffset(const Vec3 &);
	void addOffset(float, float, float);
	void begin(int);
	void beginIndices(int);
	void color(const Color &);
	void color(float, float, float, float);
	void color(int);
	void color(int, int);
	void color(int, int, int, int);
	void color(unsigned char, unsigned char, unsigned char, unsigned char);
	void colorABGR(int);
	void draw(const mce::MaterialPtr&);
	void draw(const mce::MaterialPtr&, const mce::TexturePtr&);
	void draw(const mce::MaterialPtr&, const mce::TexturePtr&, const mce::TexturePtr&);
	void enableColor();
	void end(const char *, bool);
	void getColor();
	void getPolygonCount() const;
	void init();
	void noColor();
	void normal(const Vec3 &);
	void normal(float, float, float);
	void quad(unsigned int, bool);
	void quad(unsigned int, unsigned int, unsigned int, unsigned int);
	void resetScale();
	void resetTilt();
	void rotationOffset(float, const Vec3 &);
	void scale2d(float, float);
	void scale3d(float, float, float);
	void setOffset(const Vec3 &);
	void setOffset(float, float, float);
	void tex(const Vec2 &);
	void tex(float, float);
	void tex1(const Vec2 &);
	void tex1(float, float);
	void tex2(const Vec2 &);
	void tex2(float, float);
	void tilt();
	void triangle(unsigned int, unsigned int, unsigned int);
	void trim();
	void vertex(const Vec3 &);
	void vertexUV(const Vec3 &, float, float);
	void vertexUV(float, float, float, float, float);
	void voidBeginAndEndCalls(bool);
};
