/*
The main program should now
    instance the Student class and assignments structure
    get the student's name and set it
    display the default gradelevel and major (from the class) and ask if this is correct
        if its not get new values for them and set it
    get all the grades as normally and calculate as normally
        only now we use the structure to see the lowest grade and check directly against that record
*/

#include <iostream>
#include "grade_class.cpp"
#include "student_class.cpp"


int main(){
    Student student = Student();

    std::string name, yes_no_input; 

    std::cout << "\n----------------------------------------------------------------------------------\n";
    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    student.set_name(name);
    
    std::cout << "\nIs the following information correct?\n";
    student.print_info();

    std::cout << "If correct, type Yes: ";
    std::getline(std::cin, yes_no_input);

    if(yes_no_input[0] != 'Y' || yes_no_input[0] != 'Y'){
        student.update_data();
    }

    std::cout << "Current information:\n\n";
    student.print_info();
    
    std::cout << "\n----------------------------------------------------------------------------------\n";
    std::cout << "Enter grades\nLowest score will be dropped\n\n";

    Grades grades = Grades();

    grades.collect_grade_array();
    grades.set_grades();


    std::cout << "\n----------------------------------------------------------------------------------\n";
    
    
    std::cout << "Would you like to see all of the entered grades? (Y or N): ";
    std::cin >> yes_no_input;

    if(yes_no_input[0] == 'Y' || yes_no_input[0] == 'Y'){
        grades.display_grades();
    }


    std::cout << "Thank you " << student.get_name() << ", the final grade for semester is " << grades.get_average() << " at " << grades.get_grade_letter(grades.get_average()) << "\n\n";

    return 0;
}



