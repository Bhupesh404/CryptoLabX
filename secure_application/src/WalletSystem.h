#ifndef WALLETSYSTEM_H
#define WALLETSYSTEM_H

#include <vector>
#include "Wallet.h"
#include "Transaction.h"

class WalletSystem {
private:
    std::vector<Wallet> wallets;
    std::vector<Transaction> transactions;

    int nextWalletId;
    int nextTransactionId;

    Wallet* findWalletById(int walletId);
    Wallet* findWalletByUsername(const std::string& username);

public:
    WalletSystem();

    void createWallet();
    void login();

private:
    void walletMenu(const std::string& username);
    void balanceInquiry();
    void transactionHistory();
    void transactionRequest();
    void walletDetails();
};

#endif
