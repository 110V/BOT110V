#pragma once
#include "consts.h"
#include "cpr\cpr.h"
#include "json.hpp"

#include <string>
#include <sstream>

class papago_api
{
public:
	static std::string translate(std::string lang1, std::string lang2, std::string value);
};