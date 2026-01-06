#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    // Prices of items
    const double priceCola      = 1.50;
    const double priceWater     = 1.00;
    const double priceCrisps    = 0.80;
    const double priceChocolate = 1.20;
    const double priceSandwich  = 2.50;

    // Stock for each item
    int stockCola      = 3;
    int stockWater     = 5;
    int stockCrisps    = 4;
    int stockChocolate = 2;
    int stockSandwich  = 1;

    int choice = -1;
    double money = 0.0;
    double change = 0.0;

    cout << "=============================\n";
    cout << "        VENDING MACHINE      \n";
    cout << "=============================\n";

    while (true) {
        // Display menu + stock (formatted nicely)
        cout << fixed << setprecision(2);
        cout << "\nMenu:\n";
        cout << "1. Cola        - £" << priceCola      << " (Stock: " << stockCola      << ")\n";
        cout << "2. Water       - £" << priceWater     << " (Stock: " << stockWater     << ")\n";
        cout << "3. Crisps      - £" << priceCrisps    << " (Stock: " << stockCrisps    << ")\n";
        cout << "4. Chocolate   - £" << priceChocolate << " (Stock: " << stockChocolate << ")\n";
        cout << "5. Sandwich    - £" << priceSandwich  << " (Stock: " << stockSandwich  << ")\n";
        cout << "0. Exit\n";

        cout << "\nEnter item number (0 to exit): ";
        cin >> choice;

        //  Input validation for choice (handles letters, etc.)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Thanks for using the vending machine. Goodbye!\n";
            break;
        }

        double selectedPrice = 0.0;
        string selectedName;
        int* selectedStock = nullptr; // pointer to the correct stock item

        // Match choice to item + stock
        if (choice == 1) {
            selectedPrice = priceCola;
            selectedName = "Cola";
            selectedStock = &stockCola;
        }
        else if (choice == 2) {
            selectedPrice = priceWater;
            selectedName = "Water";
            selectedStock = &stockWater;
        }
        else if (choice == 3) {
            selectedPrice = priceCrisps;
            selectedName = "Crisps";
            selectedStock = &stockCrisps;
        }
        else if (choice == 4) {
            selectedPrice = priceChocolate;
            selectedName = "Chocolate";
            selectedStock = &stockChocolate;
        }
        else if (choice == 5) {
            selectedPrice = priceSandwich;
            selectedName = "Sandwich";
            selectedStock = &stockSandwich;
        }
        else {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        // Check stock before asking for money
        if (*selectedStock <= 0) {
            cout << "Sorry, " << selectedName << " is OUT OF STOCK.\n";
            continue;
        }

        // Ask user to insert money
        cout << "You selected: " << selectedName
             << " (Price: £" << selectedPrice << ")\n";
        cout << "Insert money: ";
        cin >> money;

        //  Input validation for money (handles letters + negative)
        if (cin.fail() || money < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid money amount. Please enter a valid number.\n";
            continue;
        }

        if (money < selectedPrice) {
            cout << "Not enough money. Refunding £"
                 << fixed << setprecision(2) << money << ".\n";
            continue;
        }

        // Calculate change + dispense item
        change = money - selectedPrice;
        *selectedStock = *selectedStock - 1; // decrease stock

        cout << "Dispensing " << selectedName << "...\n";
        cout << "Your change: £" << fixed << setprecision(2)
             << change << "\n";
        cout << selectedName << " remaining: " << *selectedStock << "\n";
    }

    return 0;
}

