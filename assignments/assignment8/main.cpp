/*
Given the file magazines.xml Download magazines.xml, you will create a new inherited class called XMLFiles which reads in the information to a struct and includes a to_string for printing.

Create an inherited class from File.hpp Download File.hpp called Magazine (both the hpp & cpp)
    It should have a constructor and overloaded constructor
        One sets a default filename
        The other validates and then sets a filename based on the user's passed input
    It should used and override all the virtual functions
    Open and load the file to a structure
        It can load it to a vector as an intermediary (to hold all the strings and then parse it for the struct) 
        You can also load it directly to the structure when reading the file in
    Using string methods (like find and substring) to get the information between the tags
        You can "ignore" the first line
    Create a function "write_data()" and a "to_string" 
        to_string should put the data together (the structure) with formatting
            Name then all other lines tabbed in
        write_data should print the to_string information to a new file based on the passed filename
        it should write to a text file (.txt) over an xml file (cause we are removing the xml)
Submit the main & MagazineFile cpp (hpp) and text file you create.
*/


#include <iostream>
#include "magazine_file.hpp"

int main(){

    struct magazine{
        std::string name;
        std::string location;
        long employees;
        long founded;
        std::string founder;
    };


    std::fstream file_stream;
    file_stream.open("./magazine.xml");

    std::vector <std::string> lines;
    std::vector <magazine> magazine_list;


    if(file_stream.is_open()){

        std::string line;

        while(std::getline(file_stream, line)){
            lines.push_back(line);
        }

        file_stream.close();
    }

    else{
        std::cout << "Could not open file.";
    }

    std::string line_item;
    magazine magazine_object;
    int counter = 0;

    for (const auto & each : lines){
        switch(counter){
            case 0:
                counter++;
                break;

            case 1:
                //magazine_object.name = each.substr(each.find('>') + 1 , each.find('<') + 1);
                std::cout << each.substr(each.find('>') + 1, each.find('>') + 2) << "\n";
                counter++;
                break;

            case 2:
                //magazine_object.location = each.substr(each.find('>') + 1, each.find('<') + 1);
                std::cout << each.substr(each.find('>') + 1, each.find('>') + 2) << "\n";
                counter++;
                break;

            case 3:
                magazine_object.employees = std::stoi(each.substr(each.find('>') + 1, each.find('<') + 1));
                std::cout << each.substr(each.find('>') + 1, each.find('>') + 2) << "\n";
                counter++;
                break;

            case 4:
                magazine_object.founded = std::stoi(each.substr(each.find('>') + 1, each.find('<') + 1));
                std::cout << each.substr(each.find('>') + 1, each.find('>') + 2) << "\n";
                counter++;
                break;
            case 5:
                magazine_object.founder = each.substr(each.find('>') + 1, each.find('<') + 1);
                std::cout << each.substr(each.find('>') + 1, each.find('>') + 2) << "\n";
                counter++;
                break;
            case 6:
                counter = 0;
                magazine_list.push_back(magazine_object);
                break;
        }
    }


    std::string to_print;

    for (const auto & each : magazine_list){
        to_print.append(each.name);
        to_print.append("\t");
        to_print.append(each.location);
        to_print.append("\t");
        to_print.append(std::to_string(each.employees));
        to_print.append("\t");
        to_print.append(std::to_string(each.founded));
        to_print.append("\t");
        to_print.append(each.founder);
    }


    std::cout << "to print = " << to_print;
}