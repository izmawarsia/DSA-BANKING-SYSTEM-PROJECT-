#ifndef TRANSACTION_HISTORY_H
#define TRANSACTION_HISTORY_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Linked List Node for each transaction
struct Transaction {
    int accountNumber;
    string type; // Deposit / Withdraw / Transfer
    double amount;
    string timeStamp;
    Transaction* next;

    Transaction(int accNo, string t, double amt, string ts)
        : accountNumber(accNo), type(t), amount(amt), timeStamp(ts), next(nullptr) {}
};

class TransactionHistory {
private:
    Transaction* head;

    // Helper to get current date/time
    string getCurrentTime();

public:
    TransactionHistory();
    void recordTransaction(int accountNumber, string type, double amount);
    void showTransactionHistory();
};

#endif
