/*
Name: William Ward
Course: COP3003 (CRN15015) - Programming II
Info: Assignment 3 - gradeFunction.cpp
*/

#include "gradeFunction.hpp"

std::array <int, 11> grade_array;

// student struct
struct Student {
    std::string grade_level;
    std::string name; 
    int final_grade;
    char final_letter_grade;
};

// Student struct instance
Student student;

// non-member functions to add and view struct members

// Takes passed data and inserts into struct instance
void add_name(std::string x_name){
    student.name = x_name;    
}

void add_grade_level(std::string x_grade_level){
    student.grade_level = x_grade_level;
}

void add_final_grade(int x_final_grade){
    student.final_grade = x_final_grade;
}

void add_final_letter_grade(char x_final_letter_grade){
    student.final_letter_grade = x_final_letter_grade;
}

void add_to_grade_array(int index, int value){
    grade_array[index] = value;
}


// Similar to the above functions, returning data from struct instance
std::string get_name(){
    return student.name;
}

std::string get_grade_level(){
    return student.grade_level;
}

int get_final_grade(){
    return student.final_grade;
}

char get_final_letter_grade(){
    return student.final_letter_grade;
}

int get_grade_array_at_index(int index){
    return grade_array[index];
}

int get_grade_array_size(){
    return grade_array.size();
}

// new functions

// function to sort array, use get_average, and then return the average
int get_average_grade(){
    // sort the array smallest to largest
    std::sort(grade_array.begin(), grade_array.end());
    student.final_grade = get_average(grade_array);

    return student.final_grade;
}

// new function to display message and collect input from user 
std::string display_and_collect(std::string message){
    std::string input;
    std::cout << message;
    std::getline(std::cin, input);

    return input;
}

// functions from previous assignment

// quit grading based on user input
void quit_grading (int x){

    // switch based on input from main, once finished, the program will exit
    switch (x){
    case 1:
        // reason -1
        std::cout << "\nAn error has occurred, please try again.\n\n";
        break;
    case 0:
        // reason 0, terminate
        std::cout << "\nThank you for using our product!\n\n";
        exit (1);
    case -1:
        // reason 1
        std::cout << "\nSorry you had to quit early. Thank you for using out product!\n\n";
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

        // if user inputs -1, code exits
        if (user_input == -1){
            quit_grading(-1);
        }

        else{
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