/*

Make a header file called gradefunctions
    you can use whichever naming convention you like for this and either .h or .hpp for the extension
Create and make a gradefunction.cpp file with any logic needed due to the prototypes in the header
Our grades array (whatever you named it) can be used with this without being global but is not really complete
    Because the scope can be limited by adding it to a file - we can set it up in one of them
    So add it to the header or cpp file
        think about which it should be in to limit the scope best
        there is a correct place to put it
Add one struct for a Student (will put in same scope as array)
    Should have members for gradelevel, name (full), final_grade (the final average), and final_letter_grade (the letter grade)
    can name these in any way that meets style guide
Add functions for getting student data and adding to struct
    Including storing the final average as that member
    These should be external functions from struct at this point
Code should function in same was as before but final message should include name
    "Thank you, <name here>, the final grade for semester is a B at 89%"

*/

#include <string>
#include <array>
#include <iostream>
#include "gradeFunction.hpp"

int main(){

    // put array here because we dont need other cpp files that access the .hpp to access this array
    std::array<int, 11> user_input_array;


    STUDENT student; // create instance 
    std::string name, grade_level;

    std::cout << "Please enter name: "; // get name
    std::getline(std::cin, name);
    student.add_name(name);

    std::cout << "Please enter grade level: "; // get grade_level
    std::getline(std::cin, grade_level);
    student.add_grade_level(grade_level);

    // initialize variables
    int loop_counter = 0, average_grade = 0;
    std::string user_selection;

    // ask user if they want to input all grades now or specify on a per-grade basis (I DEFINITELY did not add this to make testing easier...)
    std::cout << "Do you want to enter all grades now? Yes to continue - ";
    std::cin >> user_selection;

    std::cout << "Enter grades - lowest score will be dropped!\n";

    // if user wants to enter all grades now...
    if (char(user_selection[0]) == 'y' || char(user_selection[0] == 'Y')){
        while (loop_counter < 11){
            user_input_array[loop_counter] = get_grade_all();
            loop_counter++;
        }
    }

    // use function where user will specify they want to continue on a per-grade basis
    else{
        while (loop_counter < 11){
            user_input_array[loop_counter] = get_grade();
            loop_counter++;
        }
    }

    for (int x = 0; x < user_input_array.size(); x++){
        std::cout << "\nGrade " << x + 1 << " is " << user_input_array[x];
    }

    // sort the array to make 0 element lowest grade
    std::sort(user_input_array.begin(), user_input_array.end());

    average_grade = get_average(user_input_array);

    std::cout << "\n\nAverage after dropping lowest grade is " << average_grade << "\n\n";

    student.add_final_grade(average_grade);
    
    switch (average_grade)
    {
        // case x .... y will check if average_of_grades is in a range and enter a case accordingly. 
        case 90 ... 100: 
            student.add_final_letter_grade('A');
            break;
        case 80 ... 89:
            student.add_final_letter_grade('B');
            break;
        case 70 ... 79:
            student.add_final_letter_grade('C');
            break;
        case 60 ... 69:
            student.add_final_letter_grade('D');
            break;
        default:
            student.add_final_letter_grade('F');
            break;
    }


    std::cout << "Thank you " << student.get_name() << ", the final grade for semester is a " << student.get_final_letter_grade() << " at " << student.get_final_grade();

    std::cout << "\n\n";

}