// Bank Account V2

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

double balance = 100, deposit, withdraw;
int menuChoice;

void saveBalance()
{
    ofstream balanceFile("balance.txt");
    if (balanceFile.is_open())
    {
        balanceFile << balance;
        balanceFile.close();
    }
    else
        cout << "Unable to complete transaction.";
}

void readBalance()
{
    string accountBalance;
    ifstream balanceFile("balance.txt");
    if (balanceFile.is_open())
    {
        while (getline(balanceFile, accountBalance))
        {
            cout << accountBalance << endl;
        }
        balanceFile.close();
    }
    else
        cout << "Unable to complete transaction.";
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
            cout << "Balance: $";
            readBalance();
            cout << endl;
            break;
        case 2:
            cout << "How much would you like to deposit?\n"
                 << "$";
            double deposit;
            cin >> deposit;
            balance = balance + deposit;
            saveBalance();
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
            saveBalance();
            break;
        default:
            cout << "Incorrect input.";
        }
        displayMenu();
    }
    return 0;
}