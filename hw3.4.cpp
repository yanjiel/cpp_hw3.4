//Your assignment is to implement the "Animal Game." The idea is that you chose a secret animal.
//The computer then asks you questions about the animal, terminating with a guess.
//If the guess is right, the computer wins, if it is wrong you win.
//But as part of winning, you have to provide your animal, and a differentiating yes / no question that the program can use to learn more animals

#include <iostream>
#include <format>
#include <numeric>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

struct Game {
    static size_t n_games;
    //Game() { n_games++; } // constructor
    //~Game() { n_games--; } //destructor
};



struct BinaryTree {
    string question;
    string yes_answer;
    string no_answer;
    BinaryTree *yes_tree;
    BinaryTree *no_tree;

    BinaryTree(string q, string y_a, string n_a) {
        question = q;
        yes_answer = y_a;
        no_answer = n_a;
        yes_tree = NULL;
        no_tree = NULL;
    }

    void display_question() {
        cout << question << "(y/n): " << endl;
    }

    void give_answer(string answer) {
        if (answer == "y") {
            cout << "Is it " << yes_answer << "? (y/n): ";
        }
        else {
            cout << "Is it " << no_answer << "? (y/n): ";
        }
    }

    void display_result(string answer) {
        if (answer == "y") {
            cout << "The computer wins!" << endl;
        }
        else {
            cout << "You win." << endl;
        }
        
    }

 
};

string parse_input_lower(string input, int st = 0, int end = 1) {
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    string output = input.substr(st, end);
    transform(output.begin(), output.end(), output.begin(), ::tolower);
    return output;
}

int main() {
	cout << "Welcome to the game. ";
	cout << "Would you like play a new game? (y/n): ";
	string answer = "";
    cin >> answer;
	//answer = parse_input(answer,0,1);
    

    while (parse_input_lower(answer, 0, 1) == "y") {
        BinaryTree node{ "can it fly?", "eagle", "dog" };
        node.display_question();
        cin >> answer;
        node.give_answer(parse_input_lower(answer, 0, 1));
        cin >> answer;
        node.display_result(parse_input_lower(answer, 0, 1));


        cout << "Would you like play a new game? (y/n): ";
        cin >> answer;
    }

	return 0;
}