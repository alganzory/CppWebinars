#pragma once
#include "User.h"
class PremiumUser :
	public User
{
private:
	double discountRate;
public: 
	PremiumUser();
	PremiumUser(string username, string password);
	~PremiumUser();
	bool isPremium() override; // redefining the actual function 

};

