/*
Move our grade code to a Class should have:
    a scalar lowest grade
    an array of all the grades (the 10 not lowest grades)
    A display all grades function which prints all of these
    Move other functions and adjust to work in class

*/

#include <string>
#include <array>
#include <iostream>
#include <math.h>

using std::string;

class Grades {
public:
    int lowest_grade;
    std::array <int, 10> grade_array;
    std::array <int, 11> temp_grade_array;

    Grades(){
        this->lowest_grade = 0;
        for (int x = 0; x < this->grade_array.size(); x++){
            this->grade_array[x] = 0;
        }
    }

    int get_lowest_grade(){
        return this->lowest_grade;
    }

    std::array <int, 10> get_grade_array(){
        return this->grade_array;
    }

    void display_grades(){

        std::cout << "Lowest grade is " << this->lowest_grade << "\n";

        for (int x = 0; x < this->grade_array.size(); x++){
            std::cout << "Grade " << x + 1 << " = " << this->grade_array[x] << "\n";
        }
    }

    int get_average(){
        int sum =0, average = 0;

        for (int x = 0; x < this->grade_array.size(); x++){
            sum = sum + this->grade_array[x];
        }

        average = sum / this->grade_array.size();

        return average;
    }

    void set_grades(std::array <int, 11> user_input_array){

        std::sort(user_input_array.begin(), user_input_array.end());

        this->lowest_grade = user_input_array[0];

        for(int x = 1; x < user_input_array.size(); x++){
            this->grade_array[x-1] = user_input_array[x];
        }
    }
};

class Student {
private:
    // class members
    string name;
    string grade_level;
    string major;

public:
    // default constructor
    Student(){
        this->name = "no_name";
        this->grade_level = "Sophomore";
        this->major = "computer science";
    }

    // overloaded constructor
    Student(string name, string grade_level, string major){
        this->name = name;
        this->grade_level = grade_level;
        this->major = major;
    }


    // member functions
    void set_name(string name){
        this->name = name;
    }

    void set_grade_level(string grade_level){
        this->grade_level = grade_level;
    }

    void set_major(string major){
        this->major = major;
    }

    string get_name(){
        return this->name;
    }

    string get_grade_level(){
        return this->grade_level;
    }

    string get_major(){
        return this->major;
    }

    void print_info(){
        std::cout << this->get_name() << "\n";
        std::cout << this->get_grade_level() << "\n";
        std::cout << this->get_major() << "\n";
    }

    void update_data(){
        string user_grade_level, user_major;
        std::cout << "updating information\n\n";
        std::cout << "Enter grade level: ";
        std::cin >> user_grade_level;
        std::cout << "Enter major: ";
        std::cin >> user_major;

        this->grade_level = user_grade_level;
        this->major = user_major;
    }
};
