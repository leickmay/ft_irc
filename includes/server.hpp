#pragma once
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <map>

#include "client.hpp"
#include "channel.hpp"
#include "parser.hpp"

class server
{
	private:
		int						masterSocket;
		struct sockaddr_in		address;
		fd_set					readfds;
		parser					pars;
		std::vector<client *>	clients;
		std::string				_pass;
		bool					online;

		server();
		server(server const& other);
		server	operator=(server const& other);
		void	_incomingConnexion();
		void	_operation();
		void	_eraseClient(client *c);
		bool	_checkPass(client *c, std::string buf, int sd);
		std::string	_convertCommand(std::string command);

	public:
		server(char **av);
		~server();
		void					start();
		std::vector<client *>	*getClients();
		void					setPass(std::string pass);
		std::string				getPass() const;
		void					setOffline();
};

