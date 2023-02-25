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
using std::string;

int main(){
    Student student = Student();

    string name, yes_no_input; 

    std::cout << "Enter name: ";
    name = "Testing";
    //std::cin >> name;

    student.set_name(name);
    
    std::cout << "\nIs the following information correct?\n";

    std::cout << student.get_name() << "\n";
    std::cout << student.get_grade_level() << "\n";
    std::cout << student.get_major() << "\n";

    std::cout << "If not, please type Y: ";
    //std::cin >> yes_no_input;

    Grades grade = Grades();

    grade.display_grades();

    std::cout << grade.get_average();

}