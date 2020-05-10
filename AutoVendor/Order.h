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
	std::vector <std::pair <std::shared_ptr <Item>, int> > items; // array of pointers!!!  array<item, int> 
	double orderCost; // the final price of the cart
	bool paymentStatus; 
public:
	Order();
	Order(std::shared_ptr<User> orderer); // constructor should only do what is necessary at the creation of the object
	void addItem(std::shared_ptr <Item> item, int quanitity);
	void removeItem(std::pair <std::shared_ptr <Item>, int> itemReq);
	void handleRemoved(); 

	void setID();
	double getOrderCost() const;
	bool getPaymentStatus() const;
	bool operator == (const Order& rhs);
	~Order();
public:
	void setPaymentStatus(bool status);
};

