#pragma once

#include <vector>
#include <memory>

#include "MaterialType.h"
class Color;

class Material
{
protected:
	void _setMapColor(const Color&);
	void _setNotSolid();
	void _setSuperHot();
	void _setFlammable();
	void _setReplaceable();
	void _setNeverBuildable();
	void _setNotBlockingMotion();
	void _setNotAlwaysDestroyable();
	
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
	static void addMaterial(std::unique_ptr<Material>);
	static void _setupSurfaceMaterials();
	static Material& getMaterial(MaterialType);
	
	static std::vector<std::unique_ptr<Material>> mMaterials;
	static bool mInitialized;
	
	bool operator==(const Material&) const;
	bool operator!=(const Material&) const;
};

