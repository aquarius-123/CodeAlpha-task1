#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void display() {
        cout << type << " : Rs. " << amount << endl;
    }
};

class Account {
public:
    int accountNo;
    double balance;
    vector<Transaction> history;

    Account(int no, double bal = 0) {
        accountNo = no;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdrawal", amount));
        }
        else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount <= balance) {
            balance -= amount;
            receiver.balance += amount;

            history.push_back(Transaction("Transfer Sent", amount));
            receiver.history.push_back(Transaction("Transfer Received", amount));
        }
        else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void displayAccount() {
        cout << "\nAccount Number: " << accountNo << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    void displayTransactions() {
        cout << "\nTransaction History:\n";
        for (int i = 0; i < history.size(); i++) {
            history[i].display();
        }
    }
};

class Customer {
public:
    string name;
    Account account;

    Customer(string n, int accNo, double bal = 0)
        : account(accNo, bal) {
        name = n;
    }

    void displayCustomer() {
        cout << "\nCustomer Name: " << name << endl;
        account.displayAccount();
    }
};

int main() {
    Customer c1("Ali", 101, 5000);
    Customer c2("Ahmed", 102, 3000);

    c1.account.deposit(2000);
    c1.account.withdraw(1000);
    c1.account.transfer(c2.account, 1500);

    c1.displayCustomer();
    c1.account.displayTransactions();

    c2.displayCustomer();
    c2.account.displayTransactions();

    return 0;
}