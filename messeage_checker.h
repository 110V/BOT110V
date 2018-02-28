#pragma once
#include <string>
#include <regex>



class messeage_checker
{
public:
	static bool translate_to_eng(std::string str);
	static bool translate_to_kor(std::string str);
	static bool check_go(std::string str);
	static bool check_gorani(std::string str);
};
