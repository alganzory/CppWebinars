#include "Category.h"

Category::Category()
{
}

Category::Category(string name):
	name (name)
{
}

string Category::getName() const
{
	return name;
}

void Category::addItem(shared_ptr<Item> newItem)
{
	items.push_back(newItem);
}

void Category::removeItem(shared_ptr<Item> itemReq)
{
	// find where the element is in the list or the vector
	// use the index of that item to delete it!
	items.erase(find(items.begin(), items.end(), itemReq));


}

shared_ptr<Item> Category::retItem(int index)
{

	// exception
	// handle errors that may happen during runtime 
	// something u cannot control

	if (index <0 || index > items.size() - 1) {
		cout << "Not an available item";
		return nullptr;
	}

	return items[index];
}

void Category::listItem()
{
	for (auto& item : items) {
		std::cout << *item << std::endl;
	}
}

ostream& operator<<(ostream& output, const Category& category)
{
	output << category.name << endl;

	// print all items
	if (category.items.empty()) return output;

	int counter = 0;

	for (auto& item : category.items) {
		output << ++ counter << "- " << *item << endl;
	}
	return output;
}
