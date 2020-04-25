#pragma once
#include "User.h"
#include <vector>
class FreeUser :
	public User
{
private:
	// pair !!!: 
	std::pair <int, int> timeWindow; 
public:
	FreeUser();
	FreeUser(std::string username, std::string password);
	bool isPremium() override;
	~FreeUser();
};
