#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::getline;
void printmates(std::vector<string> roomate) {
    // print out passed structure of roomate
    for (const auto &r : roomate) {
    std::cout << r << "\n";
}
}
int main() {
// first iteration with change

    std::vector<string> mates {"Jill", "Nate", "Stella"};

    for ( auto &m : mates) {
        if (m == "Stella") {
        m = "Jane";
        }
    }
    printmates(mates);
    return 0;
};