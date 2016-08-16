#pragma once

#include "GuiElement.h"

class TextBox : public GuiElement
{
public:
	TextBox(MinecraftClient&, Options::Option, const std::string&, const std::string&);

	virtual ~TextBox();
	virtual void tick(MinecraftClient*);
	virtual void render(MinecraftClient*, int, int);
	virtual void topRender(MinecraftClient*, int, int);
	virtual void pointerPressed(MinecraftClient*, int, int);
	virtual void pointerReleased(MinecraftClient*, int, int);
	virtual void focusedMouseClicked(MinecraftClient*, int, int);
	virtual void focusedMouseReleased(MinecraftClient*, int, int);
	virtual void handleButtonRelease(MinecraftClient*, short);
	virtual void handleTextChar(MinecraftClient*, const std::string&, bool);
	virtual void handleCaretLocation(int);
	virtual void backPressed(MinecraftClient*, bool);
	virtual void suppressOtherGUI();
	virtual void setTextBoxText(const std::string&);
	virtual bool hasFocus() const;
	virtual void setFocus(MinecraftClient*);
	virtual void loseFocus(MinecraftClient*);
};
