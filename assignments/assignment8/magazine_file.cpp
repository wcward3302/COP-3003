#include "magazine_file.hpp"

// -------------------------------------private member functions--------------------------------------

void Magazine_file::split_data(){

    std::string line_item;
    magazine magazine_object;
    int counter = 0;

    for (const auto & each : lines){
        switch(counter){
            case 0:
                counter++;
                break;

            case 1:
                magazine_object.name = each.substr(each.find('>') + 1);
                counter++;
                break;

            case 2:
                magazine_object.location = each.substr(each.find('>') + 1);
                counter++;
                break;

            case 3:
                magazine_object.employees = std::stoi(each.substr(each.find('>') + 1));
                counter++;
                break;

            case 4:
                magazine_object.founded = std::stoi(each.substr(each.find('>') + 1));
                counter++;
                break;
            case 5:
                magazine_object.founder = each.substr(each.find('>'));
                counter++;
                break;
            case 6:
                counter = 0;
                magazine_list.push_back(magazine_object);
                break;
        }
    }
}



// --------------------------------------public member functions--------------------------------------
// default constructor
Magazine_file::Magazine_file(){
    filename = "./magazine.xml";
}

// overloaded constructor
Magazine_file::Magazine_file(std::string in_file_name){
    filename = "./" + in_file_name + ".xml";
}

// takes input and changs the member veriable "file name" which is used to open "x" file
void Magazine_file::change_filename(std::string in_file_name){
    filename = "./" + in_file_name + ".xml";
}

// parse given file and fill structure 
void Magazine_file::load_file(){

    std::fstream file_stream;
    file_stream.open(filename);

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

    // calling member function to data from the lines member into the vector of structs
    split_data();
}

// take structures, create lines concat \t, output to a .txt now that all the xml has been removed
void Magazine_file::write_file(std::string new_file_name){


    std::fstream file_stream;
    file_stream.open(new_file_name);

    if(file_stream.is_open()){

        

        file_stream.close();
    }

    else{
        std::cout << "Could not open file.";
    }
}