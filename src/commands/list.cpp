#include "../../includes/commands/list.hpp"

list::list()
{
}
list::~list()
{
}

void list::execute(std::string buf, client *cli, std::vector<channel *> *channels)
{
	std::string message;
	std::string chan_list;
	channel *cur_chan;
	size_t i = 1;

	_getCmd(buf);
	if (_cmd.size() > 1 && _cmd[1] == "")
		_cmd.pop_back();

	std::cout << BOLDBLUE << "_cmd.size() = " << _cmd.size() << RESET << std::endl;
	if (_cmd.size() > 1)
	{
		while (i < _cmd.size())
		{
			cur_chan = _getChan(_cmd[i], channels);
			if (cur_chan != NULL && !cur_chan->isSecrect)
			{
				chan_list.append(cur_chan->getName() + " # ");
				if (!cur_chan->isPrivate)
					chan_list.append(":" + cur_chan->getTopic());
				message = ":server " + std::string(RPL_LISTSTART) + " Channel :Users Name\r\n";
				send(cli->getSd(), message.c_str(), message.length(), 0);
				message = ":server " + std::string(RPL_LIST) + " " + chan_list + "\r\n";
				send(cli->getSd(), message.c_str(), message.length(), 0);
				message = ":server " + std::string(RPL_LISTEND) + " :End of /LIST\r\n";
				send(cli->getSd(), message.c_str(), message.length(), 0);
			}
			chan_list.clear();
			i++;
		}
	}
}