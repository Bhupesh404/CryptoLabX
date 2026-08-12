#ifndef WALLET_H
#define WALLET_H

#include <string>

class Wallet {
private:
    int walletId;
    std::string ownerName;
    std::string username;
    std::string password;
    double balance;

public:
    Wallet(int id,
           const std::string& owner,
           const std::string& user,
           const std::string& pass,
           double initialBalance);

    int getWalletId() const;
    std::string getOwnerName() const;
    std::string getUsername() const;
    std::string getPassword() const;
    double getBalance() const;

    void addBalance(double amount);
    bool subtractBalance(double amount);
};

#endif
