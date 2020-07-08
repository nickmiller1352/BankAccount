#include "Savings.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996) // Allows use of ctime function

using namespace std;

double savings_balance;
double savings_deposit;
double savings_withdraw;
double interestEarned;
double interestRate;
double time_passed;
string savings_account_balance;
string savings_statement;
int savingsMenuChoice;
string::size_type savings_sz;

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
            savings_balance = stod(savings_account_balance, &savings_sz);
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
            savings_balance = stod(savings_account_balance, &savings_sz);
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

void compoundInterest()
{

    interestEarned = savings_balance * pow((1 + interestRate / 100), time_passed) - savings_balance;
    savings_account_balance = savings_balance * pow((1 + interestRate / 100), time_passed);
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