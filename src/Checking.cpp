#include "Checking.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable : 4996) // Allows use of ctime function

using namespace std;

double checking_balance;
double checking_deposit;
double checking_withdraw;
string checking_account_balance;
string checking_statement;
int checkingMenuChoice;
string::size_type checking_sz;

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
            checking_balance = stod(checking_account_balance, &checking_sz);
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
            checking_balance = stod(checking_account_balance, &checking_sz);
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