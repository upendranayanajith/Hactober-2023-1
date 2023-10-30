#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int minRange, maxRange, numAttempts;
    int userNumber, generatedNumber;
    int attemptsLeft;
    int numMatches = 0;

    // Get user input for the range and the number of attempts
    std::cout << "Enter the range (min max) for random numbers: ";
    std::cin >> minRange >> maxRange;
    std::cout << "Enter the number of attempts: ";
    std::cin >> numAttempts;

    // Generate random numbers and compare
    for (attemptsLeft = numAttempts; attemptsLeft > 0; --attemptsLeft) {
        generatedNumber = minRange + (std::rand() % (maxRange - minRange + 1));

        std::cout << "Attempt #" << (numAttempts - attemptsLeft + 1) << "/" << numAttempts
                  << ": Guess a number between " << minRange << " and " << maxRange << ": ";
        std::cin >> userNumber;

        if (userNumber == generatedNumber) {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
            numMatches++;
            break;
        } else if (userNumber < generatedNumber) {
            std::cout << "Try a higher number." << std::endl;
        } else {
            std::cout << "Try a lower number." << std::endl;
        }
    }

    if (attemptsLeft == 0) {
        std::cout << "You've run out of attempts. The correct number was " << generatedNumber << "." << std::endl;
    }

    std::cout << "You had " << numMatches << " match(es) out of " << numAttempts << " attempts." << std::endl;

    return 0;
}
