#include "Item.h"

Item::Item()
{

}

Item::Item(string name, double price, int inStock, string sellingShop):
	name (name), price (price), inStock (inStock), sellingShop (sellingShop)
{
}

string Item::getName() const
{
	return name;
}

string Item::getShop() const
{
	return sellingShop;
}

double Item::getPrice() const
{
	return price;
}

int Item::getStock() const
{
	return inStock;
}

void Item::setName()
{
	this->name = name;
}

void Item::setPrice()
{
	this->price = price;
}

void Item::storeItem(int quantity)
{
	inStock += quantity;
}

void Item::buyItem(int quantity)
{
	// check
	// exception
	if (inStock >= quantity)
		inStock -= quantity;
	else cout << "Not enough quantity" << endl;
}

bool Item::operator==(const Item& rhs)
{
	return (this->getName() == rhs.getName());
}

ostream& operator<<(ostream& output, const Item& item)
{
	output << item.name << "\t" << item.price << '\t' << item.inStock << '\n';
	return output;
}
