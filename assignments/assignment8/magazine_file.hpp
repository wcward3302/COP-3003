/*
Name - William Ward
Date - 4/22/23
Assignment 8 - Inheritance

prototyping header file for necessary variables and functions, set scope

*/

#ifndef magazine_file_hpp
#define magazine_file_hpp

#include "file.hpp"
#include <iostream>

class Magazine_file : public Files {

private:

    // struct for org of file content
    struct magazine{
        std::string name;
        std::string location;
        long employees;
        long founded;
        std::string founder;
    };
    
    // vector to have many magazine structs
    std::vector <magazine> magazine_list;
    std::vector <std::string> lines;
    std::string to_output;

    // internal class function to handle moving lines from file into data structure
    void split_data();

    void to_string();

public:

    // default constructor
    Magazine_file();

    // overload constructor to accept name parameter
    Magazine_file(std::string);

    // overridden files from parent class
    void change_filename(std::string) override;
    void load_file() override;
    void write_file(std::string) override;
};

#endif