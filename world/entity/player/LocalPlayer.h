#pragma once

#include "Player.h"

enum class EntityEvent;
class StructureFeature;

class LocalPlayer : public Player {
public:

	virtual ~LocalPlayer();
	virtual void setPos(Vec3 const&);
	virtual void move(Vec3 const&);
	virtual void normalTick();
	virtual void rideTick();
	virtual void startRiding(Entity&);
	virtual void handleEntityEvent(EntityEvent, int);
	virtual void handleInsidePortal(BlockPos const&);
	virtual void changeDimension(DimensionId);
	virtual void changeDimension(ChangeDimensionPacket const&);
	virtual EntityUniqueID getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void playSynchronizedSound(LevelSoundEvent, Vec3 const&, int, bool);
	virtual void stopRiding(bool, bool);
	virtual void drop(ItemInstance const&, bool);
	virtual bool outOfWorld();
	virtual void _hurt(EntityDamageSource const&, int, bool, bool);
	virtual void readAdditionalSaveData(CompoundTag const&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void die(EntityDamageSource const&);
	virtual void setSneaking(bool);
	virtual void setSprinting(bool);
	virtual void actuallyHurt(int, EntityDamageSource const*, bool);
	virtual void travel(float, float);
	virtual void applyFinalFriction(float);
	virtual void aiStep();
	virtual void swing();
	virtual void setArmor(ArmorSlot, ItemInstance const&);
	virtual void setItemSlot(EquipmentSlot, ItemInstance&);
	virtual void setOffhandSlot(ItemInstance const&);
	virtual void updateAi();
	virtual void onEffectRemoved(MobEffectInstance&);
	virtual void destroyRegion();
	virtual void _fireDimensionChanged();
	virtual void changeDimensionWithCredits(DimensionId);
	virtual void tickWorld(Tick const&);
	virtual void checkMovementStats(Vec3 const&);
	virtual StructureFeature* getCurrentStructureFeature() const;
	virtual void respawn();
	virtual void resetRot();
	virtual void resetPos(bool);
	virtual bool isInTrialMode();
	virtual void startCrafting(BlockPos const&, bool);
	virtual void openContainer(BlockPos const&);
	virtual void openContainer(EntityUniqueID const&);
	virtual void openFurnace(BlockPos const&);
	virtual void openEnchanter(BlockPos const&);
	virtual void openAnvil(BlockPos const&);
	virtual void openBrewingStand(BlockPos const&);
	virtual void openHopper(BlockPos const&);
	virtual void openHopper(EntityUniqueID const&);
	virtual void openDispenser(BlockPos const&, bool);
	virtual void openBeacon(BlockPos const&);
	virtual void openPortfolio();
	virtual void openCommandBlock(BlockPos const&);
	virtual void openCommandBlockMinecart(EntityUniqueID const&);
	virtual void openHorseInventory(EntityUniqueID const&);
	virtual void openTrading(EntityUniqueID const&);
	virtual void openChalkboard(ChalkboardBlockEntity&);
	virtual void openNpcInteractScreen(Entity&);
	virtual void openInventory();
	virtual void openStructureEditor(BlockPos const&);
	virtual void displayClientMessage(std::string const&);
	virtual void displayLocalizableMessage(std::string const&, std::vector<std::string>, bool);
	virtual void displayWhisperMessage(std::string const&, std::string const&);
	virtual void startSleepInBed(BlockPos const&);
	virtual void stopSleepInBed(bool, bool);
	virtual bool canStartSleepInBed();
	virtual void openSign(BlockPos const&);
	virtual bool isLocalPlayer() const;
	virtual void stopLoading();
	virtual void setPlayerGameType(GameType);
	virtual void _crit(Entity&);
	virtual MinecraftEventing* getEventing() const;
	virtual void addExperience(int);
	virtual void addLevels(int);
	virtual void setContainerData(IContainerManager&, int, int);
	virtual bool slotChanged(IContainerManager&, int, ItemInstance const&, ItemInstance const&);
	virtual void refreshContainer(IContainerManager&, std::vector<ItemInstance> const&);
	virtual void deleteContainerManager();
	virtual bool isEntityRelevant(Entity const&);
	virtual bool isTeacher() const;
	virtual void chorusFruitTeleport();

};