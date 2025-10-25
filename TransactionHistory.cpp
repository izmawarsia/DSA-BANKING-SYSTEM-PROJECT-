#include "TransactionHistory.h"

// Constructor
TransactionHistory::TransactionHistory() {
    head = nullptr;
}

// Function to get the current date and time
string TransactionHistory::getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string t(dt);
    t.pop_back(); // remove newline
    return t;
}

// Function to record a new transaction
void TransactionHistory::recordTransaction(int accountNumber, string type, double amount) {
    string timestamp = getCurrentTime();
    Transaction* newTransaction = new Transaction(accountNumber, type, amount, timestamp);

    if (head == nullptr) {
        head = newTransaction;
    } else {
        Transaction* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newTransaction;
    }

    cout << "\n--------------------------------------------\n";
    cout << "Transaction Recorded:\n";
    cout << "[Account " << accountNumber << "] ";
    if (type == "Deposit") cout << "+";
    else if (type == "Withdraw") cout << "-";
    cout << amount << " (" << type << ")\n";
    cout << "🕒 " << timestamp << endl;
    cout << "--------------------------------------------\n";
}

// Function to display all recorded transactions
void TransactionHistory::showTransactionHistory() {
    cout << "\n========== TRANSACTION HISTORY ==========\n";

    if (head == nullptr) {
        cout << "No transactions yet.\n";
        return;
    }

    Transaction* temp = head;
    while (temp != nullptr) {
        cout << "[Account " << temp->accountNumber << "] ";
        if (temp->type == "Deposit") cout << "+";
        else if (temp->type == "Withdraw") cout << "-";
        cout << temp->amount << " (" << temp->type << ") | " << temp->timeStamp << endl;
        temp = temp->next;
    }

    cout << "=========================================\n";
}
