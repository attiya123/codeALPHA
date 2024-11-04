#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// BankAccount struct to represent individual accounts
struct BankAccount {
    string accountHolder;
    int accountNumber;
    double balance;

    BankAccount(string holder, int accNum, double initialBalance = 0.0)
        : accountHolder(holder), accountNumber(accNum), balance(initialBalance) {}
};

// BankSystem class to manage multiple bank accounts
class BankSystem {
private:
    unordered_map<int, BankAccount> accounts;  // Hash table for quick account lookup

public:
    // Function to create a new account
    void createAccount(string holder, int accountNumber, double initialBalance = 0.0) {
        if (accounts.find(accountNumber) == accounts.end()) {  // Check if account already exists
            accounts[accountNumber] = BankAccount(holder, accountNumber, initialBalance);
            cout << "Account created successfully for " << holder << " with account number " << accountNumber << endl;
        } else {
            cout << "Error: Account number " << accountNumber << " already exists." << endl;
        }
    }

    // Function to deposit money into an account
    void deposit(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber].balance += amount;
            cout << "Deposited " << amount << " to account number " << accountNumber << endl;
        } else {
            cout << "Error: Account number " << accountNumber << " not found." << endl;
        }
    }

    // Function to withdraw money from an account
    void withdraw(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            if (accounts[accountNumber].balance >= amount) {
                accounts[accountNumber].balance -= amount;
                cout << "Withdrew " << amount << " from account number " << accountNumber << endl;
            } else {
                cout << "Error: Insufficient balance in account number " << accountNumber << endl;
            }
        } else {
            cout << "Error: Account number " << accountNumber << " not found." << endl;
        }
    }

    // Function to check the balance of an account
    void checkBalance(int accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Balance for account number " << accountNumber << ": " << accounts[accountNumber].balance << endl;
        } else {
            cout << "Error: Account number " << accountNumber << " not found." << endl;
        }
    }
};

int main() {
    BankSystem bank;

    // Test the banking system
    bank.createAccount("Alice", 1001, 500.0);
    bank.createAccount("Bob", 1002, 300.0);

    bank.deposit(1001, 200.0);
    bank.withdraw(1002, 100.0);

    bank.checkBalance(1001);
    bank.checkBalance(1002);

    return 0;
}
