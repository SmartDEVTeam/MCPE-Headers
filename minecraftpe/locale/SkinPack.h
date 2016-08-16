#pragma once

#include <string>
#include <vector>

// Size : 32
class SkinPack
{
public:
	enum SkinPackType
	{
		DEFAULT, PACK
	};

	std::string serializableName;	// 0
	std::string name;				// 4
	std::string price;				// 8
	bool unlocked;				// 12
	std::vector<Skin> skins;			// 16
	SkinPackType type;			// 28

	SkinPack(SkinPackType type, std::string const &serializableName, std::string name, bool unlocked, std::initializer_list<Skin> const &skins);

	const std::string &getSerializableName() const;

	const std::string &getPrice() const;
	void setPrice(std::string const &);

	bool isPremiumUnlocked() const;
	bool setPremiumUnlocked(bool);

	const std::string &getName() const;
	const std::vector<Skin> &getSkins() const;
	SkinPackType getSkinPackType() const;

	bool operator==(SkinPack const &) const;
};
