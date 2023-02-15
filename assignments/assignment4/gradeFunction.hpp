/*
Name: William Ward
Course: COP3003 (CRN15015) - Programming II
Info: Assignment 3 - gradeFunction.hpp
*/

#include <string>
#include <array>
#include <iostream>
#include <math.h>

// student struct
struct STUDENT {
    std::string grade_level;
    std::string name; 
    int final_grade;
    char final_letter_grade;

    // member function prototypes
    void add_name(std::string);    
    void add_grade_level(std::string);
    void add_final_grade(int);
    void add_final_letter_grade(char);

    std::string get_name();
    std::string get_grade_level();
    int get_final_grade();
    char get_final_letter_grade();
};

std::string display_and_collect(std::string);
void quit_grading (int);
int get_grade ();
int get_average (std::array <int, 11> grade_array);