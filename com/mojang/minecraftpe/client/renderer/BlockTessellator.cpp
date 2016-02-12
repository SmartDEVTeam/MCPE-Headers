#include "BlockTessellator.h"

void BlockTessellator::setRenderBounds(float x1, float y1, float z1, float x2, float y2, float z2) {
	aabb.set(x1, y1, z1, x2, y2, z2);
}