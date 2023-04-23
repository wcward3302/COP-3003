/*
Name - William Ward
Date - 4/22/23
Assignment 8 - Inheritance

call defined functions from inheritance class

*/

#include <iostream>
#include "magazine_file.hpp"
#include "magazine_file.cpp"

int main(){

    // call default constructor
    Magazine_file magazine = Magazine_file();

    // call load function to take contents of file, sort into data struct
    magazine.load_file();

    // using org'd struct, convert to formatted string and write to text file
    magazine.write_file(magazine.filename);

}