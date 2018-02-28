#include "messeage_checker.h"

bool messeage_checker::translate_to_eng(std::string str)
{
	std::regex reg("^.+eng$");
	if (std::regex_match(str, reg))
		return true;
	return false;
}
bool messeage_checker::translate_to_kor(std::string str)
{
	std::regex reg("^.+kor$");
	if (std::regex_match(str, reg))
		return true;
	return false;
}
bool messeage_checker::check_go(std::string str)
{
	std::regex reg(u8".*(go|고).*");
	if (std::regex_match(str, reg))
		return true;
	return false;
}
bool messeage_checker::check_gorani(std::string str)
{
	std::regex reg(u8".*(gorani|고라니).*");
	if (std::regex_match(str, reg))
		return true;
	return false;
}
