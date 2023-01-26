#include <iostream>

// function one, summation
int summation(int x, int y)
{
    int output = 0;

    // basic summation for loop, will add 'x' to 'x', 'y' times
    for (int i = 0; i < y; i++)
    {   
        if (i < y -1)
        {
            std::cout << x << " + ";
        }
        else
        {
            std::cout << x << "\n\n";
        }
        output = output + x;
    }
    std::cout << "Summation = " << output << "\n\n";
    return output;
}

int main()
{
    // initialize variables
    int x = 0;
    int y = 0;

    // get user input for 2 numbers
    std::cout << "Please enter 2 numbers to multiply!\nResponse (x): ";
    std::cin >> x;
    std::cout << "\nResponse (y): ";
    std::cin >> y;
    std::cout << "\n\nOutput: ";
    
    // call function and pass input
    summation(x, y);
}