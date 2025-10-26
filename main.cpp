#include<iostream>
using namespace std;

void accountManagement();   // Step 1
// void transactionHistory();  // Step 2
// void undoOperations();      // Step 3
// void serviceQueue();        // Step 4
// void loanProcessing();      // Step 5

int main() {
    int choice;

    do {
        cout << "\n======================================";
        cout << "\n      BANK MANAGEMENT SYSTEM MENU     ";
        cout << "\n======================================";
        cout << "\n1. Customer Account Management (Hashing)";
        cout << "\n2. Transaction History (Linked List)";
        cout << "\n3. Undo Operations (Stack)";
        cout << "\n4. Customer Service Queue (Queue)";
        cout << "\n5. Loan Request Handling (Priority Queue)";
        cout << "\n6. Exit";
        cout << "\n======================================";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: accountManagement(); break;
            // case 2: transactionHistory(); break;
            // case 3: undoOperations(); break;
            // case 4: serviceQueue(); break;
            // case 5: loanProcessing(); break;
            case 6: cout << "\nExiting System. Thank You!\n"; break;
            default: cout << "\nInvalid Option! Try Again.\n"; break;
        }

    } while (choice != 6);

    return 0;
}