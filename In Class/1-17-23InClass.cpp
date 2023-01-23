
/*
1: Initiallize variables
2: Display options
3: "What did you drink"
4: Repeat 2-3
    - until user is done
5: Sum drinks for the day. 
    - Will need a counter in a switch statement to keep trank of drinks(?)
    - Use an array to keep track of hydration level
6. Display message
    - Response could be based on hydration level
*/

#include <iostream>

int main(){
    //variables
    int hydration_level = 8;
    int user_input = 0;
    int summation_array[] = {};
    int summated_value = 0;
    int end_of_day_hydration = 0;

    std::cout << "Hello, what are you drinking today?\n";
    std::cout << "0 = water\n1 = tea\n2 = sports drink\n3 = energy drink\n4 = milk\n5 = coffee\nResponse: ";
    std::cin >> user_input;

    switch (user_input)
    {
    case 0:
        std::cout << "Water";
        break;
    case 1:
        std::cout << "Tea";
        break;
    
    // ............
    
    default:
        std::cout << "hmm.";
        break;
    }

    //  TBD, probably will use a while loop to collect lots of users input
    //  
    
    if(end_of_day_hydration >= 5){
        std::cout <<"Great job!";
    }
    else{
        std::cout << "Do better.";
    }

}