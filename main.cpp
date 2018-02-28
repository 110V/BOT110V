#include <string>

#include "sleepy_discord\websocketpp_websocket.h"
#include "papago_api.h"
#include "messeage_checker.h"
#include "logger.h"




class myClientClass : public SleepyDiscord::DiscordClient {
public:
	using SleepyDiscord::DiscordClient::DiscordClient;
	void onMessage(SleepyDiscord::Message message)
	{
		if (message.author.bot)
		{
			return;
		}
		logger::logln(message.author.username + " : " + message.content);
		if (messeage_checker::translate_to_eng(message.content))
		{
			std::string translatedText = papago_api::translate("ko", "en", message.content.substr(0, message.content.length() - 3));
			sendMessage(message.channelID, message.author.username + "->" + translatedText);
		}
		else if (messeage_checker::translate_to_kor(message.content))
		{
			std::string translatedText = papago_api::translate("en", "ko", message.content.substr(0, message.content.length() - 3));
			sendMessage(message.channelID, message.author.username + "->" + translatedText);
		}
		else if (messeage_checker::check_go(message.content))
		{
			sendMessage(message.channelID, u8"고감지");
		}
		if (messeage_checker::check_gorani(message.content))
		{
			addReaction(message.channelID, message.ID, "gorani%3A417327720662302720");
		}
	}
};

int main()
{
	logger::init();
	myClientClass client(consts::DiscordToken, 2);
	client.run();
}
