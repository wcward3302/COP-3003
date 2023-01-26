#include <iostream>
#include <array>

int main(){
    /*int number = 788;
    int counter = 0;

    while (number <= 1085){
        number = number + 20;
        counter++;
    }
    std::cout << counter << "\n";*/

    int user_input = 0;
    int counter = 0;
    std::array<int, 10> drink_choices;

    while (user_input != -1){
        std::cout << "What did you drink today?\n(0 = coffee, 1 = tea, 2 = sports drink)\nResponse: ";
        std:: cin >> user_input;
        
        if(user_input > 0){
            drink_choices[counter] = user_input;
            std::cout << counter <<"\n";
        }
        counter++;
    }

    counter = 0;
    for(auto num : drink_choices){
        std::cout << num <<"\n";
    }

    for (auto e : drink_choices){
        
    }
}
