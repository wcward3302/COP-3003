/*
Name: William Ward (wcward3302@eagle.fgcu.edu)
Course: COP3003 - Programming II
Info: Assignment 1
*/

#include <iostream>

int main () { // Main function
    int current_day = 0; // variable for user inputs
    int days_until_meeting = 0;
    int meeting_day = 0; // variable for calcuating day of week 

    std::cout << "\nWhat is the current day? (Monday = 1, Sunday = 7)\nResponse: ";
    std::cin >> current_day; // collect current day
    
    std::cout << "\nIn how many days will you be meeting with friends?\nResponse: ";
    std::cin >> days_until_meeting; // collect # of days until meeting
    
    meeting_day = ((current_day + days_until_meeting) % 7); // using equation from slides to calculate day of week for meeting
    
    if(meeting_day >= 5 || meeting_day == 0){ // output after determining day of week for the meeting. 0, 5, 6, 7 = weekend
        std::cout <<"\n\nGreat! Enjoy your fun weekend!\n\n";
    }
    else{
        std::cout << "\nOh, workday. Work is better with friends at least.\n\n";
    }
    return 0;
}
