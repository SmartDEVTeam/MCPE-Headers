#pragma once

#include "Entity.h"

class Item;
class MobEffectInstance;
class PathNavigation;
class LookControl;
class MoveControl;
class JumpControl;
class BodyControl;
class Sensing;
class MobEffect;
class EntityUniqueID;
class Attribute;
class ItemEntity;
class ArmorSlot;
#include "../item/ItemInstance.h"

// Size : 3178
class Mob : public Entity {
public:
	float yBodyRot; // 352
	float yBodyRotO; // 356
	float yHeadRot; // 360
	float yHeadRotO; // 364
	char mfiller[2572]; // 368
	ItemInstance armor[4]; // 2940
	char mfiller1[96]; // 3020
	bool wat; // 3116
	bool isJumping; // 3117
	int whocares; // 3120
	float speed; // 3124
	LookControl* lookControl; // 3128
	MoveControl* moveControl; // 3132
	JumpControl* jumpControl; // 3136
	BodyControl* bodyControl; // 3140
	PathNavigation* getNavigation; // 3144
	Sensing* getSensing; // 3148
	char mfiller2[32]; // 3152
	float yYa; // 3184
	char mfiller3[4]; // 3188
	bool wat1; // 3192
	bool isSurfaceMob; // 3193
	int wat2; // 3196
	char mfiller4[52]; // 3200
	bool canPickupLoot; // 3252
	bool removeWhenFarAway; // 3253
	int wat3; // 3256
	int wat4; // 3260
	int arrowCount; // 3264
	
	Mob(Level &);
	Mob(BlockSource &);
	
	virtual ~Mob();
	virtual void lerpTo(const Vec3 &, const Vec2 &, int);
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual bool isBaby() const;
	virtual float getHeadHeight() const;
	virtual void playerTouch(Player&);
	virtual bool isImmobile() const;
	virtual bool isPickable();
	virtual bool isPushable() const;
	virtual bool isShootable();
	virtual bool isSneaking() const;
	virtual bool isAlive() const;
	virtual void hurt(const EntityDamageSource&, int);
	virtual void animateHurt();
	virtual void doFireHurt(int);
	virtual void handleEntityEvent(EntityEvent);
	virtual void setOnFire(int);
	virtual void causeFallDamage(float);
	virtual bool canAddRider(Entity&) const;
	virtual void buildDebugInfo(std::string &) const;
	virtual void outOfWorld();
	virtual void readAdditionalSaveData(const CompoundTag&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void _playStepSound(const BlockPos&, int);
	virtual void postInit();
	virtual void knockback(Entity *, int, float, float);
	virtual void die(const EntityDamageSource&);
	virtual void resolveDeathLoot(int);
	virtual bool canSee(const Entity&) const;
	virtual void onLadder();
	virtual void spawnAnim();
	virtual bool isSleeping() const;
	virtual void setSneaking(bool);
	virtual bool isSprinting() const;
	virtual void setSprinting(bool);
	virtual float getVoicePitch();
	virtual void playAmbientSound();
	virtual int getAmbientSoundInterval();
	virtual void getItemInHandIcon(ItemInstance const *, int);
	virtual void getSpeed();
	virtual void setSpeed(float);
	virtual void getJumpPower() const;
	virtual void heal(int);
	virtual void hurtEffects(EntityDamageSource const &, int);
	virtual void getMeleeWeaponDamageBonus(Mob *);
	virtual void getMeleeKnockbackBonus();
	virtual void actuallyHurt(int, EntityDamageSource const *);
	virtual bool isInvertedHealAndHarm() const;
	virtual void travel(float, float);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushEntities();
	virtual void lookAt(Entity *, float, float);
	virtual bool isLookingAtAnEntity();
	virtual bool canSpawn(bool);
	virtual void finalizeMobSpawn();
	virtual bool shouldDespawn() const;
	virtual void getAttackAnim(float);
	virtual void performRangedAttack(Mob &, float);
	virtual ItemInstance& getCarriedItem();
	virtual void setCarriedItem(const ItemInstance&);
	virtual void getItemUseDuration();
	virtual void swing();
	virtual void ate();
	virtual void getMaxHeadXRot();
	virtual Mob* getLastHurtByMob();
	virtual void setLastHurtByMob(Mob*);
	virtual Player* getLastHurtByPlayer();
	virtual void setLastHurtByPlayer(Player*);
	virtual Entity* getLastHurtMob();
	virtual void setLastHurtMob(Entity*);
	virtual Mob* getTarget();
	virtual void setTarget(Mob *);
	virtual void canAttack(Mob *, bool);
	virtual bool isAlliedTo(Mob *);
	virtual void doHurtTarget(Entity *);
	virtual bool canBeControlledByRider();
	virtual void teleportTo(Vec3 const &);
	virtual void getMutableAttribute(const Attribute&);
	virtual void getAttribute(const Attribute&) const;
	virtual int getEquipmentCount() const;
	virtual void getArmorValue();
	virtual void getArmorCoverPercentage();
	virtual void hurtArmor(int);
	virtual void setArmor(ArmorSlot, ItemInstance const *);
	virtual ItemInstance* getArmor(ArmorSlot) const;
	virtual void getAllArmor() const;
	virtual void getAllArmor();
	virtual void getArmorTypeHash();
	virtual void dropHeldItem();
	virtual void dropAllArmor();
	virtual void dropAllGear(int);
	virtual void drop(ItemInstance const *, bool);
	virtual void sendInventory() const;
	virtual bool canBeAffected(MobEffectInstance const &);
	virtual void _removeWhenFarAway();
	virtual void getDeathLoot();
	virtual void dropDeathLoot(int);
	virtual void dropRareDeathLoot();
	virtual void jumpFromGround();
	virtual void _pickUpItem(ItemEntity &);
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void _serverAiMobStep();
	virtual void _getSoundVolume();
	virtual std::string _getAmbientSound();
	virtual std::string _getHurtSound();
	virtual std::string _getDeathSound();
	virtual void getDamageAfterArmorAbsorb(EntityDamageSource const &, int);
	virtual void getDamageAfterMagicAbsorb(EntityDamageSource const &, int);
	virtual void getExperienceReward() const;
	virtual bool useNewAi();
	virtual void onEffectAdded(MobEffectInstance&);
	virtual void onEffectUpdated(MobEffectInstance const &);
	virtual void onEffectRemoved(MobEffectInstance&);
	virtual void registerAttributes();
};
