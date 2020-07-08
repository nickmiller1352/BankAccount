// Bank Account V2.3.cpp

// Allows a single user to save balance for next use.
// Holds memory of balance in a text file.

/*  - Create a .txt file named "balance" to hold user's balance.
    - Write a function to write account balance to "balance".
    - Write a function to read account balance from "balance".
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double balance, deposit, withdraw;
string account_balance;
string::size_type sz;
int menuChoice;

void saveBalance()
{
    ofstream balancefile;
    balancefile.open("balance.txt");
    balancefile << account_balance;
    balancefile.close();
}

void readBalance()
{
    ifstream balancefile("balance.txt");
    if (balancefile.is_open())
    {
        while (getline(balancefile, account_balance))
        {
            balance = stod(account_balance, &sz);
        }
        balancefile.close();
    }
}

void printBalance()
{
    ifstream balancefile("balance.txt");
    if (balancefile.is_open())
    {
        while (getline(balancefile, account_balance))
        {
            balance = stod(account_balance, &sz);
            cout << "Balance: $" << balance << endl;
        }
        balancefile.close();
    }
}

void makeDeposit()
{
    readBalance();

    cout << "How much would you like to deposit?\n";
    cout << "$";

    cin >> deposit;
    balance = balance + deposit;

    account_balance = to_string(balance);

    saveBalance();
}

void makeWithdrawal()
{
    readBalance();

    cout << "How much would you like to withdraw?\n";
    cout << "$";

    cin >> withdraw;
    balance = balance - withdraw;

    account_balance = to_string(balance);

    saveBalance();
}

void displayMenu()
{
    cout << "What would you like to do today?\n";
    cout << "1. View Account Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Exit\n";

    cin >> menuChoice;
}

int main()
{
    displayMenu();

    while (menuChoice != 4)
    {
        switch (menuChoice)
        {
        case 1:
            printBalance();
            break;
        case 2:
            makeDeposit();
            break;
        case 3:
            makeWithdrawal();
            break;
        default:
            cout << "Incorrect input.\n";
        }
        displayMenu();
    }
    return 0;
}