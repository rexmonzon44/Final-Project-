#include "AllCustomers.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void AllCustomers::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    customers.clear();
    Customer temp;
    while (file >> temp.firstName >> temp.lastName >> temp.accountNumber >> temp.address >> temp.city >> temp.state >> temp.zipCode >> temp.phoneNumber) {
        customers.push_back(temp);
    }
    file.close();
}

void AllCustomers::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    for (const auto& customer : customers) {
        file << customer.firstName << ' ' << customer.lastName << ' ' << customer.accountNumber << ' '
             << customer.address << ' ' << customer.city << ' ' << customer.state << ' '
             << customer.zipCode << ' ' << customer.phoneNumber << '\n';
    }
    file.close();
}

void AllCustomers::printAllCustomers() const {
    for (const auto& customer : customers) {
        cout << customer.accountNumber << ": " << customer.firstName << " " << customer.lastName << endl;
    }
}

void AllCustomers::sortCustomers() {
    sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b) {
        return a.lastName < b.lastName;
    });
    cout << "Customers sorted by last name." << endl;
}

void AllCustomers::printSpecificCustomer(int accountNumber) const {
    auto it = find_if(customers.begin(), customers.end(), [accountNumber](const Customer& c) {
        return c.accountNumber == accountNumber;
    });

    if (it != customers.end()) {
        cout << "Customer Details:\n";
        cout << "Name: " << it->firstName << " " << it->lastName << endl;
        cout << "Address: " << it->address << ", " << it->city << ", " << it->state << " " << it->zipCode << endl;
        cout << "Phone: " << it->phoneNumber << endl;
    } else {
        cout << "Customer not found." << endl;
    }
}

void AllCustomers::addNewCustomer() {
    Customer newCustomer;
    cout << "Enter First Name: ";
    cin >> newCustomer.firstName;
    cout << "Enter Last Name: ";
    cin >> newCustomer.lastName;
    cout << "Enter Account Number: ";
    cin >> newCustomer.accountNumber;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, newCustomer.address);
    cout << "Enter City: ";
    cin >> newCustomer.city;
    cout << "Enter State: ";
    cin >> newCustomer.state;
    cout << "Enter Zip Code: ";
    cin >> newCustomer.zipCode;
    cout << "Enter Phone Number: ";
    cin >> newCustomer.phoneNumber;

    customers.push_back(newCustomer);
    cout << "Customer added successfully." << endl;
}

void AllCustomers::addMultipleCustomers() {
    addNewCustomer();
    char choice;
    cout << "Add another customer? (y/n): ";
    cin >> choice;
    if (tolower(choice) == 'y') {
        addMultipleCustomers();
    }
}

void AllCustomers::updateCustomer(int accountNumber) {
    auto it = find_if(customers.begin(), customers.end(), [accountNumber](const Customer& c) {
        return c.accountNumber == accountNumber;
    });

    if (it != customers.end()) {
        cout << "Updating Customer: " << it->firstName << " " << it->lastName << endl;
        cout << "Enter New First Name: ";
        cin >> it->firstName;
        cout << "Enter New Last Name: ";
        cin >> it->lastName;
        cout << "Enter New Address: ";
        cin.ignore();
        getline(cin, it->address);
        cout << "Enter New City: ";
        cin >> it->city;
        cout << "Enter New State: ";
        cin >> it->state;
        cout << "Enter New Zip Code: ";
        cin >> it->zipCode;
        cout << "Enter New Phone Number: ";
        cin >> it->phoneNumber;

        cout << "Customer updated successfully." << endl;
    } else {
        cout << "Customer not found." << endl;
    }
}

void AllCustomers::deleteCustomer(int accountNumber) {
    auto it = remove_if(customers.begin(), customers.end(), [accountNumber](const Customer& c) {
        return c.accountNumber == accountNumber;
    });

    if (it != customers.end()) {
        customers.erase(it, customers.end());
        cout << "Customer deleted successfully." << endl;
    } else {
        cout << "Customer not found." << endl;
    }
}



