#ifndef ALLCUSTOMERS_H
#define ALLCUSTOMERS_H

#include <string>
#include <vector>
using namespace std;

struct Customer {
    string firstName;
    string lastName;
    int accountNumber;
    string address;
    string city;
    string state;
    string zipCode;
    string phoneNumber;
};

class AllCustomers {
private:
    vector<Customer> customers;

public:
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;
    void printAllCustomers() const;
    void sortCustomers();
    void printSpecificCustomer(int accountNumber) const;
    void addNewCustomer();
    void addMultipleCustomers();
    void updateCustomer(int accountNumber);
    void deleteCustomer(int accountNumber);
};

#endif
