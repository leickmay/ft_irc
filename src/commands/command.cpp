#include "../../includes/commands/command.hpp"

command::command()
{
}

command::~command()
{
}

channel*	command::_getChan(std::string name, std::vector<channel *> *channels)
{
	for (std::vector<channel *>::iterator it = channels->begin(); it != channels->end(); it++)
	{
		channel *c = *it;
		if (c->getName() == name)
			return c;
	}
	return NULL;
}


bool	command::_checkClient(client *cli, channel *chan)
{
	std::vector<client *> members = chan->getMembers();
	client *c;
	for (std::vector<client*>::iterator it = members.begin(); it != members.end(); it++)
	{
		c = *it;
		if (c->getSd() == cli->getSd())
			return true;
	}
	return false;
}

void command::_getCmd(std::string buf)
{
	char delimiter = ' ';
	std::vector<std::string> cmd_tmp;
	std::string line;
	std::stringstream ss(buf);
	while (std::getline(ss, line, delimiter))
	{
		while (line.back() == '\n' || line.back() == '\r')
			line.pop_back();
		cmd_tmp.push_back(line);
	}
	while (cmd_tmp.back() == "\n" || cmd_tmp.back() == "\r" || cmd_tmp.back().size() == 0)
		cmd_tmp.pop_back();
	if (cmd_tmp.size() > 2 && cmd_tmp[2][0] == ':')
		cmd_tmp[2] = &cmd_tmp[2][1];
	_cmd.clear();
	_cmd = cmd_tmp;

	for (std::vector<std::string>::iterator it = _cmd.begin(); it != _cmd.end(); it++)
	{
		std::cout << BOLDYELLOW << "_cmd = |" + (*it) + "|" << RESET << std::endl;
	}
	
}