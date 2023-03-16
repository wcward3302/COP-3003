#include <iostream>

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

std::string get_last_chars (std::string input){

    if(input.size() <= 2){
        return "Too small";
    }

    std::string output;

    for (int x = 0; x < 2; x++){
        output.push_back(input[input.size()-x-1]);
        output.push_back(' ');
    }

    return output;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

std::string get_last_chars (std::string input, int input_num){

    if(input.size() <= 2){
        return "Too small";
    }

    std::string output;

    for (int x = 0; x < input_num; x++){
        output.push_back(input[input.size()-x-1]);
        output.push_back(' ');
    }

    return output;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(){

    std::string apple = "Apple", bat = "Bat", bad_wifi = "BadWifi";

    int user_test_num;


    std::cout << "\n1 - " << get_last_chars(apple);
    std::cout << "\n2 - " << get_last_chars(bat);
    std::cout << "\n3 - " << get_last_chars(bad_wifi);

    std::cout << "\n\n";
    exit(0);
}