#include <vector>
#include <iostream>
#include <fstream>

class BookFile {
protected:
    // making member vairables protected so only BookFile functions may access
    std::vector <std::string> lines;
    std::vector <std::string> output;

public:
    // public member functions to call
    void read_file (std::string);
    void split_data ();
    void append_correctedfile ();
    void display_file_content (std::string);
};

// takes file name as input, opens, if open will copy all lines into "lines" vector
void BookFile::read_file (std::string filename){

    std::fstream text_file;

    text_file.open(filename);

    if (text_file.is_open()){

        std::string line;

        while (std::getline(text_file, line)){

            lines.push_back(line);   
        }

        text_file.close();
    }

    // if the file was not able to be openned, display error 
    else {

        std::cout << "Could not open file.";
    }
}

// takes lines, puts every line as title followed by every other line as the authors.
void BookFile::split_data () {

    for (int i = 0; i < lines.size(); i+=2){

        output.push_back(lines[i] + " - by - " + lines [i+1]);
    }
}

// takes the contents of output vector and appends to given output file
void BookFile::append_correctedfile(){

    std::fstream title_author;

    title_author.open("title_author.txt");
    
    if (title_author.is_open()){

        for (const auto & each : output){

            title_author << each << "\n";
        }
    }   
    
    title_author.close();
}


// extra funciton, takes a file name and reads out all contents
void BookFile::display_file_content(std::string file_name){

    std::fstream text_file;
    std::string line;

    text_file.open (file_name);

    std::cout << "-------------------------- " << file_name << "--------------------------\n";

    if (text_file.is_open()){
        while (std::getline(text_file, line)){

            std::cout << line << "\n";
        }

        text_file.close();
    }    
}