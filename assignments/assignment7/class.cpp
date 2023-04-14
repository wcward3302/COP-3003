#include <vector>
#include <iostream>
#include <fstream>

class BookFile {
protected:
    std::vector <std::string> lines;
    std::vector <std::string> output;

public:
    void read_file (std::string);
    void split_data ();
    void append_correctedfile ();
    void display_file_content (std::string);
};


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
    else {

        std::cout << "Could not open file.";
    }
}

void BookFile::split_data () {

    for (int i = 0; i < lines.size(); i++){
        // no need for 2 more vectors to hold titles and authors
        output.push_back(lines[i] + " - by - " + lines [++i]);
        // ++i causes warning, but who cares (?)
    }
}

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

void BookFile::display_file_content(std::string file_name){

    std::fstream text_file;
    std::string line;

    text_file.open (file_name);

    if (text_file.is_open()){

        while (std::getline(text_file, line)){

            std::cout << line << "\n";
        }
        text_file.close();
    }    
}