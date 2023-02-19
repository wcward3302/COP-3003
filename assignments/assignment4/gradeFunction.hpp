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

// functions to add data to the struct instance
void add_name(std::string);
void add_grade_level(std::string);
void add_final_grade(int);
void add_final_letter_grade(char);
void add_to_grade_array(int, int);


// functions to return data from struct members
std::string get_name();
std::string get_grade_level();
int get_final_grade();
char get_final_letter_grade();
int get_average_grade();
int get_grade_array_at_index(int);
int get_grade_array_size();

// functions to handle logic and math
std::string display_and_collect(std::string);
void quit_grading (int);
int get_grade ();
int get_average (std::array <int, 11> );

#endif