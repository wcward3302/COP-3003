/*
Name: William Ward
Course: COP3003 (CRN15015) - Programming II
Info: Assignment 3 - main.cpp
*/

#include <string>
#include <array>
#include <iostream>
#include "gradeFunction.hpp"

int main(){

    // create instance 
    // initialize variables
    int loop_counter = 0, average_grade = 0;
    std::string name, grade_level;

    std::cout << "\n--------------------------------------------------------------------------------------------------------------------------\n\n";

    // NEW with this update - Function that will display provided message, collect and then return input!
    std::string get_name_message = "Please enter your name: ";
    std::string get_grade_level_message = "Please enter your grade level: ";

    // get name, pass to struct with function
    name = display_and_collect(get_name_message);
    add_name(name);

    // get grade level, pass to struct with function
    grade_level = display_and_collect(get_grade_level_message);
    add_grade_level(grade_level);

    std::cout << "\n--------------------------------------------------------------------------------------------------------------------------\n\n";


    // loop to collect all grades with get_grade input function (validation inside function)
    std::cout << "Enter grades - lowest score will be dropped! (-1 to quit)\n";
    while (loop_counter < 11){
        add_to_grade_array(loop_counter, get_grade());
        loop_counter++;
    }

    std::cout << "\n--------------------------------------------------------------------------------------------------------------------------\n\n";
    
    // sort the array to make 0 element lowest grade and print
    std::cout << "Grades are\t";
    for (int x = 0; x < get_grade_array_size(); x++){
        std::cout << get_grade_array_at_index(x) << "\t";
    }


    // call averaging function, display message, add to student
    average_grade = get_average_grade();

    // cout lowest grade and average grade
    std::cout << "\n\nLowest grade to be dropped = " << get_grade_array_at_index(0);
    std::cout << "\n\nAverage after dropping lowest grade is " << get_final_grade();

    std::cout << "\n\n--------------------------------------------------------------------------------------------------------------------------\n\n";

    // enter switch statement, add grade letter to student based on average grade
    switch (average_grade)
    {
        // case x .... y will check if average_of_grades is in a range and enter a case accordingly. 
        case 90 ... 100: 
            add_final_letter_grade('A');
            break;
        case 80 ... 89:
            add_final_letter_grade('B');
            break;
        case 70 ... 79:
            add_final_letter_grade('C');
            break;
        case 60 ... 69:
            add_final_letter_grade('D');
            break;
        default:
            add_final_letter_grade('F');
            break;
    }


    // end message
    std::cout << "Thank you " << get_name() << ", the final grade for semester is " << get_final_letter_grade() << " at " << get_final_grade() << "\n";
    
    quit_grading(0);
}