/*
Name: William Ward
Course: COP3003 (CRN15015) - Programming II
Info: Assignment 3

1. Loop should remain in main() do not move loop to separate function
2. grades should be inserted to array after grade is gotten (in function) and this passed to the summation function
        - Lowest grade should still be removed in main (so still getting 11 grades and removing 1)
*/

#include <iostream>
#include <array>

/*
3. Create a brand new function: quit_grading (or quitGrading) use the naming style that fits your code
        - Pass it a number (0, 1, -1) which it uses to determine why we are quitting
            - Default should print "Thank you for using our product!"
            - 1 should print "Sorry you had to quit early. Thank you for using our product!"
            - -1 should print "An error occurred, please try again"
        - should quit the program after printing message
*/

void quit_grading (int x){
    // switch based on input from main, once finished, the program will exit
    switch (x){
    case -1:
        // reason -1
        std::cout << "an error has occurred, please try again.\n";
        break;
    case 0:
        // reason 0, terminate
        std::cout << "Thank you for using our product!\n";
        exit (1);
    case 1:
        // reason 1
        std::cout << "Sorry you had to quit early. Thank you for using out product!\n";
        exit (1);
        break;
    default: // default case just skips the switch
        break;
    }
}

/*
4. Refactor our portion getting grades to a new function called: get_grade
        - Should take no parameters
        - Will ask the user if they want to continue entering grades
            - If not then pass 1 to quit_grading
        - Will then ask for their grade
        - Will validate the grade (is it between 0 and 100 when truncated)
            - If its valid it will return it
            - If its not it will run quit_grading with a -1
*/

int get_grade (){
    std::string continue_check;
    float user_input = 0;
    bool user_input_valid = false;

    std::cout << "Do you want to continue entering grades? (y to continue)\nResponse: ";
    std::cin >> continue_check;

    if (char(continue_check[0]) == 'y' || char(continue_check[0]) == 'Y'){
        while(!user_input_valid)
        { 
            std::cout << "Enter grade: ";
            std::cin >> user_input;

            // if the input is within range and the cin was not passed bad input, pass true and break from nested while loop
            if(user_input >= 0 && user_input <= 100 && std::cin.good()){ 
                user_input_valid = true;
            }

            // else, display a message, clear cin buffer and data, repeat loop until response is valid. Stay on target... 
            else{
                std::cout << "please enter a valid response (0-100)\n";
                std::cin.clear();
                std::cin.ignore(100,'\n');
            }
        }
    }
    else{
        quit_grading(1);
    }
    return user_input;
}

int get_grade_all (){
    float user_input = 0;
    bool user_input_valid = false;

    while(!user_input_valid){ 
        std::cout << "Enter grade: ";
        std::cin >> user_input;

        // if the input is within range and the cin was not passed bad input, pass true and break from nested while loop
        if(user_input >= 0 && user_input <= 100 && std::cin.good()){ 
            user_input_valid = true;
        }

        // else, display a message, clear cin buffer and data, repeat loop until response is valid. Stay on target... 
        else{
            std::cout << "please enter a valid response (0-100)\n";
            std::cin.clear();
            std::cin.ignore(100,'\n');
        }
    }

    return user_input;
}

/*
5. Refactor average code to a function called get_average
        - After all grades gotten (all 10) 
            - Call get_average passing the array as a parameter
            - return the average for the passed array
*/

int get_average (std::array <int, 11> grade_array){
    int sum = 0;
    int average = 0;
    int counter = 0;
    
    for (int x = 1; x < 11; x++){
        sum = sum + grade_array[x];
        counter++;
    }

    average = sum / counter;

    return average;
}

/*
6. In Main it will then
        - Print out the same message as in assignment 2 with the average and final letter grade based on returned value
        - all quit_grading with 0
*/

int main(){

    int loop_counter = 0, average_grade = 0;
    std::string user_selection;
    std::array<int, 11> user_input_array;

    std::cout << "Do you want to enter all grades now? Yes to continue - ";
    std::cin >> user_selection;

    if (char(user_selection[0]) == 'y' || char(user_selection[0] == 'Y')){
        while (loop_counter < 11){
            user_input_array[loop_counter] = get_grade_all();
            loop_counter++;
        }
    }
    else{
        while (loop_counter < 11){
            user_input_array[loop_counter] = get_grade();
            loop_counter++;
        }
    }

    std::sort(user_input_array.begin(), user_input_array.end());

    average_grade = get_average(user_input_array);

    std::cout << "\n\nAverage = " << average_grade << "\n\n";
    
    std::cout << "\nYour final grade was ";
    switch (average_grade)
    {
        // case x .... y will check if average_of_grades is in a range and enter a case accordingly. 
        case 90 ... 100: 
            std::cout << "A";
            break;
        case 80 ... 89:
            std::cout << "B";
            break;
        case 70 ... 79:
            std::cout << "C";
            break;
        case 60 ... 69:
            std::cout << "D";
            break;
        default:
            std::cout << "F";
            break;
    }

    std::cout << "\n\n";

}