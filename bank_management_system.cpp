#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;

public:
    Account(int accNo, string accName, double initialBalance) {
        accountNumber = accNo;
        name = accName;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! Current balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! Current balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    void displayDetails() const {
        cout << "\nAccount Number: " << accountNumber
             << "\nAccount Holder: " << name
             << "\nBalance: " << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

class Bank {
private:
    vector<Account> accounts;
    int nextAccountNumber;

public:
    Bank() : nextAccountNumber(1001) {}

    void createAccount() {
        string name;
        double initialDeposit;

        cout << "\nEnter account holder name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter initial deposit: ";
        cin >> initialDeposit;

        if (initialDeposit < 0) {
            cout << "Initial deposit cannot be negative!" << endl;
            return;
        }

        Account newAccount(nextAccountNumber, name, initialDeposit);
        accounts.push_back(newAccount);
        cout << "Account created successfully! Your account number is: " << nextAccountNumber << endl;
        nextAccountNumber++;
    }

    void depositMoney() {
        int accNo;
        double amount;
        cout << "\nEnter account number: ";
        cin >> accNo;

        for (Account &acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc.deposit(amount);
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void withdrawMoney() {
        int accNo;
        double amount;
        cout << "\nEnter account number: ";
        cin >> accNo;

        for (Account &acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc.withdraw(amount);
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void displayAccountDetails() {
        int accNo;
        cout << "\nEnter account number: ";
        cin >> accNo;

        for (const Account &acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                acc.displayDetails();
                return;
            }
        }
        cout << "Account not found!" << endl;
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n--- Bank Management System ---";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Display Account Details";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.depositMoney();
                break;
            case 3:
                bank.withdrawMoney();
                break;
            case 4:
                bank.displayAccountDetails();
                break;
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
