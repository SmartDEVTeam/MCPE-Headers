#pragma once

class RectangleArea
{
    float x, y, w, h;

	RectangleArea();
	RectangleArea(float, float, float, float, bool);

	void centerX() const;
	void centerY() const;
	void clampToNorm() const;
	void grow(float) const;
	bool isEmpty() const;
	bool isInside(float, float) const;
	void resizeAroundCenter(float, float) const;
	void scale(float) const;
	void translate(float, float) const;
	void unionReacts(const RectangleArea&) const;
	RectangleArea* set(float, float, float, float);
	operator=(const RectangleArea&);
};
