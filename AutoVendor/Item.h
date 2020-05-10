#pragma once

#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
	string name;
	double price;
	int inStock;
	string sellingShop;

public:
	// default
	Item();
	// overloaded
	Item(string name, double price, int inStock, string sellingShop);
	// setters and getters
	string getName() const;
	string getShop() const;
	double getPrice() const;
	int getStock() const;

	void setName();
	void setPrice();
	void storeItem(int quantity);
	void buyItem(int quantity);
	bool operator == (const Item& rhs);
	friend ostream& operator << (ostream & output, const Item & item);

};

