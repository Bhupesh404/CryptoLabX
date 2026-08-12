#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// -----------------------------
// Data Structures
// -----------------------------

struct Transaction {
    int transactionId;
    string senderWallet;
    string receiverWallet;
    double amount;
    string status;
};

struct Wallet {
    int walletId;
    string ownerName;
    string password;
    double balance;
};

// -----------------------------
// Global Data
// -----------------------------

vector<Wallet> wallets;
vector<Transaction> transactions;

int nextWalletId = 1001;
int nextTransactionId = 5001;

// -----------------------------
// Function Declarations
// -----------------------------

void createWallet();
void transactionHistory();
void balanceInquiry();
void transactionRequest();
void displayMenu();

// -----------------------------
// Create Wallet
// -----------------------------

void createWallet() {
    Wallet newWallet;

    cout << "\n========== CREATE WALLET ==========\n";

    cout << "Enter owner name: ";
    cin >> newWallet.ownerName;

    cout << "Enter password: ";
    cin >> newWallet.password;

    newWallet.walletId = nextWalletId++;
    newWallet.balance = 1000.00;

    wallets.push_back(newWallet);

    cout << "\nWallet created successfully!\n";
    cout << "Wallet ID: " << newWallet.walletId << endl;
    cout << "Initial Balance: "
         << fixed << setprecision(2)
         << newWallet.balance << " COIN\n";
}

// -----------------------------
// Balance Inquiry
// -----------------------------

void balanceInquiry() {
    int walletId;

    cout << "\n========== BALANCE INQUIRY ==========\n";
    cout << "Enter Wallet ID: ";
    cin >> walletId;

    for (const auto& wallet : wallets) {
        if (wallet.walletId == walletId) {
            cout << "\nWallet ID: " << wallet.walletId << endl;
            cout << "Owner: " << wallet.ownerName << endl;
            cout << "Balance: "
                 << fixed << setprecision(2)
                 << wallet.balance << " COIN\n";
            return;
        }
    }

    cout << "\nWallet not found.\n";
}

// -----------------------------
// Transaction Request
// -----------------------------

void transactionRequest() {
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

    Wallet* sender = nullptr;
    Wallet* receiver = nullptr;

    for (auto& wallet : wallets) {
        if (wallet.walletId == senderId) {
            sender = &wallet;
        }

        if (wallet.walletId == receiverId) {
            receiver = &wallet;
        }
    }

    if (sender == nullptr || receiver == nullptr) {
        cout << "\nInvalid wallet ID.\n";
        return;
    }

    if (amount <= 0) {
        cout << "\nInvalid transaction amount.\n";
        return;
    }

    if (sender->balance < amount) {
        cout << "\nInsufficient balance.\n";
        return;
    }

    sender->balance -= amount;
    receiver->balance += amount;

    Transaction transaction;

    transaction.transactionId = nextTransactionId++;
    transaction.senderWallet = to_string(senderId);
    transaction.receiverWallet = to_string(receiverId);
    transaction.amount = amount;
    transaction.status = "SUCCESS";

    transactions.push_back(transaction);

    cout << "\nTransaction successful!\n";
    cout << "Transaction ID: "
         << transaction.transactionId << endl;
    cout << "Amount: "
         << fixed << setprecision(2)
         << amount << " COIN\n";
}

// -----------------------------
// Transaction History
// -----------------------------

void transactionHistory() {
    cout << "\n========== TRANSACTION HISTORY ==========\n";

    if (transactions.empty()) {
        cout << "No transactions available.\n";
        return;
    }

    for (const auto& transaction : transactions) {
        cout << "\nTransaction ID: "
             << transaction.transactionId << endl;

        cout << "Sender Wallet: "
             << transaction.senderWallet << endl;

        cout << "Receiver Wallet: "
             << transaction.receiverWallet << endl;

        cout << "Amount: "
             << fixed << setprecision(2)
             << transaction.amount << " COIN\n";

        cout << "Status: "
             << transaction.status << endl;

        cout << "----------------------------------------\n";
    }
}

// -----------------------------
// Display Menu
// -----------------------------

void displayMenu() {
    cout << "\n========================================\n";
    cout << "       CRYPTOCURRENCY WALLET\n";
    cout << "========================================\n";
    cout << "1. Create Wallet\n";
    cout << "2. Transaction History\n";
    cout << "3. Balance Inquiry\n";
    cout << "4. Transaction Request\n";
    cout << "5. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

// -----------------------------
// Main Function
// -----------------------------

int main() {
    int choice;

    cout << "\nWelcome to Cryptocurrency Wallet!\n";

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {

            case 1:
                createWallet();
                break;

            case 2:
                transactionHistory();
                break;

            case 3:
                balanceInquiry();
                break;

            case 4:
                transactionRequest();
                break;

            case 5:
                cout << "\nThank you for using Cryptocurrency Wallet.\n";
                return 0;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}
