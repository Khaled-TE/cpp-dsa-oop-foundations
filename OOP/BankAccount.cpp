#include <iostream>
#include <string>
using namespace std;

class BankAccount{
private:

    string accountNumber;
    string accountHolderName;
    double balance;

public:

    BankAccount(string an, string ahn, double b)
    {
        accountNumber = an;
        accountHolderName = ahn;
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance )
        {
            balance -= amount;
        }
    }

    bool isHigherBalance(BankAccount other)
    {
        return (balance > other.balance);
    }

    bool isVIP()
    {
        return (balance > 500);
    }

    void displayAccountInfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
        cout << "VIP Status: " << (isVIP() ? "Yes" : "No") << endl;
    }
    
};

int main()
{
    BankAccount account1("123456789", "John Doe", 1000);
    BankAccount account2("987654321", "Jane Smith", 2000);

    account1.deposit(1000);
    account2.deposit(2000);

    account1.withdraw(500);
    account2.withdraw(1000);

    if(account1.isHigherBalance(account2))
    {
        cout << "Account 1 has a higher balance." << endl;
    }
    else
    {
        cout << "Account 2 has a higher balance." << endl;
    }

    cout << "Account 1 Info:" << endl;
    account1.displayAccountInfo();
    cout << "Account 2 Info:" << endl;
    account2.displayAccountInfo();

    return 0;
}