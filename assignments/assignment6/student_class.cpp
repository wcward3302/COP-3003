/*
1. William Ward
2. CRN 15050 - COP3303
3. Assignment 6

info: Placed lines around explicit components for this assignment
*/


#include <iostream>
#include <array>
#include <string>

//using const arrays to check if input is valid, easy to update in the future by adding to this list
const std::array <std::string, 12> US_GRADE_LEVELS = {"1st grade", "2nd grade", "3rd grade", "4th grade", "5th grade", "6th grade", "7th grade", "8th grade" , "9th grade", "10th grade", "11th grade", "12th grade"};
const std::array <std::string, 12> UK_GRADE_LEVELS = {"year 1", "year 2", "year 3", "year 4", "year 5", "year 6", "year 7", "year 8", "year 9", "year 10", "year 11", "year 12"};
const std::array <std::string, 4> US_COLLEGE_GRADE_LEVELS = {"freshman", "sophomore", "junior", "senior"};
const std::array <std::string, 4> UK_COLLEGE_GRADE_LEVELS = {}; // Could not find anything about UK college grade levels :(

class Student {

//-------------------------------------------------------------Private member variables--------------------------------------------------------------------
    private:
    // private member variables
    std::array <int, 10> current_grades;
    int lowest_grade;
//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public:
    // public member variables
    std::string student_name;
    std::string grade_level;
    std::string major;

    private:
    // private member functions
    // takes string and returns it lowered
    std::string to_lower(std::string input){
        int x = 0;
        while(x < input.length()){
            input[x] = tolower(input[x]);
            x++;
        }
        return input;
    }
//-----------------------------------------------------Validate_grade()------------------------------------------------------------------------------------
    // take a string, will return true or false if the string is in either of the arrays
    bool validate_grade_level(std::string input_grade_level){
        
        std::string input = to_lower(input_grade_level);

        // check if input is in college grade list
        for(int x = 0; x < US_COLLEGE_GRADE_LEVELS.size(); x++){
            if (input == US_COLLEGE_GRADE_LEVELS[x]){
                return true;
            }
            if (input == UK_COLLEGE_GRADE_LEVELS[x]){
                return true;
            }
        }

        // check if input is in "primary" school level list
        for(int x = 0; x < US_GRADE_LEVELS.size(); x++){
            if (input == US_GRADE_LEVELS[x]){
                return true;
            }
            if (input == UK_GRADE_LEVELS[x]){
                return true;
            }
        }

        // if not in any of the lists, return false
        return false;
    }

//------------------------------------------------------convert_grade_level()------------------------------------------------------------------------------

    // takes in grade level string, converts to int
    long convert_grade_level(std::string input_grade_level){
        // if the grade is valid, 
        if (validate_grade_level(input_grade_level)){
            
            std::string input = to_lower(input_grade_level);

            // check if input is in college grade list}
            for(int x = 0; x < US_COLLEGE_GRADE_LEVELS.size(); x++){
                if (input == US_COLLEGE_GRADE_LEVELS[x]){
                    return x + 1;
                }
                if (input == UK_COLLEGE_GRADE_LEVELS[x]){
                    return x + 1;
                }
            }

            // check if input is in "primary" school level list
            for(int x = 0; x < US_GRADE_LEVELS.size(); x++){
                if (input == US_GRADE_LEVELS[x]){
                    return x + 1;
                }
                if (input == UK_GRADE_LEVELS[x]){
                    return x + 1;
                }
            }
        }
    
        // if not valid and if not in lists, return default 9th grade
        return 9;
    }
//---------------------------------------------------------------------------------------------------------------------------------------------------------


    public:
    // public member functions
//--------------------------------------------------------------3 constructors-----------------------------------------------------------------------------
    // default constructor - get none, default values
    Student(){
        this->student_name = "no_name";
        this->grade_level = "Sophomore";
        this->major = "computer science";
    }

    // constructor 1 - get name, default the rest
    Student(std::string name){
        this->student_name = name;
        this->grade_level = "Sophomore";
        this->major = "computer science";
    }

    // constructor 2 - get all ( string grade level )
    Student(std::string name, std::string grade_level, std::string major){
        this->student_name = name;
        this->grade_level = grade_level;
        this->major = major;
    }

