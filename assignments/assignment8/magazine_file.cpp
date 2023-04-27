/*
Name - William Ward
Date - 4/22/23
Assignment 8 - Inheritance

Definitions of all functions needed to perform the necessary tasks

*/

#include "magazine_file.hpp"

// -------------------------------------private member functions--------------------------------------

std::string Magazine_file::validate(std::string file_name){
    std::string validated_name;
    
    // parse name char by char, push valid chars on validated string  
    for (char chars : file_name){
        if(chars >= 65 && chars <= 122){
            validated_name.push_back(chars);
        }
    }

    return validated_name;
}

// function will take vector of strings, parse out desired data, return the filled struct to the vector of structs
void Magazine_file::split_data(){

    std::string line_item;
    magazine magazine_object;
    int counter = 0;

    // will be using similar logic to that which was given to us for the CSV handling
    for (const auto & each : lines){
        switch(counter){
            // logic - using substr(index, length) set index to the first instance of > + 1, and the length as the (2nd < index) - (/ index) - 2
            // case 0 and 6 will be <magazine> lines so will increment from 0 and use 6 to push to vector of structs and reset counter
            case 0:
                counter++;
                break;

            case 1:
                magazine_object.name = each.substr(each.find('>') + 1, (each.find('/') - each.find('>')) - 2);
                counter++;
                break;

            case 2:
                magazine_object.location = each.substr(each.find('>') + 1, (each.find('/') - each.find('>')) - 2);
                counter++;
                break;

            case 3:
                magazine_object.employees = std::stoi(each.substr(each.find('>') + 1, (each.find('/') - each.find('>')) - 2));
                counter++;
                break;

            case 4:
                magazine_object.founded = std::stoi(each.substr(each.find('>') + 1, (each.find('/') - each.find('>')) - 2));
                counter++;
                break;

            case 5:
                magazine_object.founder = each.substr(each.find('>') + 1, (each.find('/') - each.find('>')) - 2);
                counter++;
                break;
                
            case 6:
                counter = 0;
                magazine_list.push_back(magazine_object);
                break;
        }
    }
}

// takes each struct of parsed data and appends it to a single string in the vector of strings, followed by a newline for the next struct
void Magazine_file::to_string(){
    for (const auto & each : magazine_list){
        to_output.append(each.name);
        to_output.append("\t");
        to_output.append(each.location);
        to_output.append("\t");
        to_output.append(std::to_string(each.employees));
        to_output.append("\t");
        to_output.append(std::to_string(each.founded));
        to_output.append("\t");
        to_output.append(each.founder);
        to_output.append("\n");
    }
}


// --------------------------------------public member functions--------------------------------------

// default constructor
Magazine_file::Magazine_file(){
    filename = "magazine";
}

// overloaded constructor
Magazine_file::Magazine_file(std::string in_file_name){

    filename = "./" + validate(in_file_name) + ".xml";
    
}

// takes input and changs the member veriable "file name" which is used to open "x" file
void Magazine_file::change_filename(std::string in_file_name){
    filename = "./" + in_file_name + ".xml";
}

// parse given file and fill structure 
void Magazine_file::load_file(){

    std::fstream file_stream;
    file_stream.open(filename + ".xml");

    if(file_stream.is_open()){

        std::string line;

        while(std::getline(file_stream, line)){
            lines.push_back(line);
        }

        file_stream.close();
    }

    else{
        std::cout << "Could not open file. (read)";
    }

    // calling member function to data from the lines member into the vector of structs
    split_data();
}

// take parsed vector of org'd strings, output to text file
void Magazine_file::write_file(std::string out_file_name){

    to_string();

    std::fstream file_stream;

    filename = "./" + validate(out_file_name) + ".txt";

    file_stream.open(filename);

    if(file_stream.is_open()){

        std::cout << to_output;

        file_stream << to_output;

        file_stream.close();
    }

    else{
        std::cout << "Could not open file. (write)";
    }
}