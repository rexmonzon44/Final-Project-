#include "AllCustomers.h"
#include "AllPurchases.h"
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\n--- Rex Monzon Apparel Clothing ---\n";
    cout << "1. Print all customers\n";
    cout << "2. Sort customers by last name\n";
    cout << "3. View a customer's information and purchases\n";
    cout << "4. Add a new customer\n";
    cout << "5. Add multiple customers\n";
    cout << "6. Update customer information\n";
    cout << "7. Delete a customer\n";
    cout << "8. Add a new purchase\n";
    cout << "9. Add multiple purchases\n";
    cout << "10. Save data to file\n";
    cout << "11. Exit\n";
    cout << "Select an option: ";
}

int main() {
    AllCustomers allCustomers;
    AllPurchases allPurchases;

    string customerFile = "customers.txt";
    string purchaseFile = "purchases.txt";

    allCustomers.loadFromFile(customerFile);
    allPurchases.loadFromFile(purchaseFile);

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            allCustomers.printAllCustomers();
            break;
        case 2:
            allCustomers.sortCustomers();
            break;
        case 3: {
            int accountNumber;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            allCustomers.printSpecificCustomer(accountNumber);
            allPurchases.printCustomerPurchases(accountNumber);
            break;
        }
        case 4:
            allCustomers.addNewCustomer();
            break;
        case 5:
            allCustomers.addMultipleCustomers();
            break;
        case 6: {
            int accountNumber;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            allCustomers.updateCustomer(accountNumber);
            break;
        }
        case 7: {
            int accountNumber;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            allCustomers.deleteCustomer(accountNumber);
            break;
        }
        case 8:
            allPurchases.addNewPurchase();
            break;
        case 9:
            allPurchases.addMultiplePurchases();
            break;
        case 10:
            allCustomers.saveToFile(customerFile);
            allPurchases.saveToFile(purchaseFile);
            cout << "Data saved successfully." << endl;
            break;
        case 11:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 11);

    return 0;
}
