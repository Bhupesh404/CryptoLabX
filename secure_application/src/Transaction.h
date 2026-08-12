#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    int transactionId;
    int senderWalletId;
    int receiverWalletId;
    double amount;
    std::string status;

public:
    Transaction(int id,
                int sender,
                int receiver,
                double transactionAmount,
                const std::string& transactionStatus);

    int getTransactionId() const;
    int getSenderWalletId() const;
    int getReceiverWalletId() const;
    double getAmount() const;
    std::string getStatus() const;
};

#endif
