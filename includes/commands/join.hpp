#pragma once
#include <iostream>
#include <sys/socket.h>
//#include "../parser.hpp"
#include "../client.hpp"
#include "../channel.hpp"

class join
{
private:
//	std::string _name;
//	client		*_cli;
//	server		*_serv;
	bool	_checkName(std::string name, channel *chan);
	void	_joinAlreadyExists(std::string name, client *cli, channel *chan);
public:
	join();
	void	execute(std::string buf, client *cli, channel *chan);
	void	broadcastMsg(std::string buf, client *cli, channel *chan);
	~join();
};


