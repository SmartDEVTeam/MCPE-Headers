#pragma once

#include <vector>
#include <string>
#include <memory>

class Textures;
class TexturePair;
class HumanoidModel;

// Size : 20
// 0.15.6
class SkinInfoData {
public:
	bool idk; // 4
	std::string geometryName; // 8
	std::string skinId; // 12
	std::unique_ptr<HumanoidModel> visualModel; // 16

	SkinInfoData();
	virtual ~SkinInfoData();
	virtual void updateSkin(const std::string&, const std::vector<unsigned char>&);
	virtual TexturePair* getTexturePair();
	virtual std::string getData() = 0;
	virtual int getDataLength() = 0;
	virtual bool hasValidTexture() = 0;
	virtual void validataAndResizeSkinData(std::vector<unsigned char>&);
	void copySkinPart(std::vector<unsigned char>&, int, int, int, int, int, int, int, int);
	std::string getGeometryName() const;
	std::string getSkinId() const;
	std::unique_ptr<HumanoidModel> getVisualModel();
	void setForceAlpha(std::vector<unsigned char>&, int, int, int, int);
	void setNoAlpha(std::vector<unsigned char>&, int, int, int, int);
	void setVisualModel(std::unique_ptr<HumanoidModel>);
	bool validateAlpha(std::vector<unsigned char>&, int, int, int, int, float);
};
