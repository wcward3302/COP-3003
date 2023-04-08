#include <iostream>

std::string current_function (std::string input){


}

int main(){
    std::string input = "bob\nMarsh\n11\n12\n1978";

    std::cout << current_function(input);

}


/*
#include <iostream>
#include <array>
#include <vector>

int main() {
    // change this from an array to using a vector
    std::vector <int> hometeam_scores;

    // hint: you won't need a counter where your going
    while(true) {
        int cur_score = 0;

        std::cout << "Enter a Score between 0 and 100 (-1 to exit): " << std::endl;
        std::cin >> cur_score;
        if (cur_score < 0){
            break;
        } 
        
        else if (cur_score <= 100){
            hometeam_scores.push_back(cur_score);
        }
        
        else {
            std::cout << "You need to enter a number between 1 and 100" << std::endl;
        }
    }

    std::cout << "Your scores are:" << std::endl;
    for (const auto s : hometeam_scores) {
        std::cout << "\t" << s << std::endl;
    }
    return 0;
}
*/