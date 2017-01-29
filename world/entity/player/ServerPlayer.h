#pragma once

#include "Player.h"
#include "../../inventory/IContainerListener.h"
class PacketSender;
class NetworkIdentifier;
class NetworkHandler;
class SkinInfoData;
namespace mce { class UUID; }

class ServerPlayer : public Player, public IContainerListener
{
public:
	ServerPlayer(Level&, PacketSender&, NetworkHandler&, GameType, const NetworkIdentifier&, std::function<void ()(ServerPlayer&)>, std::unique_ptr<SkinInfoData, std::default_delete<SkinInfoData>>, mce::UUID, int);	
	
	virtual ~ServerPlayer();
	virtual void normalTick();
	virtual void push(const Vec3&);
	virtual void changeDimension(DimensionId);
	virtual void getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void knockback(Entity*, int, float, float, float);
	virtual void aiStep();
	virtual void hurtArmor(int);
	virtual void onEffectAdded(MobEffectInstance&);
	virtual void onEffectUpdated(const MobEffectInstance&);
	virtual void onEffectRemoved(MobEffectInstance&);
	virtual void destroyRegion();
	virtual void changeDimensionWithCredits(DimensionId);
	virtual void tickWorld(const Tick&);
	virtual void checkMovementStats(const Vec3&);
	virtual void setPermissions(CommandPermissionLevel);
	virtual void openContainer(int, const BlockPos&);
	virtual void openContainer(int, const EntityUniqueID&);
	virtual void openFurnace(int, const BlockPos&);
	virtual void openEnchanter(int, const BlockPos&);
	virtual void openAnvil(int, const BlockPos&);
	virtual void openBrewingStand(int, const BlockPos&);
	virtual void openHopper(int, const BlockPos&);
	virtual void openHopper(int, const EntityUniqueID&);
	virtual void openDispenser(int, const BlockPos&, bool);
	virtual void openBeacon(int, const BlockPos&);
	virtual void openPortfolio();
	virtual void openHorseInventory(int, const EntityUniqueID&);
	virtual void openNpcInteractScreen(Entity&);
	virtual void openInventory();
	virtual void openStructureEditor(const BlockPos&);
	virtual void displayLocalizableMessage(const std::string&, std::vector<std::string, const std::allocator<std::string>&, bool);
	virtual void displayWhisperMessage(const std::string&, const std::string&);
	virtual void stopSleepInBed(bool, bool);
	virtual void setPlayerGameType(GameType);
	virtual void setContainerData(IContainerManager&, int, int);
	virtual void slotChanged(IContainerManager&, int, const ItemInstance&, bool);
	virtual void refreshContainer(IContainerManager&, std::vector<ItemInstance, const std::allocator<ItemInstance>&);
	virtual void deleteContainerManager();
	virtual bool isPositionRelevant(DimensionId, const BlockPos&);
	virtual bool isEntityRelevant(const Entity&);
	virtual void onSuspension();
	
	void disconnect();
	void doCloseContainer();
	void nextContainerCounter();
	void setPlayerInput(float, float, bool, bool);
};
