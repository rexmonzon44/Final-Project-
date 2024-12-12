#include "AllPurchases.h"
#include <iostream>
#include <fstream>
using namespace std;

void AllPurchases::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    purchases.clear();
    Purchase temp;
    while (file >> temp.accountNumber >> temp.item >> temp.date >> temp.amount) {
        purchases.push_back(temp);
    }
    file.close();
}

void AllPurchases::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    for (const auto& purchase : purchases) {
        file << purchase.accountNumber << ' ' << purchase.item << ' ' << purchase.date << ' ' << purchase.amount << '\n';
    }
    file.close();
}

void AllPurchases::printCustomerPurchases(int accountNumber) const {
    double totalSpent = 0.0;
    cout << "Purchases for Account #" << accountNumber << ":\n";
    for (const auto& purchase : purchases) {
        if (purchase.accountNumber == accountNumber) {
            cout << "- " << purchase.item << " on " << purchase.date << " for $" << purchase.amount << endl;
            totalSpent += purchase.amount;
        }
    }
    cout << "Total Spent: $" << totalSpent << endl;
}

void AllPurchases::addNewPurchase() {
    Purchase newPurchase;
    cout << "Enter Account Number: ";
    cin >> newPurchase.accountNumber;
    cout << "Enter Item: ";
    cin >> newPurchase.item;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> newPurchase.date;
    cout << "Enter Amount: ";
    cin >> newPurchase.amount;

    purchases.push_back(newPurchase);
    cout << "Purchase added successfully." << endl;
}

void AllPurchases::addMultiplePurchases() {
    addNewPurchase();
    char choice;
    cout << "Add another purchase? (y/n): ";
    cin >> choice;
    if (tolower(choice) == 'y') {
        addMultiplePurchases();
    }
}
