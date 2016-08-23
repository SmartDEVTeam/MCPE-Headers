#pragma once

#include "SkinInfoData.h"

// Size : 28
class ServerSkinInfoData : public SkinInfoData {
public:
	char sid_vars[8]; // 20
	
	ServerSkinInfoData();
	virtual ~ServerSkinInfoData();
	virtual void updateSkin(const std::string&, const std::vector<unsigned char>&);
	virtual TexturePair* getTexturePair();
	virtual std::string getData() = 0;
	virtual int getDataLength() = 0;
	virtual bool hasValidTexture() = 0;
	virtual void validataAndResizeSkinData(std::vector<unsigned char>&);
};
