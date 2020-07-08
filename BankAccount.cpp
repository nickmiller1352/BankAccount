// Bank Account V3

// Keeps track of every transaction within this account.
// Allow user to print a statement showing transactions on account.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double balance, deposit, withdraw;
string account_balance, statement;
string::size_type sz;
int menuChoice;

void saveBalance()
{
    ofstream balancefile;
    balancefile.open("balance.txt");
    balancefile << account_balance;
    balancefile.close();
}

void printStatement()
{
    ifstream statementfile("statement.txt");
    if (statementfile.is_open())
    {
        while (getline(statementfile, statement))
        {
            cout << statement << endl;
        }
        statementfile.close();
    }
    else
        cout << "Statement unavailable.";
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

    ofstream statementfile;
    statementfile.open("statement.txt", ios_base::app);
    statementfile << '\n'
                  << "Deposit made: $" << deposit << endl;
    statementfile << "Balance: $" << account_balance;
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

    ofstream statementfile;
    statementfile.open("statement.txt", ios_base::app);
    statementfile << '\n'
                  << "Withdrawal made: $" << withdraw << endl;
    statementfile << "Balance: $" << account_balance;
}

void displayMenu()
{
    cout << "What would you like to do today?\n";
    cout << "1. View Account Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Print Statement\n";
    cout << "5. Exit\n";

    cin >> menuChoice;
}

int main()
{
    displayMenu();

    while (menuChoice != 5)
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
        case 4:
            printStatement();
            break;
        default:
            cout << "Incorrect input.\n";
        }
        displayMenu();
    }
    return 0;
}