/*
Name: William Ward
Course: COP3003 (CRN15015) - Programming II
Info: Assignment 3

1. Loop should remain in main() do not move loop to separate function
2. grades should be inserted to array after grade is gotten (in function) and this passed to the summation function
        - Lowest grade should still be removed in main (so still getting 11 grades and removing 1)
3. Create a brand new function: quit_grading (or quitGrading) use the naming style that fits your code
        - Pass it a number (0, 1, -1) which it uses to determine why we are quitting
            - Default should print "Thank you for using our product!"
            - 1 should print "Sorry you had to quit early. Thank you for using our product!"
            - -1 should print "An error occurred, please try again"
        - should quit the program after printing message
4. Refactor our portion getting grades to a new function called: get_grade
        - Should take no parameters
        - Will ask the user if they want to continue entering grades
            - If not then pass 1 to quit_grading
        - Will then ask for their grade
        - Will validate the grade (is it between 0 and 100 when truncated)
            - If its valid it will return it
            - If its not it will run quit_grading with a -1
5. Refactor average code to a function called get_average
        - After all grades gotten (all 10) 
            - Call get_average passing the array as a parameter
            - return the average for the passed array
6. In Main it will then
        - Print out the same message as in assignment 2 with the average and final letter grade based on returned value
        - all quit_grading with 0
*/

#include <iostream>
#include <array>

void quit_grading (int x){
    // if x is 1, -1, or 0...
}

int get_grade (int x){
    // validate input, 
    return 0;
}

int get_average (int grade_array[], int size_of_grade_array){
    int sum = 0;
    int average = 0;
    for (int x = 0; x < size_of_grade_array; x++){
        sum = sum + grade_array[x];
    }

    average = sum / size_of_grade_array;
    return average;
}

int main(){
    int grade_array [] = {91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    std::cout << "average is " << get_average(grade_array, sizeof(grade_array)/sizeof(int)) << "\n";
}