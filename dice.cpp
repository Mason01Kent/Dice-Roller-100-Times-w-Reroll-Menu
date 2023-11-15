#include <iostream>
#include <random>
#include <ctime>

class Dice {
public:
    Dice() {
        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    int roll() {
        // Generate a random number between 1 and 6
        return (std::rand() % 6) + 1;
    }
};

int main() {
    Dice dice;
    int counts[6] = { 0 }; // Initialize an array to store the counts of each number

    for (int i = 0; i < 100; ++i) {
        int rollResult = dice.roll();
        counts[rollResult - 1]++; // Increment the count for the rolled number
    }

    for (int i = 0; i < 6; ++i) {//prints out the number of times each number was rolled
        cout << "\t" << (i + 1) << ")" << " was rolled " << counts[i] << " times" << std::endl;
    }
    cout << endl << "Thank you for using the Dice Roller!" << endl;
    cout << " ~ Mason Kent ~" << endl;
}

int main() {

    cout << "Project 6" << endl << "Welcome to the Dice Roller!" << endl << endl << "Press 1 to roll the dice! or 2 to quit" << endl;

    int choice;
    //input validation
    while (!(cin >> choice) || choice < 1 || choice > 2) {
        cout << "Invalid input. Please enter a number between 1 and 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //switch to determine input and what inputs to ask and outputs to provide
    switch (choice) {
    case 1:
        CallDice();
        break;

    case 2:
        break;
    }
    }

    return 0;
}