#pragma once

#include <string>
#include <vector>

#include "../client/renderer/ResourceLocation.h"

class SkinPack;

// Size : 40
// 0.15.6
class Skin {
public:
	enum SkinType {
		DEFAULT, FREE, PAID
	};

	SkinPack* pack; // 0
	int packIndex; // 4
	int skinIndex; // 8
	std::string serializable; // 12
	std::string name; // 16
	std::string geometryName; // 20
	ResourceLocation path; // 24
	SkinType type; // 32
	float guiScale; // 36

	Skin(const std::string&, const std::string&, const std::string&, const ResourceLocation&, Skin::SkinType, float);
	Skin(const std::string&, const std::string&, const std::string&, const std::string&, Skin::SkinType, float);

	SkinPack* getSkinPack() const;
	void setSkinPack(SkinPack*);
	
	void setPackIndex(int);
	void setSkinIndex(int);

	const std::string& getSerializable() const;
	const std::string& getName() const;
	const std::string& getGeometryName() const;
	const ResourceLocation& getSkinLocation() const;
	float getGuiScale() const;

	bool premiumLocked() const;
	bool isCustomSkin() const;
	bool isPremium() const;

	bool operator==(const Skin&) const;
};
