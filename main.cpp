#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define variables to keep track of user and computer scores
    int user_score = 0;
    int computer_score = 0;

    // Define variables for user and computer choices
    int user_choice;
    int computer_choice;

    // Game loop
    while (true) {
        // Print out current scores
        cout << "Score: You - " << user_score << ", Computer - " << computer_score << endl;

        // Get user's choice with error handling for invalid input
        while (true) {
            cout << "Choose (1) Rock, (2) Paper, or (3) Scissors: ";
            cin >> user_choice;

            if (user_choice >= 1 && user_choice <= 3) {
                break;
            } else {
                cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            }
        }

        // Generate computer's choice
        computer_choice = rand() % 3 + 1;

        // Determine winner and adjust scores
        if (user_choice == computer_choice) {
            cout << "Tie!" << endl;
        } else if ((user_choice == 1 && computer_choice == 3) ||
                   (user_choice == 2 && computer_choice == 1) ||
                   (user_choice == 3 && computer_choice == 2)) {
            cout << "You win!" << endl;
            user_score++;
        } else {
            cout << "Computer wins!" << endl;
            computer_score++;
        }

        // Ask user if they want to play again
        char play_again;
        cout << "Play again? (y/n): ";
        cin >> play_again;

        // If user chooses not to play again, break out of loop
        if (play_again == 'n') {
            break;
        }
    }

    return 0;
}