/*
1. William Ward
2. CRN 15050 - COP3303
3. Assignment 6
*/



#include "student_class.cpp"
#include <iostream>


int main(){

    Student student = Student();

    std::cout << "\n-------------------------------------------Section 1--------------------------------------------\n";

    // some test values for function
    std::string test_1 = "Junior", test_2 = "fRESHMAN", test_3 = "Year 9", test_4 = "yEaR 7", test_5 = "10Th GRADE", test_6 = "no grade";
    
    // use print function to test new private functions
    student.pretty_print_for_testing(test_1);
    student.pretty_print_for_testing(test_2);
    student.pretty_print_for_testing(test_3);
    student.pretty_print_for_testing(test_4);
    student.pretty_print_for_testing(test_5);
    student.pretty_print_for_testing(test_6);

    // while loop will allow continuous entering of different grade levels to test, [0] = n will exit
    std::cout << "\n";
    std::string loop_continue;
    while (loop_continue[0] != 'N' && loop_continue[0] != 'n'){

        std::cout << "Please enter your own grade level (n to quit): ";
        std::getline(std::cin, loop_continue);
        if(loop_continue[0] != 'N' && loop_continue[0] != 'n'){
            student.pretty_print_for_testing(loop_continue);
        }
    }

    // ask if want to continue with the rest of the program or exit now
    std::string check_continue;
    std::cout << "\nContinue to student info and grades? Yes to continue, No to quit: ";
    std::getline(std::cin, check_continue);

    if(check_continue[0] != 'Y' && check_continue[0] != 'y'){
        student.quit_grading(0);
    }


    std::cout << "\n-------------------------------------------Section 2--------------------------------------------\n";

    // not much has changed here since last assignment, just changes to work with new class structuring.
    std::string yes_no_check1, yes_no_check2, name;

    // get user name and insert into object
    std::cout << "\nPlease enter your name: ";
    std::getline (std::cin, student.student_name);

    // display current info and ask if user wants to update
    std::cout << "\nIs the following information correct?\n\n";
    student.display_info();

    std::cout << "\nWould you like to update the information? Yes to update, No to continue\nResponse: ";
    std::getline(std::cin, yes_no_check1);

    // if first char of input is Y, call update info function to collect the values the user has not provided yet
    if (yes_no_check1[0] == 'Y' || yes_no_check1[0] == 'y'){
        student.update_info(1);
        // display updated info
        std::cout << "\n\nUpdated information: \n";
        student.display_info();
    }



    std::cout << "\n-------------------------------------------Section 3--------------------------------------------\n";

    // get grades from user. Call collect grade array function, will loop and get grades w/ valid checking
    std::cout << "\nPlease enter your grades. (-1 to quit)\n";
    student.get_grades();
    // ask if user wants to see the grade array

    std::cout << "\n\nShow all grades? (Yes or No): ";
    std::cin >> yes_no_check2;

    // same as the above y/n check
    if (yes_no_check2[0] == 'Y' || yes_no_check2[0] == 'y'){
        std::cout << "\n\n";
        student.display_grades();
        std::cout << "\n";
    }

    // display exit message
    std::cout << "\n\nThank you " << student.student_name << ", your final average grade is " << student.get_average() << " with a letter grade of " << student.get_grade_letter(student.get_average()) << "\n";

    student.quit_grading(0);
}