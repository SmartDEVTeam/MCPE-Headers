#pragma once

#include "Button.h"

namespace Touch {

class TButton : public Button {
public:
	char filler[8];

	TButton(int, std::string const&, MinecraftClient*, bool, int);
	TButton(int, int, int, std::string const&, MinecraftClient*, int);
	TButton(int, int, int, int, int, std::string const&, MinecraftClient*, bool, int);
	virtual ~TButton();
	virtual void renderBg(MinecraftClient*, int, int);

	void init(MinecraftClient*);
	void init(MinecraftClient*, std::string const&, IntRectangle const&, IntRectangle const&, int, int, int, int);
};

};
