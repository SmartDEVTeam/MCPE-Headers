#pragma once

#include "Player.h"

class RemotePlayer : public Player
{
public:
	virtual ~RemotePlayer();
	virtual void normalTick();
	virtual void aiStep();
	virtual void prepareRegion(ChunkSource&);
	virtual void destroyRegion();
	virtual void suspendRegion();
	virtual void tickWorld(const Tick&);
	virtual void setContainerData(IContainerManager&, int, int);
	virtual void slotChanged(IContainerManager&, int, const ItemInstance&, bool);
	virtual void refreshContainer(IContainerManager&, std::vector<ItemInstance, const std::allocator<ItemInstance>&);
	virtual void onMovePlayerPacketNormal(const Vec3&, const Vec2&);
	virtual void onRegionDestroyed();
};
