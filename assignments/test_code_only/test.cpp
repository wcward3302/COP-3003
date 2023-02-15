#include <iostream>
#include <array>

std::string display_and_collect(std::string message){

    std::string x;
    std::cout << message;
    std::getline (std::cin, x);

    return x;
}

int main(){

    std::string name,grade_level, grade;
    std::array <int, 3> grade_array;
    int counter =0;

    std::string message_1 = "Please enter name: ";
    std::string message_2 = "Please enter grade level: ";
    std::string message_3 = "Please enter grade: ";

    name = display_and_collect(message_1);
    grade_level = display_and_collect(message_2);

    while (counter < 3){
        grade_array[counter] = std::stoi(display_and_collect(message_3));
        counter++;
    }
    
    std::cout << "Name = " << name << "\tGrade level = " << grade_level << "\n";
    for(auto x:grade_array){
        std::cout << x << "\t";
    }

    std::cout << "\n\n";
    return 0;
}