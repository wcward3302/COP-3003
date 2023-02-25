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

using std::string;
using std::cout;

class Grades {
public:
    int lowest_grade;
    std::array <int, 10> grade_array;

    Grades(){
        this->lowest_grade = 0;
        for (int x = 0; x < this->grade_array.size(); x++){
            this->grade_array[x] = 90;
        }
    }

    void display_grades(){
        for (int x = 0; x < this->grade_array.size(); x++){
            std::cout << this->grade_array[x] << "\t";
        }
    }
    int get_average(){
        int sum =0, average = 0;

        for (int x = 0; x < this->grade_array.size(); x++){
            sum = sum + this->grade_array[x];
        }

        average = sum / this->grade_array.size();

        return average + 1;
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
};


