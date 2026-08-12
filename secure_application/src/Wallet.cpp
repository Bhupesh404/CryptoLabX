#include "Wallet.h"

Wallet::Wallet(int id,
               const std::string& owner,
               const std::string& user,
               const std::string& pass,
               double initialBalance)
    : walletId(id),
      ownerName(owner),
      username(user),
      password(pass),
      balance(initialBalance) {
}

int Wallet::getWalletId() const {
    return walletId;
}

std::string Wallet::getOwnerName() const {
    return ownerName;
}

std::string Wallet::getUsername() const {
    return username;
}

std::string Wallet::getPassword() const {
    return password;
}

double Wallet::getBalance() const {
    return balance;
}

void Wallet::addBalance(double amount) {
    balance += amount;
}

bool Wallet::subtractBalance(double amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }

    balance -= amount;
    return true;
}
