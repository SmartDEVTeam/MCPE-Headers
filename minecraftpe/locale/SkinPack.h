#pragma once

#include <string>
#include <vector>

#include "../client/renderer/ResourceLocation.h"

class Offer;

// Size : 40
// 0.15.6
class SkinPack {
public:
	enum SkinPackType {
		DEFAULT, PACK
	};

	Offer* offer; // 0
	SkinPackType type; // 4
	int packIndex; // 8
	std::string serializableName; // 12
	std::string name; // 16
	ResourceLocation location; // 20
	std::vector<Skin> skins; // 28

	SkinPack(Offer*, SkinPackType, const std::string&, const std::string&, const ResourceLocation&, int, const std::initializer_list<Skin>&);

	const std::string& getSerializableName() const;
	const ResourceLocation& getLocationForKeyArt() const;

	const std::string& getPrice() const;
	Offer* getOffer() const;
	int getPackIndex() const;
	
	bool isPremiumUnlocked() const;

	const std::string& getName() const;
	const std::vector<Skin>& getSkins() const;
	SkinPackType getSkinPackType() const;

	bool operator==(const SkinPack&) const;
};
