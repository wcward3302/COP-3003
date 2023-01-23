/*
Name: William Ward
Course: COP3003 (CRN15015) - Programming II
Info: Assignment 2

Construction:
- loop collect user grades
    - validate for range x to y
    - insert rounded grades into array
- find the lowest grade
- calculate average minus lowest grade
- output grade based on average
*/

#include <iostream>
#include <array>
#include <cmath>

int main()
{
    std::cout << "Please enter 11 grades - grades 0-100 accepted - decimals accepted - Lowest grade will be dropped!\n\n";

    // initialize all the variables to be used for storage or math
    float user_input = 0;
    int number_of_inputs = 0;
    int sum_of_grades = 0;
    int average_of_grades = 0;

    // flag for user input validation
    bool user_input_valid = false;

    // this value should be 101 so anything less will become lowest_grade later
    float lowest_grade = 101; 

    // initialize array that will be used to store user grades
    std::array<float, 11> user_input_array = {};
    
    // collect user input and loop till array is full
    while(number_of_inputs < 11)
    { 

        // this while loop will keep user stuck in loop until response is within range 0 - 100
        while(!user_input_valid)
        { 
            std::cout << "Enter grade " << number_of_inputs + 1 << ": ";
            std::cin >> user_input;

            // if the input is within range and the cin was not passed bad input, pass true and break from nested while loop
            if(user_input >= 0 && user_input <= 100 && std::cin.good())
            { 
                user_input_valid = true;
            }

            // else, display a message, clear cin buffer and data, repeat loop until response is valid. Stay on target... 
            else
            {
                std::cout << "please enter a valid response (0-100)\n";
                std::cin.clear();
                std::cin.ignore(100,'\n');
            }
        }

        // reset flag for next loop until 11 loops, add truncated value to the array, continue looping. Stay on target..........
        user_input_valid = false; 
        user_input_array[number_of_inputs] = std::trunc(user_input);        
        number_of_inputs++;
    }

    std::cout << "\n\n";

    // This for loop will sum all the grades by adding the I value, then the i + n, etc. Will also determine lowest grade for later calculation
    for(int i = 0; i < user_input_array.size(); i++)
    {
        sum_of_grades = sum_of_grades + user_input_array[i];
        
        if (user_input_array[i] < lowest_grade)
        {
            lowest_grade = user_input_array[i];
        }
    }

    // simple average of the sum of all the grades minus the score of the dropped grade
    average_of_grades = (sum_of_grades - lowest_grade) / (user_input_array.size() - 1); 

    // output user grades minus the lowest score, once lowest score is skipped, set variable to -1 so another value is not skipped
    int counter = 1;
    for (int i = 0; i < user_input_array.size(); i++)
    {
        if (user_input_array[i] == lowest_grade)
        {
            lowest_grade = -1;
        }
        else
        {
            std::cout << "Grade " << counter++ << " was " << user_input_array[i] << "\n";
        }
    }

    // enter switch based on average grade value, will output accordingly
    std::cout << "\nYour final grade was ";
    switch (average_of_grades)
    {
        // case x .... y will check if average_of_grades is in a range and enter a case accordingly. 
        case 90 ... 100: 
            std::cout << "A";
            break;
        case 80 ... 89:
            std::cout << "B";
            break;
        case 70 ... 79:
            std::cout << "C";
            break;
        case 60 ... 69:
            std::cout << "D";
            break;
        default:
            std::cout << "F";
            break;
        }
    
    std::cout <<"\n\n";
    return 0;
}