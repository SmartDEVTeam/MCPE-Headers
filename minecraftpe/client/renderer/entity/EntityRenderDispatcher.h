#pragma once

#include "../../AppPlatformListener.h"
#include "../../../world/entity/EntityRendererId.h"

class Vec3;
class MinecraftClient;
class EntityRenderer;
class Entity;
class Level;
class Font;
class Options;
class ItemInHandRenderer;
class HumanoidMobRenderer;
class ItemRenderer;
class BlockTessellator;
class ChickenRenderer;
class MobRenderer;
class MushroomCowRenderer;
class SheepRenderer;
class SkeletonRenderer;
class BlazeRenderer;
class GhastRenderer;
class CreeperRenderer;
class SpiderRenderer;
class SlimeRenderer;
class LavaSlimeRenderer;
class EnderManRenderer;
class WolfRenderer;
class BatRenderer;
class TntRenderer;
class ArrowRenderer;
class FishHookRenderer;
class PlayerRenderer;
class ItemSpriteRenderer;
class ThrownPotionRenderer;
class PaintingRenderer;
class FallingBlockRenderer;
class MinecartRenderer;
class BoatRenderer;
class VillagerRenderer;
class SilverFishRenderer;
class SquidRenderer;
class FireballRenderer;
class OcelotRenderer;
class VillagerZombieRenderer;
class ExperienceOrbRenderer;
class LightningBoltRenderer;
class IronGolemRenderer;
class SnowGolemRenderer;
class RabbitRenderer;
class WitchRenderer;
class TripodCameraRenderer;
class MapRenderer;

class EntityRenderDispatcher : public AppPlatformListener {
public:
	static EntityRenderDispatcher *instance;

	MinecraftClient& mcClient; // 8
	BlockTessellator* blockRenderer; // 12
	ItemInHandRenderer* handRenderer; // 16
	Level* level; // 20
	Entity* cameraEntity; // 24
	Entity* crosshairPickEntity; // 28
	Vec3& cameraRot; // 32
	char erd_vars1[4]; // 36
	Options* options; // 40
	Font* font; // 44
	EntityRenderer* entityRenderers[50]; // 48
	char erd_vars2[4]; // 52
	TntRenderer* tntRenderer; // 56
	HumanoidMobRenderer* zombieRenderer; // 60
	ItemRenderer* itemRenderer; // 64
	ChickenRenderer* chickenRenderer; // 68
	MobRenderer* cowRenderer; // 72
	MushroomCowRenderer* mooshroomRenderer; // 76
	char erd_vars3[4]; // 80
	SheepRenderer* sheepRenderer; // 84
	BatRenderer* batRenderer; // 88
	WolfRenderer* wolfRenderer; // 92
	VillagerRenderer* villagerRenderer; // 96
	char erd_vars4[4]; // 100
	HumanoidMobRenderer* armorZombieRenderer; // 104
	HumanoidMobRenderer* pigZombieRenderer; // 108
	LavaSlimeRenderer* magmaCubeRenderer; // 112
	GhastRenderer* ghastRenderer; // 116
	BlazeRenderer* blazeRenderer; // 120
	SkeletonRenderer* skeletonRenderer; // 124
	SpiderRenderer* spiderRenderer; // 128
	SilverFishRenderer* silverFishRenderer; // 132
	CreeperRenderer* creeperRenderer; // 136
	SlimeRenderer* slimeRenderer; // 140
	EnderManRenderer* enderManRenderer; // 144
	ArrowRenderer* arrowRenderer; // 148
	FishHookRenderer* fishHookRenderer; // 152
	PlayerRenderer* playerRenderer; // 156
	ItemSpriteRenderer* itemSpriteRenderer1; // 160
	ItemSpriteRenderer* itemSpriteRenderer2; // 164
	ItemSpriteRenderer* itemSpriteRenderer3; // 168
	ThrownPotionRenderer* potionRenderer; // 172
	PaintingRenderer* paintingRenderer; // 176
	FallingBlockRenderer* sandRenderer; // 180
	MinecartRenderer* minecartRenderer; // 184
	BoatRenderer* boatRenderer; // 188
	SquidRenderer* squidRenderer; // 192
	FireballRenderer* smallFireballRenderer; // 196
	FireballRenderer* largeFireballRenderer; // 200
	VillagerZombieRenderer* zombieVillagerRenderer; // 204
	ExperienceOrbRenderer* expRenderer; // 208
	LightningBoltRenderer* lightingingRenderer; // 212
	IronGolemRenderer* ironGolemRenderer; // 216
	OcelotRenderer* ocelotRenderer; // 220
	SnowGolemRenderer* snowGolemRenderer; // 224
	ItemSpriteRenderer* itemSpriteRenderer4; // 228
	RabbitRenderer* rabbitRenderer; // 232
	WitchRenderer* witchRenderer; // 236
	TripodCameraRenderer* cameraRenderer; // 240
	char erd_vars5[4]; // 244
	MapRenderer* mapRenderer; // 248

	EntityRenderDispatcher(MinecraftClient&);
	virtual ~EntityRenderDispatcher();
	virtual void onAppSuspended();
	EntityRenderer* getRenderer(Entity&);
	EntityRenderer* getRenderer(EntityRendererId);
	void prepare(Level*, Font*, Entity*, Entity*, Options*, float);
	void render(Entity&, const Vec3&, float, float);
	void render(Entity&, float);
	void renderDebug(Entity&);
	void setCameraTargetPos(const Vec3&);
	void setLevel(Level*);
	Entity* getCameraEntity();
	float getCameraRot();
};
