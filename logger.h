#pragma once
#include <string>
#include <iostream>



class logger
{
public:
	static void init();
	static void log(std::string str);
	static void logln(std::string str);
};