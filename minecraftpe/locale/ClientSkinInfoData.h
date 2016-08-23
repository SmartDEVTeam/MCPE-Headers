#pragma once

#include "SkinInfoData.h"

class SkinRepository;

// Size : 28
class ClientSkinInfoData : public SkinInfoData {
public:
	TexturePair* texture; // 20
	bool validTexture; // 24

	static Textures* mTextures;
	static SkinRepository* mSkinRepository;

	ClientSkinInfoData();
	virtual void updateSkin(const std::string&, const std::vector<unsigned char>&);
	virtual TexturePair* getTexturePair();
	virtual std::string getData();
	virtual int getDataLength();
	virtual bool hasValidTexture();
	virtual void validataAndResizeSkinData(std::vector<unsigned char>&);
};
