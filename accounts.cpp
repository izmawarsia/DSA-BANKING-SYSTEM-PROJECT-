#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Account {
    int accNo;
    string name;
    double balance;
public:
Account(){ }
Account(int accNo , string name , double balance){
    this->accNo = accNo;
    this->name = name;
    this->balance = balance;
}
int getAccountNo() const{
return accNo;
}
string getName() const{
    return name;
}
double getBalance() const{
    return balance;
}
void displayAccount() const{
cout <<"\n---------------------------------------------";
cout <<"\nAccount Number: " << accNo <<endl;
cout <<"\nAccount Holder Name: " << name <<endl;
cout <<"\nAccount Current Balance in (Rs.): " << balance <<endl;
cout<<"----------------------------------------------" <<endl;
}
};
class BankSystem{
    private:
    unordered_map<int,Account> accounts;
    int nextAccNo = 1001;
    public:
    void createAccount(){
        string name;
        double balance;
        cin.ignore();
        cout<<"Enter Account Holder Name:";
        getline(cin,name);
        cout <<"Enter Initial Deposit Amount in (Rs.):";
        cin>>balance;
        int accNo = nextAccNo++ ;
        accounts[accNo] = Account(accNo,name,balance);
        cout<<"\n Account created successfully!"<<endl;
        cout<<"Assigned account number is:" << accNo <<endl;
    }
    void deleteAccount(){
        int accNo;
        cout <<"Enter Account Number : "<<endl;
        cin>>accNo;
        if(accounts.erase(accNo)){
            cout<<"Account deleted successfully!"<<endl;
        }else{
            cout<<"Account not found"<<endl;
        }
    }
     void viewAccount() {
        int accNo;
        cout << "\nEnter Account Number to see account details: ";
        cin >> accNo;

        if (accounts.find(accNo) != accounts.end()) {
            accounts[accNo].displayAccount();
        } else {
            cout << "\nAccount Not Found!\n";
        }
    }
    void listallAccounts(){
         if (accounts.empty()) {
            cout << "\n📭 No Accounts Found!\n";
            return;
        }
        cout << "\n========== ALL ACCOUNTS ==========\n";
        for (auto &entry : accounts) {
            entry.second.displayAccount();
        }
    }
    
};
void accountManagement() {
    BankSystem bank;
    int choice;

    do {
        cout << "\n========== BANK STAFF MENU ==========\n";
        cout << "1. Create New Customer Account\n";
        cout << "2. View Account Details\n";
        cout << "3. Delete Account\n";
        cout << "4. List All Accounts\n";
        cout << "5. Exit\n";
        cout << "=====================================\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.viewAccount(); break;
            case 3: bank.deleteAccount(); break;
            case 4: bank.listallAccounts(); break;
            case 5: cout << "\n Exiting... Thank you!\n"; break;
            default: cout << "\n Invalid Option! Try Again.\n"; break;
        }

    } while (choice != 5);

    
}
