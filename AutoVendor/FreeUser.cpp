#include "FreeUser.h"

FreeUser::FreeUser()
{
}

FreeUser::FreeUser(std::string username, std::string password) :
	User(username, password)
{
}

bool FreeUser::isPremium()
{
	return false;
}


FreeUser::~FreeUser()
{
}
