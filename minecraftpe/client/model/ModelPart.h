#pragma once

#include <vector>
#include <string>
class Model;
class Matrix;
class TextureOffset;
class Vec3;
class AABB;

// Size : 160
class ModelPart {
public:
	float rotationPointX;	// 0
	float rotationPointY;	// 4
	float rotationPointZ;	// 8
	float rotateAngleX;		// 12
	float rotateAngleY;		// 16
	float rotateAngleZ;		// 20
	bool mirror;			// 24
	bool idk;				// 25
	float offsetX;			// 28
	float offsetY;			// 32
	float offsetZ;			// 36
	std::vector<ModelPart*> childModels;	// 40
	char filler[8]; 		// 44
	int textureWidth;		// 52
	int textureHeight;		// 56
	char filler1[4];		// 60
	int textureOffsetX;		// 64
	int textureOffsetY;		// 68
	bool isHidden;			// 72
	char filler2[84];		// 76

	ModelPart(ModelPart&&);
	ModelPart(int, int, int, int);
	~ModelPart();
	void addBox(const Vec3&, const Vec3&, float);
	void addBoxMapTex(const Vec3&, const Vec3&, const TextureOffset&, float);
	void addChild(ModelPart*);
	void compile(float);
	void draw(const Model&, float);
	void expandAABB(AABB&);
	void load(const GeometryPtr&, const std::string&);
	void mimic(const ModelPart&);
	void operator=(ModelPart&&);
	void render(const Model&, float);
	void reset();
	void setNeverRender(bool);
	void setPos(const Vec3&);
	void setTexSize(int, int);
	void texOffs(int, int);
	void translateTo(Matrix&, float);
};
