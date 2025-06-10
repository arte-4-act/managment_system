#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Structure to represent a customer request
struct Customer {
    string name;
    int requestNumber;

    Customer(string n, int num) : name(n), requestNumber(num) {}
};

// Class representing the customer service system using a queue
class CustomerService {
private:
    queue<Customer> requests; // Queue to manage customer requests
    int currentRequestNumber; // Track the current request number

public:
    CustomerService() : currentRequestNumber(1) {}

    // Simulate a customer arriving and enqueuing their request
    void enqueueCustomer(string name) {
        Customer newCustomer(name, currentRequestNumber++);
        requests.push(newCustomer);
        cout << "Customer " << newCustomer.name << " has arrived and queued with request number " << newCustomer.requestNumber << ".\n";
    }

    // Simulate completing service for the next customer in queue
    void dequeueCustomer() {
        if (requests.empty()) {
            cout << "No customers in the queue.\n";
        }
        else {
            Customer nextCustomer = requests.front();
            requests.pop();
            cout << "Completed service for customer " << nextCustomer.name << " with request number " << nextCustomer.requestNumber << ".\n";
        }
    }

    // Display the current queue of customer requests
    void displayQueue() {
        if (requests.empty()) {
            system("cls"); // Clear the screen
            cout << "The customer queue is empty.\n";
        }
        else {
            system("cls"); // Clear the screen
            queue<Customer> tempQueue = requests;
            cout << "Current customer queue:\n";
            while (!tempQueue.empty()) {
                Customer currentCustomer = tempQueue.front();
                tempQueue.pop();
                cout << "Request Number: " << currentCustomer.requestNumber << ", Customer Name: " << currentCustomer.name << endl;
            }
        }
    }
};

int main() {
    CustomerService service;

    int choice;
    string name;

    do {
        cout << "\nCustomer Service Menu:\n";
        cout << "1. Arrive Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Customer Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls"); // Clear the screen 
            cout << "Enter customer name: ";
            cin >> name;
            system("cls"); // Clear the screen
            service.enqueueCustomer(name); // Call enqueueCustomer method of CustomerService class
            break;
        case 2:
            system("cls"); // Clear the screen
            service.dequeueCustomer(); // Call dequeueCustomer method of CustomerService class
            break;
        case 3:
            system("cls"); // Clear the screen 
            service.displayQueue(); // Call displayQueue method of CustomerService class
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
