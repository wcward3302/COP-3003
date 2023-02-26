/*
1. William Ward
2. CRN 15050 - COP3303
3. Assignment 5
*/

#include <iostream>

#include "grade_class.cpp"

//--------------------------------------------Main Function--------------------------------------------//

int main(){
    // create class instances
    Student student = Student();
    Grades grade = Grades();

    std::string yes_no_check1, yes_no_check2, name;

    std::cout << "\n-------------------------------------------Section 1--------------------------------------------\n";

    // get user name
    std::cout << "\nPlease enter your name: ";
    std::getline (std::cin, name);

    // insert name into student object
    student.set_name(name);

    // display current info and ask if user wants to update
    std::cout << "\nIs the following information correct?\n\n";
    student.print_info();
    std::cout << "\nWould you like to update the information? Yes to update, No to continue\nResponse: ";
    std::getline(std::cin, yes_no_check1);

    // if first char of input is Y, call update info function to collect the values the user has not provided yet
    if (yes_no_check1[0] == 'Y' || yes_no_check1[0] == 'y'){
        student.update_data();
        // display updated info
        std::cout << "\n\nUpdated information: \n";
        student.print_info();
    }


    std::cout << "\n-------------------------------------------Section 2--------------------------------------------\n";

    // get grades from user. Call collect grade array function, will loop and get grades w/ valid checking
    std::cout << "\nPlease enter your grades. (-1 to quit)\n";
    grade.collect_grade_array();

    // user input stored in temp array, this will put top 10 in grade array and store lowest in lowest grade member
    grade.set_grades();

    // ask if user wants to see the grade array
    std::cout << "\nWould you like to see your grades without the lowest score? (YES or NO)\nResponse: ";
    //std::getline(std::cin, yes_no_check2);
    std::cin >> yes_no_check2;

    // same as the above y/n check
    if (yes_no_check2[0] == 'Y' || yes_no_check2[0] == 'y'){
        grade.display_grades();
    }

    // display exit message
    std::cout << "\n\nThank you " << student.get_name() << ", your final average grade is " << grade.get_average() << " with a letter grade of " << grade.get_grade_letter(grade.get_average()) << "\n";

    grade.quit_grading(0);
}



