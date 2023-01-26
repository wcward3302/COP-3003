#include <iostream>

int summation(int x, int y)
{
    int output = 0;
    for (int i = 0; i < y; i++)
    {   
        std::cout << x << " + ";
        output = output + x;
    }
    std::cout << " Summation = " << output << "\n\n";
    return output;
}

int main()
{
    int x = 0;
    int y = 0;

    std::cout << "Please enter 2 numbers to multiply!\nResponse (x): ";
    std::cin >> x;
    std::cout << "\nResponse (y): ";
    std::cin >> y;

    summation(x, y);
}