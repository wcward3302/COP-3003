/*
1. William Ward
2. CRN 15050 - COP3303
3. Assignment 5
*/

#include <iostream>



//-----------------------------------------------------------------------------------------Student Class-------------------------------------------------------------------------------------------//

class Student {

private:
    // private class members
    std::string name;
    std::string grade_level;
    std::string major;

public:
    // made all functions public for main to access
    // default constructor
    Student(){
        this->name = "no_name";
        this->grade_level = "Sophomore";
        this->major = "computer science";
    }

    // overloaded constructor
    Student(std::string name, std::string grade_level, std::string major){
        this->name = name;
        this->grade_level = grade_level;
        this->major = major;
    }


    // member functions
    void set_name(std::string name){
        this->name = name;
    }

    void set_grade_level(std::string grade_level){
        this->grade_level = grade_level;
    }

    void set_major(std::string major){
        this->major = major;
    }

    std::string get_name(){
        return this->name;
    }

    std::string get_grade_level(){
        return this->grade_level;
    }

    std::string get_major(){
        return this->major;
    }

    void print_info(){
        std::cout << this->get_name() << "\n";
        std::cout << this->get_grade_level() << "\n";
        std::cout << this->get_major() << "\n";
    }

    // update info is called, collects into and inserts into object
    void update_data(){
        // variables
        std::string user_grade_level, user_major;

        // message
        std::cout << "\nUpdating information\n\n";

        // update grade level
        std::cout << "Enter grade level: ";
        std::getline(std::cin, user_grade_level);
        this->grade_level = user_grade_level;

        // update major
        std::cout << "Enter major: ";
        std::getline(std::cin, user_major);
        this->major = user_major;
    }
};