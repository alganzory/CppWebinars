#include <iostream>
#include <vector>
using namespace std;

/*
  Browser:
  Allow the user to create new tabs, change their info, close	
	- The container and the info are DYNAMIC.
	- dynamically allocate an array, initialise the size to 0;
	- add new tab, increase the size by 1, array (size +1 );
	- reallocate the array to a larger size.
	- creating an array of a bigger size based on the user request
	- copying the elements of the previous array into the bigger one
	- deleting the previous array, since its doing nothing anymore
	- adding the user's new tab into the new array!
*/

class Browser2 {
public:
	string defaultNewTab;
	int tabsCount;
	string* tabs;  

	int capacity;	// to know if our current array is enough for 
					// the user request

	Browser2() {
		cout << "Welcome to Doodle Chrome 2.0, Here are your open tabs:\n";
		defaultNewTab = "Google.com";
		tabsCount = 0;
		capacity = 0;
		tabs = nullptr;
		displayTabs();
	}

	void displayTabs() {

		if (tabs == nullptr) cout << "\nNo tabs open.\n";
		else {
			for (int i = 0; i < tabsCount; i++) {
				cout << i + 1 << "- " << tabs[i] << "\t";
			}
			cout << "\n";
		}
	}


	void addTab() {
		tabsCount++; //2 => 0 , 1
		//3 => 0, 1, 2


		if (capacity <= tabsCount) {
			capacity = 2 * tabsCount;
			//reserving copies of the previous tabs, before moving them
			string* temp = new string[tabsCount];

			/*tabs = 1, 2, 3
				new tab = 4;*/


			for (int i = 0; i < tabsCount-1; i++) {
				temp[i] = tabs[i];
			}
			// deleting the previous tabs, since I have already copied them
			delete [] tabs;
			// creating the bigger array ( the actual intent) 
			tabs = new string[capacity];


			for (int i = 0; i < tabsCount-1; i++) {
				tabs[i] = temp[i];
			}

			delete [] temp;

		}

		tabs[tabsCount-1] = defaultNewTab;

	}


	void changeTab(int tabNumber) {
		cout << "What website do you want to visit?\n";
		string website{};
		cin >> website;
		cin.ignore();
		tabs[tabNumber - 1] = website;
		cout << "Website changed successfully!\n";
	}

	void deleteTab(int tabNumber) {
		for (int i = tabNumber - 1; i < tabsCount - 1; i++) {
			tabs[i] = tabs[i + 1];
		}
		tabsCount--;
		cout << "Tab closed successfully\n";
	}
};

void changeTabMenu(Browser2& doodleChrome) {

	cout << "Enter the number of tab you want to change:";
	int tabNumber = 0;
	cin >> tabNumber;
	cin.ignore();
	doodleChrome.changeTab(tabNumber);
}

void closeTabMenu(Browser2& doodleChrome) {

	cout << "Enter the number of tab you want to close:";
	int tabNumber = 0;
	cin >> tabNumber;
	cin.ignore();
	doodleChrome.deleteTab(tabNumber);
}

void mainMenu(Browser2& doodleChrome) {
	while (true) {
		cout << "Press N to add a new tab or C to change the website or D to close tab\n";
		char newTab = '0';
		cin >> newTab;
		cin.ignore();
		if (newTab == 'n' || newTab == 'N') {
			doodleChrome.addTab();
			cout << "New tab created successfully\n\n";
		}
		else if (newTab == 'c' || newTab == 'C') changeTabMenu(doodleChrome);
		else closeTabMenu(doodleChrome);

		doodleChrome.displayTabs();

	}
}

int main() {
	Browser2 doodleChrome;
	mainMenu(doodleChrome);
}
