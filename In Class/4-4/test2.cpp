#include <iostream>
#include <vector>
#include <memory> // new include for smart pointers
using std::string;
using std::cout;
using std::getline;

void printmates(std::vector<string> roomate) {
    // create pointer to be printed out - major leak here!
    // also happens - esp. in old code
    
    std::vector<string> * pointertest = new roomate;
    // print out passed structure of roomate
    for (const auto &r : *pointertest) {
        std::cout << r << "\n";
    }

    delete pointertest;
}
int main() {
// now we add a unique pointer but not here - this is still fine
std::vector<string> mates {"Jill", "Nate", "Stella"};
// still fine as this just gets memory address and then drops once out of scope
    for (auto &m : mates) {
        if (m == "Stella") {
        m = "Jane";
        }
    }
    // now how can we use this with a passed vector
    printmates(mates);
    return 0;
};