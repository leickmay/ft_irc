#pragma once

#include "command.hpp"


class privmsg : public command
{
	private :
		std::vector<std::string> cmd;
		void getCmd(std::string buf);

	public :
		privmsg();
		~privmsg();

		void execute(std::string buf, client *cli, std::vector<channel *> *channels, std::vector<client *> *cli_list);
};