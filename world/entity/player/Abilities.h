#pragma once

#include <string>

class Ability;
class CompoundTag;
class PermissionsHandler;
struct CommandPermissionLevel;

class Abilities
{
private:
	void* _registerAbilities();
	void* _registerAbilities(const std::string&, const Ability&);

public:
	Abilities();

	void addSaveData(CompoundTag&);
	void* getAbilities() const;
	void* getAbility(const std::string&) const;
	void* getAbility(const std::string&);
	bool getBool(const std::string&) const;
	PermissionsHandler getCommandPermissions() const;
	float getFloat(const std::string&);
	bool isFlying() const;
	void loadSaveData(const CompoundTag&);
	void setAbility(cosnt std::string&, bool);
	void setAbility(cosnt std::string&, float);
	void setCommandPermissions(CommandPermissionLevel);
};
