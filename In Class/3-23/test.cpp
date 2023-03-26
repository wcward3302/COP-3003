#include <vector>
#include <iostream>
#include <array>

const std::array <std::string, 4> suits = {"clubs", "diamonds", "spades", "hearts"};
const std::array <std::string, 13> values = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king"};


int main(){

    struct Card {

        int value;  // 1-13
        std::string face;
        std::string suit;

    };

    std::vector <Card> deck;

    for (int i = 0; i < 4; i++){    // will loop 4 times, 1 for each suit
        for (int j = 1; j <= 13; j++){  // will loop 13 total times but starts at 1
            deck.push_back(Card{j, values[j-1], suits[i]});    
        }
    }
    
    for (const auto& card : deck ){
        std::cout << "Card " << card.value << " is " << card.face << " of " << card.suit << "\n";
    }

    return 0;
}
