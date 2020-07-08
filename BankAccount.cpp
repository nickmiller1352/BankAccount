// Bank Account V1.cpp

// Most basic use of this service.
// Balance always starts at $0.
// Allows the user to view balance, deposit, and withdraw.
// Does not save ending balance for next use.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double balance, deposit, withdraw;
int menuChoice;

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
            cout << "Balance: $" << balance << '\n';
            break;
        case 2:
            cout << "How much would you like to deposit?\n"
                 << "$";
            double deposit;
            cin >> deposit;
            balance = balance + deposit;
            break;
        case 3:
            cout << "How much would you like to withdraw?\n"
                 << "$";
            double withdraw;
            cin >> withdraw;
            if (withdraw > balance)
            {
                cout << "Insufficient funds for withdrawal!\n";
            }
            else
            {
                balance = balance - withdraw;
            }
            break;
        default:
            cout << "Incorrect input.";
        }
        displayMenu();
    }
    return 0;
}