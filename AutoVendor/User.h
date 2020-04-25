#include <string>
#include <vector>
#include "Order.h"
#ifndef User_h__
#define User_h__

using namespace std;
class User
{
protected: // They are only visible to the children classes
	string username, password;
	string name;
	int age;
	string card;
	double balance;
	vector <Order> orders; // JUST A smart ARRAY OF ORDERS!!!

public: 
	User();
	User(string username, string password);

	string getName() const;
	string getUsername() const;

	bool isAuth(string username, string password);
	virtual bool isPremium() = 0; //pure virtual function, 
								//prevents us from instantiating this class
	void makeOrder(Order order); // adds an order to the list of orders that the user has

	void deleteOrder(Order order);

	virtual ~User(); //virtual destructor
};

#endif // User_h__
