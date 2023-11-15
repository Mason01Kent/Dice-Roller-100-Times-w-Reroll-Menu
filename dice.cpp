#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void CallDice(); // Function prototype

class Dice { // Dice class
public:
    Dice() { 
        srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator
    }

    int roll() {
        return (rand() % 6) + 1; // Return a random number between 1 and 6
    }
};

void CallDice() { 
    Dice dice;// Create a dice object

    int counts[6] = { 0 };

    for (int i = 0; i < 100; ++i) { // Roll the dice 100 times
        int rollResult = dice.roll();
        counts[rollResult - 1]++;
    }

    for (int i = 0; i < 6; ++i) { // Display the results
        cout << "\t" << (i + 1) << ")" << " was rolled " << counts[i] << " times" << std::endl;
    }
}

void Menu() { // Menu function
    cout << endl << "Press 1 to roll the dice! or 2 to quit: ";
    int choice;
    cin >> choice;
    switch (choice) { // Switch statement
    case 1: // Call the dice function and menu function for repeating menu
        CallDice();
        Menu();
        break;
    case 2: // Exit the program
        cout << endl << "Thank you for using the Dice Roller!" << endl << endl;
        cout << "\t ~ Mason Kent ~" << endl << endl;
        break;
    }
}

int main() { // Main function
    cout << "Project 6" << endl << "Welcome to the Dice Roller!" << endl;
    Menu(); // Call the menu function

    cout << "Press enter to exit..." << endl;

    return 0;
}