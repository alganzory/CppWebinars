#pragma once

#include "Item.h"
#include <string>
#include <vector>
#include <memory>


class User;

class Order
{
private:
	std::string orderID;
	std::shared_ptr <User> orderer; // Order* => shared_ptr < Order> => smart pointer
	std::vector <std::shared_ptr <Item> > items; // array of pointers!!!
	double orderCost; // the final price of the cart
	bool paymentStatus; 
public:
	Order();
	Order(std::shared_ptr<User> orderer); // constructor should only do what is neccessary at the creation of the object
	void addItem(std::shared_ptr <Item> item);
	void removeItem(std::shared_ptr <Item> item);
	void setID();
	double getOrderCost() const;
	bool getPaymentStatus() const;

	~Order();
public:
	void setPaymentStatus(bool status);
};

