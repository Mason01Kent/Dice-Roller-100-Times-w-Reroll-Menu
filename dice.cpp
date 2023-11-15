//Mason Kent
//COP2000.0M1
//Random Dice Roller
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void CallDice(); //function prototype

class Dice { //class for dice
public:
    Dice() {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    int roll() {//rolls the dice
        return (rand() % 6) + 1;//returns a random number between 1 and 6
    }
};

void CallDice() {
    Dice dice; //calls the dice class

    int counts[6] = { 0 }; // Initialize an array to store the counts of each number

    for (int i = 0; i < 100; ++i) { //rolls the dice 100 times
        int rollResult = dice.roll(); // Roll the dice
        counts[rollResult - 1]++; // Increment the count for the rolled number
    }

    for (int i = 0; i < 6; ++i) {//prints out the number of times each number was rolled
        cout << "\t" << (i + 1) << ")" << " was rolled " << counts[i] << " times" << std::endl;
    }

}

void Menu() { //menu function
    cout <<  endl << "Press 1 to roll the dice! or 2 to quit: ";
    int choice;
    cin >> choice;
    switch (choice) { //switch statement for menu
    case 1: //calls the dice and menu function
        CallDice();
        Menu();
        break;
    case 2: //exits the program
        cout << endl << "Thank you for using the Dice Roller!" << endl << endl;
        cout << "\t ~ Mason Kent ~" << endl << endl;
		break;
    }
}

int main() { //main function
    cout << "Project 6" << endl << "Welcome to the Dice Roller!" << endl;   
    Menu();

   
    cout << "Press enter to exit..." << endl;

    return 0;
}