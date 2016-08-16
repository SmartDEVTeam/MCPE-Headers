#pragma once

#include <string>
#include <vector>

class SkinPack;

// Size : 24
class Skin
{
public:
	enum SkinType
	{
		DEFAULT, FREE, PAID
	};

	SkinPack *pack;			// 0
	std::string serializable;	// 4
	std::string name;			// 8
	std::string geometryName;	// 12
	std::string path;			// 16
	SkinType type;			// 20

	Skin(std::string const&, std::string const&, std::string const&, std::string const&, Skin::SkinType);

	SkinPack *getSkinPack() const;
	void setSkinPack(SkinPack *);

	const std::string &getSerializable() const;
	const std::string &getName() const;
	const std::string &getGeometryName() const;
	const std::string &getPath() const;

	bool premiumLocked() const;
	bool isCustomSkin() const;

	bool operator==(Skin const &) const;
};
