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

void quit_grading (int);
bool is_valid(int, int, int);
int get_grade ();


int main(){
    Student student = Student();

    string name, yes_no_input; 
    std::array <int, 11> grade_array;

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

    for (int x = 0; x <= 11; x++){
        grade_array[x] = get_grade();
    } 


    grades.set_grades(grade_array);

    std::cout << "\n----------------------------------------------------------------------------------\n";
    
    
    std::cout << "Would you like to see all of the entered grades? (Y or N): ";
    std::cin >> yes_no_input;

    if(yes_no_input[0] == 'Y' || yes_no_input[0] == 'Y'){
        grades.display_grades();
    }

    std::cout << "\nAverage = " << grades.get_average() << "\n";
    std::cout << "\nLowest is " << grades.get_lowest_grade() << "\n";

    return 0;
}


// quit grading based on user input
void quit_grading (int x){

    // switch based on input from main, once finished, the program will exit
    switch (x){
    case 1:
        // reason -1
        std::cout << "\nAn error has occurred, please try again.\n\n";
        break;
    case 0:
        // reason 0, terminate
        std::cout << "\nThank you for using our product!\n\n";
        exit (1);
    case -1:
        // reason 1
        std::cout << "\nSorry you had to quit early. Thank you for using out product!\n\n";
        exit (1);
        break;
    default: // default case just skips the switch
        break;
    }
}

// check if input is valid, repeat until true. Can now use to check future inputs between min and max
bool is_valid(int input_number, int min, int max){

        // if the input is within range and the cin was not passed bad input, pass true and break from nested while loop
        if(input_number >= min && input_number <= max && std::cin.good()){ 
            return true;
        }

        // else, display a message, clear cin buffer and data, repeat loop until response is valid. Stay on target... 
        else{
            std::cout << "please enter a valid response (" << min << " - " << max << ")\n";
            std::cin.clear();
            std::cin.ignore(100,'\n');
            return false;
        }
}

// is called to get a grade, handles input and validation before returning value
int get_grade (){

    // initialize variables
    float user_input = 0;
    bool user_input_valid = false;

    // loop will be false until user input is validated and passed true flag
    while(!user_input_valid){ 
        std::cout << "Enter grade: ";
        std::cin >> user_input;

        // if user inputs -1, code exits
        if (user_input == -1){
            quit_grading(-1);
        }

        // if user input is checked to be valid, break from while loop
        else if (is_valid(user_input, 0, 100)){ // uses new "is_valid()" function to check validity!
            user_input_valid = true;
        }
        
        // if user_input_valid is not made true by this point, keep looping until true
    }

    // return the user input once validated
    return user_input;
}