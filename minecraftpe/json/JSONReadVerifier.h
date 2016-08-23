#pragma once

#include "reader.h"

class JSONReadVerifier {
public:
	static void verifyRead(const std::string&, Json::Reader&, bool);
};