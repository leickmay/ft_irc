#include "../includes/client.hpp"

client::client(int sd, sockaddr_in address):_sd(sd), _address(address), _accessAccepted(false)
{
}

client::~client()
{
}

std::string	client::getNick() const
{
	return _nick;
}

std::string	client::getLogin() const
{
	return _login;
}

std::string	client::getRealName() const
{
	return _realName;
}

std::string	client::getBuffer() const
{
	return _buffer;
}

int			client::getSd() const
{
	return _sd;
}

bool		client::getAccept() const
{
	return _accessAccepted;
}

sockaddr_in	client::getAddress() const
{
	return _address;
}

void	client::setNick(std::string nick)
{
	_nick = nick;
}

void	client::setLogin(std::string login)
{
	_login = login;
}

void	client::setRealName(std::string realName)
{
	_realName = realName;
}

void	client::setBuffer(std::string buffer)
{
	_buffer = buffer;
}

void	client::cleanBuffer()
{
	_buffer.clear();
}

void	client::setSd(int sd)
{
	_sd = sd;
}

void	client::setAccept(bool b)
{
	_accessAccepted = b;
}

void	client::setAddr(sockaddr_in address)
{
	_address = address;
}

std::string	client::getIp() const
{
	std::string ip = inet_ntoa(_address.sin_addr);
	return ip;
}

void		client::addChanInvitation(std::string name)
{
	if (!isInvited(name))
	{
		_chan_invitation.push_back(name);
	}
}

bool		client::isInvited(std::string name)
{
	for (std::vector<std::string>::iterator it = _chan_invitation.begin(); it != _chan_invitation.end(); it++)
	{
		if (*it == name)
			return (true);
	}
	return (false);
}