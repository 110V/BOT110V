#include "logger.h"
#include "utils.h"

void logger::init()
{
	std::wcout.imbue(std::locale("korean"));
}
void logger::log(std::string str)
{
	std::wcout << widen(str);
}
void logger::logln(std::string str)
{
	std::wcout << widen(str)<<std::endl;
}