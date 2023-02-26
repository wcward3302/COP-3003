/*
Move our grade code to a Class should have:
    a scalar lowest grade
    an array of all the grades (the 10 not lowest grades)
    A display all grades function which prints all of these
    Move other functions and adjust to work in class

*/

#include <array>
#include <iostream>
#include <math.h>


class Grades {
private:
    // private class members
    int lowest_grade;
    std::array <int, 10> grade_array;
    std::array <int, 11> temp_grade_array;

public:
    // made all functions public for main to access
    // default constructor
    Grades(){
        this->lowest_grade = 0;
        for (int x = 0; x < this->grade_array.size(); x++){
            this->grade_array[x] = 0;
        }
    }

    // getters and setters
    int get_lowest_grade(){
        return this->lowest_grade;
    }

    std::array <int, 10> get_grade_array(){
        return this->grade_array;
    }

    // function to display grade array
    void display_grades(){

        std::cout << "Lowest grade is " << this->lowest_grade << "\n";

        for (int x = 0; x < this->grade_array.size(); x++){
            std::cout << "Grade " << x + 1 << " = " << this->grade_array[x] << "\n";
        }
    }

    // no member for average, so this function takes member array and return the average
    int get_average(){
        int sum =0, average = 0;

        for (int x = 0; x < this->grade_array.size(); x++){
            sum = sum + this->grade_array[x];
        }

        average = sum / this->grade_array.size();

        return average;
    }

    // takes the temp array and inserts top 10 into grade array and lowest into lowest grade member
    void set_grades(){

        std::sort(this->temp_grade_array.begin(), this->temp_grade_array.end());

        this->lowest_grade = this->temp_grade_array[0];

        for(int x = 1; x < this->temp_grade_array.size(); x++){
            this->grade_array[x-1] = this->temp_grade_array[x];
        }
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

    // call once to collect all grades consecutivly
    void collect_grade_array(){
        for (int x = 0; x <= 11; x++){
            this->temp_grade_array[x] = get_grade();
        } 
    }

    char get_grade_letter(int average_grade){
        // enter switch statement, add grade letter to student based on average grade
        switch (average_grade)
        {
            // case x .... y will check if average_of_grades is in a range and enter a case accordingly. 
            case 90 ... 100: 
                return 'A';
                break;
            case 80 ... 89:
                return 'B';
                break;
            case 70 ... 79:
                return 'C';
                break;
            case 60 ... 69:
                return 'D';
                break;
            default:
                return 'F';
                break;
        }
    }


};

