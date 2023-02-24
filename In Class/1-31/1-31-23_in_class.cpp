#include <iostream>
#include <array>
#include <iomanip>

const std::array <int, 5> SANDWICHES = {0, 1199, 1099, 899, 899};
const std::array <int, 5> DRINKS = {0, 599, 499, 99, 299};
const std::array <int, 5> SIDES = {0, 199, 199, 199, 499};

// added another function to call to get user input
int get_input(){ 
    int selection = 0;
    std::cout << "Selection : ";
    std::cin >> selection;
    return selection;
}

// given the selections for sammy, drink, and side, return total (in cents)
int get_total(int sandwich_choice, int drink_choice, int side_choice){

    int total = 0;

    total = SANDWICHES[sandwich_choice] + DRINKS[drink_choice] + SIDES[side_choice];
    total = total + (total * 0.06);

    return total;
}

// display menu, collect input via get_choice(), return total
int get_choice(){

    int sandwich_choice = 0, drink_choice = 0, side_choice = 0;

    std::cout << "\n\n1. Meatball ($11.99)\t\t2. Chicken ($10.99)\t\t3. Ham ($8.99)\t\t4. Tuna ($8.99)\n(Skip = 0)\n";
    sandwich_choice = get_input();

    std::cout << "\n\n1. Coke ($5.99)\t\t2. Pepsi ($4.99)\t\t3. Water ($0.99)\t\t4. Coffee ($2.99)\n(skip = 0)\n";
    drink_choice = get_input();

    std::cout << "\n\n1. Chips ($1.99)\t\t2. Soup ($1.99)\t\t3. Salad ($1.99)\t\t4. Soup & Salad ($4.99)\n(skip = 0)\n";
    side_choice = get_input();

    return get_total(sandwich_choice, drink_choice, side_choice);
}

// call the functions, do some conversions to do all math in cents
int main (){
    
    int total = get_choice();
    double payment = 0;
    int payment_int = 0;
    std::cout << "\n\nTotal is = $" << double(total) / 100 << "\nPlease enter payment amount: $";
    std::cin >> payment;
    
    payment_int = int(payment * 100);

    if (total > payment_int){
        std::cout << "Still owe = $" << double(total - payment_int) / 100;
    }
    else{
        std::cout << "Change is = $" << double(payment_int - total) / 100;
    }
    std::cout << "\n\n\n";
}