/*
Name: William Ward
Course: COP3003 (CRN15015) - Programming II
Info: Assignment 3 - gradeFunction.hpp
*/
#ifndef GRADEFUNCTION
#define GRADEFUNCTION

#include <string>
#include <array>
#include <iostream>
#include <math.h>

// student struct
struct Student {
    std::string grade_level;
    std::string name; 
    int final_grade;
    char final_letter_grade;
    std::array <int, 11> grade_array;
};

std::string display_and_collect(std::string);
void quit_grading (int);
int get_grade ();
int get_average (std::array <int, 11> grade_array);

#endif