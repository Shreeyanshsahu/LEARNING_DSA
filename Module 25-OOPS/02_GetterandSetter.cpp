#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;   // private data (cannot be accessed directly)

public:
    // Constructor
    BankAccount(int initialBalance) {
        // Use setter to initialize safely
        setBalance(initialBalance);
    }

    // Setter: used to set/change private variable safely
    void setBalance(int amount) {
        if (amount >= 0) {
            balance = amount;
        } else {
            cout << "Invalid balance! Setting to 0.\n";
            balance = 0;
        }
    }

    // Getter: used to access private variable safely
    int getBalance() {
        return balance;
    }

    // Deposit money
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Deposit amount must be positive!\n";
        }
    }

    // Withdraw money
    void withdraw(int amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
        } else {
            cout << "Invalid withdraw amount!\n";
        }
    }
};

int main() {
    // Create account with initial balance
    BankAccount account(1000);

    cout << "Initial Balance: " << account.getBalance() << endl;

    // Deposit money
    account.deposit(500);
    cout << "After deposit: " << account.getBalance() << endl;

    // Withdraw money
    account.withdraw(300);
    cout << "After withdraw: " << account.getBalance() << endl;

    // Try invalid set
    account.setBalance(-200);  // handled by setter
    cout << "After invalid set: " << account.getBalance() << endl;

    return 0;
}
