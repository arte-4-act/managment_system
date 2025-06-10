#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Structure to represent an item in the inventory
struct Item {
    string name;
    int quantity;

    Item(string n, int q) : name(n), quantity(q) {}
};

// Class representing the inventory management system using a stack
class Inventory {
private:
    stack<Item> items; // Stack to store items in the inventory

public:
    // Add a new item to the inventory
    void addItem(string name, int quantity) {
        Item newItem(name, quantity);
        items.push(newItem); // Push the new item onto the stack
        cout << "Added " << quantity << " of " << name << " to the inventory.\n";
    }

    // Sell an item from the inventory
    void sellItem() {
        if (items.empty()) {
            cout << "No items in the inventory to sell.\n";
        }
        else {
            Item soldItem = items.top(); // Get the top item from the stack
            items.pop(); // Remove the top item from the stack
            cout << "Sold " << soldItem.quantity << " of " << soldItem.name << ".\n";
        }
    }

    // Display the current stock level
    void displayStock() {
        if (items.empty()) {
            cout << "The inventory is empty.\n";
        }
        else {
            stack<Item> tempStack = items; // Create a temporary stack to iterate over items
            cout << "Current stock levels:\n";
            while (!tempStack.empty()) {
                Item currentItem = tempStack.top(); // Get the top item from the temporary stack
                tempStack.pop(); // Remove the top item from the temporary stack
                cout << currentItem.name << ": " << currentItem.quantity << endl; // Display item details
            }
        }
    }
};

int main() {
    Inventory inventory;

    int choice;
    string name;
    int quantity;

    do {
        cout << "\nInventory Management Menu:\n";
        cout << "1. Add Item to Inventory\n";
        cout << "2. Sell Item from Inventory\n";
        cout << "3. Display Stock Level\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls"); // Clear the screen
            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter item quantity: ";
            cin >> quantity;
            system("cls"); // Clear the screen
            inventory.addItem(name, quantity); // Call addItem method of Inventory class
            break;
        case 2:
            system("cls"); // Clear the screen
            inventory.sellItem(); // Call sellItem method of Inventory class
            break;
        case 3:
            system("cls"); // Clear the screen
            inventory.displayStock(); // Call displayStock method of Inventory class
            break;
        case 4:
            system("cls"); // Clear the screen
            cout << "Exiting the program.\n";
            break;
        default:
            system("cls"); // Clear the screen
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
