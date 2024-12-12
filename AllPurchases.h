#ifndef ALLPURCHASES_H
#define ALLPURCHASES_H

#include <string>
#include <vector>
using namespace std;

struct Purchase {
    int accountNumber;
    string item;
    string date;
    double amount;
};

class AllPurchases {
private:
    vector<Purchase> purchases;

public:
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;
    void printCustomerPurchases(int accountNumber) const;
    void addNewPurchase();
    void addMultiplePurchases();
};

#endif

