#include "User.h"

User::User()
{
	balance = 0;
	age = 0;

}

User::User(string username, string password):
	username (username), password (password)
{
	// a call to the function to get the other data
}

string User::getName() const
{
	return name;
}

string User::getUsername() const
{
	return username;
}

bool User::isAuth(string username, string password)
{
	return (this->username == username && this->password == password);
}

void User::makeOrder(Order order)
{
	// adding one element to the orders
	orders.push_back(order);
}

void User::deleteOrder(Order order)
{
	// erasing the element from the array!
	 // return a position of the order we want to delete!
	orders.erase(find(orders.begin(), orders.end(), order));
}

User::~User()
{
	
}


