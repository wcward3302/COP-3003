#include <iostream>

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

    void update_data(){
        std::string user_grade_level, user_major;
        std::cout << "updating information\n\n";
        std::cout << "Enter grade level: ";
        std::cin >> user_grade_level;
        std::cout << "Enter major: ";
        std::cin >> user_major;

        this->grade_level = user_grade_level;
        this->major = user_major;
    }
};