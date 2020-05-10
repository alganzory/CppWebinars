#pragma once
#include "Item.h"
#include <vector>
#include <memory.h>
using namespace std;


class Category
{
private: 
	// a list of items
	vector <shared_ptr <Item> > items;
	// name 
	string name;

public: 

	Category();
	Category(string name);

	string getName() const;
	void addItem(shared_ptr <Item> newItem);
	void removeItem(shared_ptr <Item> itemReq);
	shared_ptr <Item > retItem(int index);
	friend ostream& operator << (ostream& output, const Category& category);
	void listItem();
};



