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
    Student student;
    // initialize variables
    int loop_counter = 0, average_grade = 0;
    std::string name, grade_level;



    // NEW with this update - Function that will display provided message, collect and then return input!
    std::string get_name_message = "Please enter your name: ";
    std::string get_grade_level_message = "Please enter your grade level: ";

    name = display_and_collect(get_name_message);
    student.name = name;

    grade_level = display_and_collect(get_grade_level_message);
    student.grade_level = grade_level;



    // loop to collect all grades with get_grade input function (validation inside function)
    std::cout << "Enter grades - lowest score will be dropped!\n";
    while (loop_counter < 11){
        student.grade_array[loop_counter] = get_grade();
        loop_counter++;
    }



    // sort the array to make 0 element lowest grade and print
    std::sort(student.grade_array.begin(), student.grade_array.end());
    std::cout << "Grades are ";
    for (int x = 0; x < student.grade_array.size(); x++){
        std::cout << student.grade_array[x] << "\t";
    }



    // call averaging function, display message, add to student
    average_grade = get_average(student.grade_array);
    std::cout << "\n\nAverage after dropping lowest grade is " << average_grade << "\n\n";
    student.final_grade = average_grade;



    // enter switch statement, add grade letter to student based on average grade
    switch (average_grade)
    {
        // case x .... y will check if average_of_grades is in a range and enter a case accordingly. 
        case 90 ... 100: 
            student.final_letter_grade = 'A';
            break;
        case 80 ... 89:
            student.final_letter_grade ='B';
            break;
        case 70 ... 79:
            student.final_grade = 'C';
            break;
        case 60 ... 69:
            student.final_letter_grade = 'D';
            break;
        default:
            student.final_letter_grade = 'F';
            break;
    }
    

    // end message
    std::cout << "Thank you " << student.name << ", the final grade for semester is a " << student.final_letter_grade << " at " << student.final_grade << "\n";
    return 0;
}