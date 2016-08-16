#pragma once

#include <memory>
#include <chrono>
#include <ratio>
#include "../gamemode/GameType.h"

class GameCallbacks;
class SkinInfoFactory;
class Vibration;
class SoundPlayer;
class Whitelist;
class LevelSettings;
class ServerCommandParser;
class GameMode;
class Level;
class NetEventCallback;
class PacketSender;
class RakNetInstance;
class ServerNetworkHandler;
class Player;
class NetworkHandler;
class Timer;
class BatchedPacketSender;
class ExternalFileLevelStorageSource;
namespace RakNet { class RakNetGUID; };

// Size : 80
class Minecraft {
public:
	GameCallbacks& gameCallBacks; // 0
	SkinInfoFactory& skinInfo; // 4
	Vibration& vibration; // 8
	SoundPlayer& soundPlayer; // 12
	std::string gameUser; // 16
	const Whitelist& whitelist; // 20
	ExternalFileLevelStorageSource* fileStorage; // 24
	std::string gameName; // 28
	bool hasLeftGame; // 32
	int filler_i; // 36
	char mc_vars[32]; // 40
	Timer* timer; // 72
	NetworkHandler* networkHandler; // 76
	BatchedPacketSender* packetSender; // 80

public:
	Minecraft(GameCallbacks&, SkinInfoFactory&, Vibration&, SoundPlayer&, const Whitelist&, const std::string&, std::chrono::duration<long long, std::ratio<1ll, 1ll>>);
	~Minecraft();
	void createGameMode(GameType, Level&);
	void createLevel(const std::string&, const std::string&, const LevelSettings&);
	void disconnectClient(const RakNet::RakNetGUID&, bool, const std::string&);
	ServerCommandParser* getCommandParser();
	GameMode* getGameMode();
	Level* getLevel();
	ExternalFileLevelStorageSource* getLevelSource();
	NetEventCallback* getNetEventCallback();
	PacketSender* getPacketSender();
	RakNetInstance* getRakNetInstance();
	std::string getServerName();
	ServerNetworkHandler* getServerNetworkHandler();
	void* getTimer();
	void* getUser();
	void hostMultiplayer(std::unique_ptr<Level>, std::unique_ptr<GameMode>, Player* , std::unique_ptr<NetEventCallback>, int, bool, int, int);
	void init(const std::string&);
	void initAsDedicatedServer();
	bool isModded();
	bool isOnlineClient();
	void onClientStartedLevel(std::unique_ptr<Level>);
	void resetGameSession();
	void restartMultiplayerHost(int, int);
	void setGameModeReal(GameType);
	void setLeaveGame();
	void setupServerCommands();
	void startClientGame(std::unique_ptr<NetEventCallback>);
	void stopGame();
	void teardown();
	void tick(int, int);
	void update();
	void validateLevel(const std::string&, const std::string&, LevelSettings&);
};
