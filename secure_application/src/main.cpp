#include <iostream>
#include "WalletSystem.h"

using namespace std;

int main() {

    WalletSystem walletSystem;

    int choice;

    cout << "\n========================================\n";
    cout << "       CRYPTOCURRENCY WALLET\n";
    cout << "          LAB ASSIGNMENT 3\n";
    cout << "========================================\n";

    while (true) {

        cout << "\n========================================\n";
        cout << "1. Create Wallet\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {

            case 1:
                walletSystem.createWallet();
                break;

            case 2:
                walletSystem.login();
                break;

            case 3:
                cout << "\nThank you for using Cryptocurrency Wallet.\n";
                return 0;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}
