#include <iostream>

int main(){
    // variables
    int birth_year = 0;
    int current_year = 2023;
    bool validation = false;
    
    // Validate user input with while loop
    while (!validation){
        std::cout << "\nPlease enter birth year\nResponse: ";
        std::cin >> birth_year;

        if (birth_year >= 1000 && birth_year <= current_year){
            validation = true;
        }
        else{
            std::cout << "\nAHHH no you don't! Try again please...";
        }
    }
    
    // Check for young/old
    if ((current_year - birth_year) > 36){ // Might be a const variable
        std::cout << "\nAge = " << (current_year - birth_year) << ", Hello old\n\n";
    }
    else{
        std::cout << "\nAge = " << (current_year - birth_year)<<", Hello youngin'\n\n";
    }

    //check for even/odd
    if (((current_year - birth_year) % 2 ) == 0){ //no need for const variable
        std::cout << "Age = " << (current_year - birth_year) << ", Hello even\n\n";
    }
    else{
        std::cout << "Age = " << (current_year - birth_year)<<", Hello odd\n\n";
    }

    //check for lucky/unlucky
    if (((current_year - birth_year) % 11 ) == 0){ // could have been a constant variable
        std::cout << "Age = " << (current_year - birth_year) << ", Hello lucky\n\n";
    }
    else{
        std::cout << "Age = " << (current_year - birth_year)<<", Hello unlucky\n\n";
    }
}