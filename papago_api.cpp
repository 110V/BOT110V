#include "papago_api.h"

using json = nlohmann::json;

std::string papago_api::translate(std::string lang1, std::string lang2, std::string content)
{
	std::stringstream body_ss;
	//source =  & target =  & text = 
	body_ss << "source =" << lang1 << "& target=" << lang2 << "& text = " << content;

	auto response = cpr::Post(
		cpr::Url{ "https://openapi.naver.com/v1/papago/n2mt" },
		cpr::Body{body_ss.str()},
		cpr::Header{ 
			{"Content-Type","application/x-www-form-urlencoded"},
			{"X-Naver-Client-Id",consts::ClientID},
			{"X-Naver-Client-Secret",consts::ClientSecret} });
	json j = json::parse(response.text);
	if (!j["message"]["result"]["translatedText"].empty())
	{
		return j["message"]["result"]["translatedText"];
	}
	else
	{
		return j["errorMessage"];
	}
}