    // constructor 3 - get all ( int grade level )
    Student(std::string name, int grade_level, std::string major){
        this->student_name = name;
        this->grade_level = std::to_string(grade_level);
        this->major = major;
    }
//---------------------------------------------------------------------------------------------------------------------------------------------------------

    // function takes in a number to determine what information to collect
    void update_info(int type){

        switch (type)
        {
        case 0: // 0 mean get everything
            std::cout << "\nPlease enter name: ";
            std::getline(std::cin, this->student_name);

            std::cout << "\nPlease enter grade level: ";
            std::getline(std::cin, this->grade_level);

            std::cout << "\nPlease enter major: ";
            std::getline(std::cin, this->major);
            break;
        
        case 1: // get grade level and major 

            std::cout << "\nPlease enter grade level: ";
            std::getline(std::cin, this->grade_level);

            std::cout << "\nPlease enter major: ";
            std::getline(std::cin, this->major);
            break;
        
        // more cases can be added to collect different components as they becomes necessary

        default:
            break;
        }
    }

    // getters, pretty prints info
    void display_info(){
        std::cout << "Name:        " << this->student_name << "\n";
        std::cout << "Grade level: " << this->grade_level << "\n";
        std::cout << "Major:       " << this->major << "\n";
    }

    void display_grades(){

        std::cout << "Lowest grade is " << this->lowest_grade << "\n";

        for (int x = 0; x < this->current_grades.size(); x++){
            std::cout << "Grade " << x + 1 << " = " << this->current_grades[x] << "\t";
        }
    }

    void pretty_print_for_testing(std::string x){
        std::string yes_or_no;
        if(validate_grade_level(x) == 1){
            yes_or_no = "yes";
        }
        else{
            yes_or_no = "no";
        }

        std::cout << "Valid check   - " <<  x << " is in list = " << yes_or_no << "\n";
        std::cout << "Convert check - " <<  x << " converted is = " << convert_grade_level(x) << "\n";
        std::cout << "\n";
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

    // other functions for operating grade array component

    // get grades is called, starts a loop, will auto add to array or lowest grade member
    void get_grades(){
        this->lowest_grade = -2;
        int counter = 0, input;

        for (int x = 0; x < this->current_grades.size() + 1; x++){

            bool valid_check = false;

            while(!valid_check){
                std::cout << "Please enter grade: ";
                std::cin >> input;

                // if the input is within range and the cin was not passed bad input, pass true and break from nested while loop
                if(input >= 0 && input <= 100 && std::cin.good()){ 
                    valid_check = true;
                }

                // if user wants to quit early
                else if(input == -1){
                    quit_grading(-1);
                }

                // else, display a message, clear cin buffer and data, repeat loop until response is valid. Stay on target... 
                else{
                    std::cout << "please enter a valid response (" << 0 << " - " << 100 << ")\n";
                    std::cin.clear();
                    std::cin.ignore(100,'\n');
                }
            }

            // if lowest grade = -2, then this is first grade and should be lowest
            if (this->lowest_grade == -2){
                this->lowest_grade = input;
            }
            else{
                // if lowest grade is larger than current grade, move LG to array, LG to current
                if (this->lowest_grade > input){
                    this->current_grades[x-1] = this->lowest_grade;
                    this->lowest_grade = input;
                }

                // all else, add to the next spot in the array
                else if(this->lowest_grade <= input){
                    this->current_grades[x-1] = input;
                }
            }
        }
    }

    // returns the average by calculating sum of all elements in member array, returns value divided by size
    int get_average(){
        int sum, average;
        for(int x = 0; x < this->current_grades.size(); x++){
            sum = sum + this->current_grades[x];
        }

        average = sum / this->current_grades.size();
        return average;
    }

    // takes the final grade and returns a letter grade based on value
    char get_grade_letter(int final_grade){
        switch (final_grade)
        {
            // case x .... y will check if average_of_grades is in a range and enter a case accordingly. 
            case 90 ... 100: 
                return 'A';
            case 80 ... 89:
                return 'B';
            case 70 ... 79:
                return 'C';
            case 60 ... 69:
                return 'D';
            default:
                return 'F';
        }
    }
};