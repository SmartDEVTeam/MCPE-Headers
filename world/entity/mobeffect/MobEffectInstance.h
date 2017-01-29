#pragma once

#include <vector>
#include <string>

class Mob;
class CompoundTag;

// For 1.0.2.1
// Size : 14
class MobEffectInstance
{
public:
	int id; // 0
	int duration; // 4
	int amplifier; // 8
	bool ambient; // 12
	bool noCounter; // 13
	bool visibleEffect; // 14

	MobEffectInstance();
	MobEffectInstance(int id);
	MobEffectInstance(int id, int duration);
	MobEffectInstance(int id, int duration, int amplifier);
	MobEffectInstance(int id, int duration, int amplifier, bool ambient, bool visibleEffect);
	void applyEffects(Mob*) const;
	bool areAllEffectsAmbient(const std::vector<MobEffectInstance, std::allocator<MobEffectInstance>>&);
	float getAmplifier();
	void getColorValue(const std::vector<MobEffectInstance, std::allocator<MobEffectInstance>>&);
	void getComponentName() const;
	std::string getDescriptionId() const;
	std::string getDisplayName() const;
	float getDuration() const;
	int getId() const;
	float getLingerDuration() const;
	float getSplashDuration() const;
	void* getSplashEffect() const;
	bool isAmbient() const;
	bool isEffectVisible() const;
	bool isNoCounter() const;
	void load(CompoundTag*);
	bool operator!=(const MobEffectInstance&) const;
	bool operator<(const MobEffectInstance&) const;
	bool operator==(const MobEffectInstance&) const;
	void removeEffects(Mob*) const;
	void save() const;
	MobEffectInstance* setDuration(int);
	MobEffectInstance* setNoCounter(bool);
	bool tick(Mob*);
	std::string toString() const;
	void update(const MobEffectInstance&);
};
