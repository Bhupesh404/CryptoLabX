#include "WalletSystem.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constructor
WalletSystem::WalletSystem()
    : nextWalletId(1001),
      nextTransactionId(5001) {
}

// =====================================================
// CREATE WALLET
// =====================================================

void WalletSystem::createWallet() {

    string ownerName;
    string username;
    string password;

    cout << "\n========== CREATE WALLET ==========\n";

    cout << "Enter owner name: ";
    cin >> ownerName;

    cout << "Enter username: ";
    cin >> username;

    // Check if username already exists
    if (findWalletByUsername(username) != nullptr) {
        cout << "\nUsername already exists.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    Wallet newWallet(
        nextWalletId,
        ownerName,
        username,
        password,
        1000.00
    );

    wallets.push_back(newWallet);

    cout << "\nWallet created successfully!\n";
    cout << "Wallet ID: " << nextWalletId << "\n";
    cout << "Username: " << username << "\n";
    cout << "Initial Balance: "
         << fixed << setprecision(2)
         << 1000.00
         << " COIN\n";

    nextWalletId++;
}

// =====================================================
// LOGIN
// =====================================================

void WalletSystem::login() {

    string username;
    string password;

    cout << "\n========== LOGIN ==========\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    Wallet* wallet = findWalletByUsername(username);

    if (wallet != nullptr &&
        wallet->getPassword() == password) {

        cout << "\nLogin successful!\n";
        cout << "Welcome, "
             << wallet->getOwnerName()
             << "!\n";

        walletMenu(username);

    } else {

        cout << "\nInvalid username or password.\n";
    }
}

// =====================================================
// WALLET MENU
// =====================================================

void WalletSystem::walletMenu(const string& username) {

    int choice;

    while (true) {

        cout << "\n========================================\n";
        cout << "           WALLET MENU\n";
        cout << "========================================\n";
        cout << "Logged in as: " << username << "\n";
        cout << "----------------------------------------\n";
        cout << "1. Balance Inquiry\n";
        cout << "2. Transaction History\n";
        cout << "3. Transaction Request\n";
        cout << "4. Wallet Details\n";
        cout << "5. Logout\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {

            case 1:
                balanceInquiry();
                break;

            case 2:
                transactionHistory();
                break;

            case 3:
                transactionRequest();
                break;

            case 4:
                walletDetails();
                break;

            case 5:
                cout << "\nLogged out successfully.\n";
                return;

            default:
                cout << "\nInvalid choice.\n";
        }
    }
}

// =====================================================
// BALANCE INQUIRY
// =====================================================

void WalletSystem::balanceInquiry() {

    int walletId;

    cout << "\n========== BALANCE INQUIRY ==========\n";

    cout << "Enter Wallet ID: ";
    cin >> walletId;

    Wallet* wallet = findWalletById(walletId);

    if (wallet == nullptr) {

        cout << "\nWallet not found.\n";
        return;
    }

    cout << "\nWallet ID: "
         << wallet->getWalletId()
         << "\n";

    cout << "Owner: "
         << wallet->getOwnerName()
         << "\n";

    cout << "Balance: "
         << fixed << setprecision(2)
         << wallet->getBalance()
         << " COIN\n";
}

// =====================================================
// TRANSACTION HISTORY
// =====================================================

void WalletSystem::transactionHistory() {

    cout << "\n========== TRANSACTION HISTORY ==========\n";

    if (transactions.empty()) {

        cout << "No transactions available.\n";
        return;
    }

    for (const Transaction& transaction : transactions) {

        cout << "\nTransaction ID: "
             << transaction.getTransactionId()
             << "\n";

        cout << "Sender Wallet: "
             << transaction.getSenderWalletId()
             << "\n";

        cout << "Receiver Wallet: "
             << transaction.getReceiverWalletId()
             << "\n";

        cout << "Amount: "
             << fixed << setprecision(2)
             << transaction.getAmount()
             << " COIN\n";

        cout << "Status: "
             << transaction.getStatus()
             << "\n";

        cout << "----------------------------------------\n";
    }
}

// =====================================================
// TRANSACTION REQUEST
// =====================================================

void WalletSystem::transactionRequest() {

    int senderId;
    int receiverId;
    double amount;

    cout << "\n========== TRANSACTION REQUEST ==========\n";

    cout << "Enter Sender Wallet ID: ";
    cin >> senderId;

    cout << "Enter Receiver Wallet ID: ";
    cin >> receiverId;

    cout << "Enter Amount: ";
    cin >> amount;

    Wallet* sender = findWalletById(senderId);
    Wallet* receiver = findWalletById(receiverId);

    if (sender == nullptr || receiver == nullptr) {

        cout << "\nInvalid wallet ID.\n";
        return;
    }

    if (amount <= 0) {

        cout << "\nAmount must be greater than zero.\n";
        return;
    }

    if (sender->getBalance() < amount) {

        cout << "\nInsufficient balance.\n";
        return;
    }

    sender->subtractBalance(amount);
    receiver->addBalance(amount);

    Transaction transaction(
        nextTransactionId,
        senderId,
        receiverId,
        amount,
        "SUCCESS"
    );

    transactions.push_back(transaction);

    cout << "\nTransaction successful!\n";

    cout << "Transaction ID: "
         << nextTransactionId
         << "\n";

    cout << "Amount: "
         << fixed << setprecision(2)
         << amount
         << " COIN\n";

    nextTransactionId++;
}

// =====================================================
// WALLET DETAILS
// =====================================================

void WalletSystem::walletDetails() {

    int walletId;

    cout << "\n========== WALLET DETAILS ==========\n";

    cout << "Enter Wallet ID: ";
    cin >> walletId;

    Wallet* wallet = findWalletById(walletId);

    if (wallet == nullptr) {

        cout << "\nWallet not found.\n";
        return;
    }

    cout << "\nWallet ID: "
         << wallet->getWalletId()
         << "\n";

    cout << "Owner: "
         << wallet->getOwnerName()
         << "\n";

    cout << "Username: "
         << wallet->getUsername()
         << "\n";

    cout << "Balance: "
         << fixed << setprecision(2)
         << wallet->getBalance()
         << " COIN\n";
}

// =====================================================
// FIND WALLET BY ID
// =====================================================

Wallet* WalletSystem::findWalletById(int walletId) {

    for (Wallet& wallet : wallets) {

        if (wallet.getWalletId() == walletId) {
            return &wallet;
        }
    }

    return nullptr;
}

// =====================================================
// FIND WALLET BY USERNAME
// =====================================================

Wallet* WalletSystem::findWalletByUsername(
    const string& username) {

    for (Wallet& wallet : wallets) {

        if (wallet.getUsername() == username) {
            return &wallet;
        }
    }

    return nullptr;
}
