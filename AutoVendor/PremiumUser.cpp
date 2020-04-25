#include "PremiumUser.h"

PremiumUser::PremiumUser()
{
}

PremiumUser::PremiumUser(string username, string password):
	User (username, password)
{
	discountRate = 0;
}

PremiumUser::~PremiumUser()
{
}

bool PremiumUser::isPremium()
{
	return true;
}
