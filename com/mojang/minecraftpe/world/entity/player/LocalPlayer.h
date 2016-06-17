#pragma once

#include "Player.h"
class Tick;
class IContainerManager;

class LocalPlayer : public Player
{
public:
	virtual ~LocalPlayer();
	virtual void setPos(const Vec3&);
	virtual void move(const Vec3&);
	virtual void normalTick();
	virtual void rideTick();
	virtual void startRiding(Entity&);
	virtual void hurt(const EntityDamageSource&, int);
	virtual void handleInsidePortal(const BlockPos&);
	virtual void changeDimension(DimensionId);
	virtual void changeDiemnsion(ChangeDimensionPacket&);
	virtual Player* getControllingPlayer() const;
	virtual void chackFallDamage(float, bool);
	virtual void stopRiding(bool);
	virtual bool outOfWorld();
	virtual void readAdditionalSaveData(const CompoundTag*);
	virtual void addAdditionalSaveData(CompoundTag*);
	virtual void die(const EntityDamageSource&);
	virtual void setSneaking(bool);
	virtual void setSprinting(bool);
	virtual void actuallyHurt(int, const EntityDamageSource&);
	virtual void travel(float, float);
	virtual void applyFinalFriction(float);
	virtual void aiStep();
	virtual void swing();
	virtual void setArmor(ArmorSlot, const ItemInstance*);
	virtual void drop(const ItemInstance*, bool);
	virtual void updateAi();
	virtual void destroyRegion();
	virtual void onPrepChangeDimension();
	virtual void onDimensionChanged();
	virtual void tickWorld(const Tick&);
	virtual void checkMovementStatistiscs(const Vec3&);
	virtual void respawn();
	virtual void resterPos(bool);
	virtual bool isInTrialMode();
	virtual void startCrafting(const BlockPos&);
	virtual void openContainer(int, const BlockPos&);
	virtual void openContainer(int, const EntityUniqueID&);
	virtual void openFurnace(int, const BlockPos&);
	virtual void openEnchanter(int, const BlockPos&);
	virtual void openAnvil(const BlockPos&);
	virtual void openBrewingStand(int, const BlockPos&);
	virtual void openHopper(int, const BlockPos&);
	virtual void openHopper(int, const EntityUniqueID&);
	virtual void openDispenser(int, const BlockPos&);
	virtual void openPortfolio();
	virtual void displayLocalizableMessage(const std::string&, const std::vector<std::string, std::allocator<std::string>>&);
	virtual void startSleepInBed(const BlockPos&);
	virtual void stopSleepInBed(bool, bool);
	virtual bool canStartSleepInBed();
	virtual void openTextEdit(BlockEntity*);
	virtual bool isLocalPlayer() const;
	virtual void stopLoading();
	virtual void _crit(Entity&);
	virtual void getTelemetry() const;
	virtual void setContainerData(IContainerManager&, int, int);
	virtual void slotChanged(IContainerManager&, int, const ItemInstance&, bool);
	virtual void refreshContainer(IContainerManager&, const std::vector<ItemInstance, std::allocator<ItemInstance>>&);
	virtual void deleteContainerManager();
};
