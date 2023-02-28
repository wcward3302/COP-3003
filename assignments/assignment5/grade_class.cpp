/*
1. William Ward
2. CRN 15050 - COP3303
3. Assignment 5
*/

#include <iostream>
#include <array>
#include <math.h>

//-----------------------------------------------------------------------------------------Grades Class-------------------------------------------------------------------------------------------//

class Grades {
    
private:
    // private class members
    int lowest_grade;
    std::array <int, 10> grade_array;

public:
    // made all functions public for main to access
    // default constructor
    Grades(){
        this->lowest_grade = -2;
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
            std::cout << "Grade " << x + 1 << " = " << this->grade_array[x] << "\t";
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

    // get grades is called, starts a loop, will auto add to array or lowest grade member
    void get_grades(){

        int counter = 0, input;

        for (int x = 0; x < this->grade_array.size() + 1; x++){

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
                    this->grade_array[x-1] = this->lowest_grade;
                    this->lowest_grade = input;
                }

                // all else, add to the next spot in the array
                else if(this->lowest_grade <= input){
                    this->grade_array[x-1] = input;
                }
            }
        }
    }

    // returns the average by calculating sum of all elements in member array, returns value divided by size
    int get_average(){
        int sum, average;
        for(int x = 0; x < this->grade_array.size(); x++){
            sum = sum + this->grade_array[x];
        }

        average = sum / this->grade_array.size();
        return average;
    }

    // takes the final grade and returns a letter grade based on value
    char get_grade_letter(int final_grade){
        switch (final_grade)
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
