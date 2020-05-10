#include "Order.h"

Order::Order()
{

}

Order::Order(std::shared_ptr<User> orderer)
{
	this->orderer = orderer;
	// setId();
	// setPayment()
}

void Order::addItem(std::shared_ptr<Item> item, int quantity)
{
	// check if a similar item exists
	// just increase the count
	auto it = find_if(items.begin(), items.end(),
		[item](std::pair <std::shared_ptr<Item>, int > i) {return i.first->getName() == item->getName(); });

	if (it != items.end())// if u find the item in the list already
		it->second += quantity; // just increase the quantity
	else
		items.push_back({ item,quantity }); // push back the new pair
	//if not push it back to the array

}

void Order::removeItem(std::pair<std::shared_ptr<Item>, int> itemReq)
{
	// take the current quantity that the item has in the order
	int toBeReturned = itemReq.second;
	// return that quantity to the stock 
	itemReq.first->storeItem(toBeReturned); // takes the value to be returned and adds it back to stock

	// set the item count in the order to 0 
	itemReq.second = 0;
	// delete it, from the order
	handleRemoved();

}

void Order::handleRemoved()
{

	// check if there is an element with quantity = 0 ;
	auto f = find_if(items.begin(), items.end(),
		[](std::pair <std::shared_ptr <Item>, int > i) {return i.second == 0; });

	// should go all over the array
	while (f != items.end() &&
		items.size() > 0) {
		// erase it from the array 
		items.erase(f);
		f = find_if(items.begin(), items.end(),
			[](std::pair <std::shared_ptr <Item>, int > i) {return i.second == 0; });
	}

}

void Order::setID()
{
	this->orderID = " ";
}

double Order::getOrderCost() const
{
	double cost = 0;

	for (auto& item : items) { //  for int i =0; i< items.size(); i++
		cost += item.first->getPrice() * item.second;
	}
	return cost;
}

bool Order::getPaymentStatus() const
{
	return paymentStatus;
}

bool Order::operator==(const Order& rhs)
{
	if (orderID == rhs.orderID) return true;
	else return false;

}

Order::~Order()
{
}

void Order::setPaymentStatus(bool status)
{
	paymentStatus = status;
}




