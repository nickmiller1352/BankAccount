// Bank Account V4

// Moved Savings and Checking into seperate files to implement here.

#include "Checking.h"
#include "Savings.h"
#pragma warning(disable : 4996) // Allows use of ctime function

using namespace std;

int mainMenuChoice;

void displayMainMenu()
{
    cout << "Please indicate the account you would like to access:\n";
    cout << "1. Checking Account\n";
    cout << "2. Savings Account\n";
    cout << "3. Exit\n";

    cin >> mainMenuChoice;
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