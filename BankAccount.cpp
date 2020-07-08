// Bank Account V4

// Added Savings account option
// Added menu to distinguish between Checkings and Savings accounts

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable : 4996) // Allows use of ctime function

using namespace std;

double checking_balance, checking_deposit, checking_withdraw;
double savings_balance, savings_deposit, savings_withdraw;
string checking_account_balance, checking_statement;
string savings_account_balance, savings_statement;
string::size_type sz;
int mainMenuChoice;
int checkingMenuChoice;
int savingsMenuChoice;

void displayMainMenu()
{
    cout << "Please indicate the account you would like to access:\n";
    cout << "1. Checking Account\n";
    cout << "2. Savings Account\n";
    cout << "3. Exit\n";

    cin >> mainMenuChoice;
}

void saveSavingsBalance()
{
    ofstream savingsbalancefile;
    savingsbalancefile.open("savings_balance.txt");
    savingsbalancefile << savings_account_balance;
    savingsbalancefile.close();
}

void printSavingsStatement()
{
    ifstream savingsstatementfile("savings_statement.txt");
    if (savingsstatementfile.is_open())
    {
        while (getline(savingsstatementfile, savings_statement))
        {
            cout << savings_statement << endl;
        }
        savingsstatementfile.close();
    }
    else
        cout << "Statement unavailable.";
}

void readSavingsBalance()
{
    ifstream savingsbalancefile("savings_balance.txt");
    if (savingsbalancefile.is_open())
    {
        while (getline(savingsbalancefile, savings_account_balance))
        {
            savings_balance = stod(savings_account_balance, &sz);
        }
        savingsbalancefile.close();
    }
}

void printSavingsBalance()
{
    ifstream savingsbalancefile("savings_balance.txt");
    if (savingsbalancefile.is_open())
    {
        while (getline(savingsbalancefile, savings_account_balance))
        {
            savings_balance = stod(savings_account_balance, &sz);
            cout << "Balance: $" << savings_balance << endl;
        }
        savingsbalancefile.close();
    }
}

void makeSavingsDeposit()
{
    readSavingsBalance();

    cout << "How much would you like to deposit?\n";
    cout << "$";

    cin >> savings_deposit;
    savings_balance = savings_balance + savings_deposit;

    savings_account_balance = to_string(savings_balance);

    saveSavingsBalance();

    time_t my_time = time(NULL);

    ofstream savingsstatementfile;
    savingsstatementfile.open("savings_statement.txt", ios_base::app);
    savingsstatementfile << '\n'
                         << ctime(&my_time);
    savingsstatementfile << '\t' << "Deposit made: $" << savings_deposit << endl;
    savingsstatementfile << '\t' << "Balance: $" << savings_account_balance;
}

void makeSavingsWithdrawal()
{
    readSavingsBalance();

    cout << "How much would you like to withdraw?\n";
    cout << "$";

    cin >> savings_withdraw;
    savings_balance = savings_balance - savings_withdraw;

    savings_account_balance = to_string(savings_balance);

    saveSavingsBalance();

    time_t my_time = time(NULL);

    ofstream savingsstatementfile;
    savingsstatementfile.open("savings_statement.txt", ios_base::app);
    savingsstatementfile << '\n'
                         << ctime(&my_time);
    savingsstatementfile << '\t' << "Withdrawal made: $" << savings_withdraw << endl;
    savingsstatementfile << '\t' << "Balance: $" << savings_account_balance;
}

void displaySavingsMenu()
{
    cout << "What would you like to do today?\n";
    cout << "1. View Account Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Print Statement\n";
    cout << "5. Exit\n";

    cin >> savingsMenuChoice;

    while (savingsMenuChoice != 5)
    {
        switch (savingsMenuChoice)
        {
        case 1:
            printSavingsBalance();
            break;
        case 2:
            makeSavingsDeposit();
            break;
        case 3:
            makeSavingsWithdrawal();
            break;
        case 4:
            printSavingsStatement();
            break;
        default:
            cout << "Incorrect input.\n";
        }
        displaySavingsMenu();
    }
}

void saveCheckingBalance()
{
    ofstream checkingbalancefile;
    checkingbalancefile.open("checking_balance.txt");
    checkingbalancefile << checking_account_balance;
    checkingbalancefile.close();
}

void printCheckingStatement()
{
    ifstream checkingstatementfile("checking_statement.txt");
    if (checkingstatementfile.is_open())
    {
        while (getline(checkingstatementfile, checking_statement))
        {
            cout << checking_statement << endl;
        }
        checkingstatementfile.close();
    }
    else
        cout << "Statement unavailable.";
}

void readCheckingBalance()
{
    ifstream checkingbalancefile("checking_balance.txt");
    if (checkingbalancefile.is_open())
    {
        while (getline(checkingbalancefile, checking_account_balance))
        {
            checking_balance = stod(checking_account_balance, &sz);
        }
        checkingbalancefile.close();
    }
}

void printCheckingBalance()
{
    ifstream checkingbalancefile("checking_balance.txt");
    if (checkingbalancefile.is_open())
    {
        while (getline(checkingbalancefile, checking_account_balance))
        {
            checking_balance = stod(checking_account_balance, &sz);
            cout << "Balance: $" << checking_balance << endl;
        }
        checkingbalancefile.close();
    }
}

void makeCheckingDeposit()
{
    readCheckingBalance();

    cout << "How much would you like to deposit?\n";
    cout << "$";

    cin >> checking_deposit;
    checking_balance = checking_balance + checking_deposit;

    checking_account_balance = to_string(checking_balance);

    saveCheckingBalance();

    time_t my_time = time(NULL);

    ofstream checkingstatementfile;
    checkingstatementfile.open("checking_statement.txt", ios_base::app);
    checkingstatementfile << '\n'
                          << ctime(&my_time);
    checkingstatementfile << '\t' << "Deposit made: $" << checking_deposit << endl;
    checkingstatementfile << '\t' << "Balance: $" << checking_account_balance;
}

void makeCheckingWithdrawal()
{
    readCheckingBalance();

    cout << "How much would you like to withdraw?\n";
    cout << "$";

    cin >> checking_withdraw;
    checking_balance = checking_balance - checking_withdraw;

    checking_account_balance = to_string(checking_balance);

    saveCheckingBalance();

    time_t my_time = time(NULL);

    ofstream checkingstatementfile;
    checkingstatementfile.open("checking_statement.txt", ios_base::app);
    checkingstatementfile << '\n'
                          << ctime(&my_time);
    checkingstatementfile << '\t' << "Withdrawal made: $" << checking_withdraw << endl;
    checkingstatementfile << '\t' << "Balance: $" << checking_account_balance;
}

void displayCheckingMenu()
{
    cout << "What would you like to do today?\n";
    cout << "1. View Account Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Print Statement\n";
    cout << "5. Exit\n";

    cin >> checkingMenuChoice;

    while (checkingMenuChoice != 5)
    {
        switch (checkingMenuChoice)
        {
        case 1:
            printCheckingBalance();
            break;
        case 2:
            makeCheckingDeposit();
            break;
        case 3:
            makeCheckingWithdrawal();
            break;
        case 4:
            printCheckingStatement();
            break;
        default:
            cout << "Incorrect input.\n";
        }
        displayCheckingMenu();
    }
}

int main()
{
    displayMainMenu();

    while (mainMenuChoice != 3)
    {
        switch (mainMenuChoice)
        {
        case 1:
            displayCheckingMenu();
            break;
        case 2:
            displaySavingsMenu();
            break;
        default:
            cout << "Incorrect input.\n";
        }
        displayMainMenu();
    }

    return 0;
}