#include "Transaction.h"

Transaction::Transaction(int id,
                         int sender,
                         int receiver,
                         double transactionAmount,
                         const std::string& transactionStatus)
    : transactionId(id),
      senderWalletId(sender),
      receiverWalletId(receiver),
      amount(transactionAmount),
      status(transactionStatus) {
}

int Transaction::getTransactionId() const {
    return transactionId;
}

int Transaction::getSenderWalletId() const {
    return senderWalletId;
}

int Transaction::getReceiverWalletId() const {
    return receiverWalletId;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getStatus() const {
    return status;
}
