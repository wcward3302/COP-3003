/*
Name: William Ward
Course: COP3003 (CRN15015) - Programming II
Info: Assignment 3 - gradeFunction.cpp
*/

#include "gradeFunction.hpp"

// new function to display message and collect input from user 
std::string display_and_collect(std::string message){
    std::string input;
    std::cout << message;
    std::getline(std::cin, input);

    return input;
}

// quit grading based on user input
void quit_grading (int x){

    // switch based on input from main, once finished, the program will exit
    switch (x){
    case -1:
        // reason -1
        std::cout << "an error has occurred, please try again.\n";
        break;
    case 0:
        // reason 0, terminate
        std::cout << "Thank you for using our product!\n";
        exit (1);
    case 1:
        // reason 1
        std::cout << "Sorry you had to quit early. Thank you for using out product!\n";
        exit (1);
        break;
    default: // default case just skips the switch
        break;
    }
}

// is called to get a grade, handles input and validation before returning value
int get_grade (){

    // initialize variables
    float user_input = 0;
    bool user_input_valid = false;

    // loop will be false until user input is validated and passed true flag
    while(!user_input_valid){ 
        std::cout << "Enter grade: ";
        std::cin >> user_input;

        // if the input is within range and the cin was not passed bad input, pass true and break from nested while loop
        if(user_input >= 0 && user_input <= 100 && std::cin.good()){ 
            user_input_valid = true;
        }

        // else, display a message, clear cin buffer and data, repeat loop until response is valid. Stay on target... 
        else{
            std::cout << "please enter a valid response (0-100)\n";
            std::cin.clear();
            std::cin.ignore(100,'\n');
        }
    }

    // return the user input once validated
    return user_input;
}

// function takes array of grades (after being sorted), sums 1 - 10 values, divides by size of array - 1. Lowest grade = first gets ignored. 
int get_average (std::array <int, 11> grade_array){

    // initialize variables
    int sum = 0;
    int average = 0;
    
    // loop though the array except for the first value, which will be the lowest grade
    for (int x = 1; x < grade_array.size(); x++){
        sum = sum + grade_array[x];
    }

    // take sum from loop and divide by number of elements
    average = sum / (grade_array.size() - 1);

    // return the calculated average
    return average;
}