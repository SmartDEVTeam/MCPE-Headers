#pragma once

#include <string>

class IntRectangle;
class Color;
class Font;
class TextureGroup;

namespace mce {
	class TexturePtr;
	class MaterialPtr;
};


class ScreenRenderer {
public:
	enum class ScreenMaterial : int { };

	static ScreenRenderer* singletonPtr;

	ScreenRenderer();
	void blit(const mce::TexturePtr&, const IntRectangle&);
	void blit(const mce::TexturePtr&, float, float, int, int, float, float, int, int, mce::MaterialPtr*);
	void blit(const mce::TexturePtr&, int, int, int, int, int, int, int, int, mce::MaterialPtr*);
	void blitRaw(const mce::TexturePtr&, float, float, float, float, float, float, float, float, float);
	void drawCenteredString(Font*, const std::string&, int, int, const Color&);
	void drawRect(int, int, int, int, const Color&, const Color&, const Color&, const Color&, int);
	void drawRect(int, int, int, int, const Color&, int);
	void drawString(Font*, const std::string&, int, int, const Color&);
	void fill(float, float, float, float, const Color&);
	void fill(int, int, int, int, const Color&);
	void fillGradient(float, float, float, float, const Color&, const Color&);
	void fillGradient(int, int, int, int, const Color&, const Color&);
	void fillHorizontalGradient(float, float, float, float, const Color&, const Color&);
	void fillHorizontalGradient(int, int, int, int, const Color&, const Color&);
	void fillStencil(float, float, float, float);
	void getMaterial(ScreenRenderer::ScreenMaterial);
	void reloadResources(TextureGroup&);
	ScreenRenderer* singleton();
};
