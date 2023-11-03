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

    for (int i = 0; i < 6; ++i) {
        std::cout << "The number " << (i + 1) << " was rolled " << counts[i] << " times" << std::endl;
    }

    return 0;
}