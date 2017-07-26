#pragma once

#include <vector>
#include <memory>

#include "MaterialType.h"
class Color;

class Material
{
private:
	void* _setupSurfaceMaterials();
	Material* _setMapColor(const Color&);
	Material* _setNotSolid();
	Material* _setSuperHot();
	Material* _setFlammable();
	Material* _setReplaceable();
	Material* _setNeverBuildable();
	Material* _setNotBlockingMotion();
	Material* _setNotAlwaysDestroyable();
	
public:
	MaterialType type; // 0
	bool flammable; // 4
	bool neverBuildable; // 5
	bool alwaysBreakable; // 6
	bool replaceable; // 7
	bool liquid; // 8
	float translucency; // 12
	bool blocksMotion; // 16
	bool solid; // 17
	bool superHot; // 18
	char filler; // 19
	Color* mapColor1; // 20
	Color* mapColor2; // 24
	Color* mapColor3; // 28
	Color* mapColor4; // 32
	
	enum class Settings;
	
	Material(MaterialType, Material::Settings, float);
	~Material();
	
	bool isType(MaterialType) const;
	bool isFlammable() const;
	bool isNeverBuildable() const;
	bool isAlwaysDestroyable() const;
	bool isReplaceable() const;
	bool isLiquid() const;
	float getTranslucency() const;
	bool getBlocksMotion() const;
	bool isSolid() const;
	bool isSolidBlocking() const;
	bool isSuperHot() const;
	unsigned int getColor() const;
	
	static void initMaterials();
	static void teardownMaterials();
	static void addMaterial(std::unique_ptr<Material, std::default_delete<Material>>);

	static Material& getMaterial(MaterialType);
	
	// static fields
	static std::vector<std::unique_ptr<Material>> mMaterials;
	static bool mInitialized;
	
	bool operator==(const Material&) const;
	bool operator!=(const Material&) const;
};

