#pragma once

#include <string>

class BinaryStream;
class NetworkIdentifier;
class NetEventCallback;

class Packet
{
public:
	virtual ~Packet();
	virtual int getId() const = 0;
	virtual const std::string& getName() const = 0;
	virtual void read(BinaryStream&) const = 0;
	virtual void write(BinaryStream&) const = 0;
	virtual void handle(const NetworkIdentifier&, NetEventCallback&) = 0;
	virtual bool disallowBatching() const;
};

