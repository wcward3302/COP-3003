#include <iostream>
#include <fstream>
#include <vector>

class Employee {
    public:
    std::string id;
};

class Time_File{
    public:
    // should be private
    std::vector <long> ids;
    std::vector <std::string> times;

    std::vector <std::string> lines;
    std::fstream time_file;
    std::string last_clock;

    void set_times(){
        for (const auto & each : lines){
            ids.push_back(std::stoi(each.substr(0, each.find( " "))));
        }
        for (const auto & each : lines){
            times.push_back(each.substr(each.find(" ") + 4));
        }
    }

    void read_file(std::string line){

    }

    void write_file(std::string line ){

    }

    void append_file(std::string line){
        time_file.open("filename.txt", std::ios::app);

        for (const auto & each : lines){
            time_file << each;
        }
        time_file << "\n";
        time_file.close();
    }

    void print_lines(){
        for (const auto & each : this->ids){
            std::cout << each << "\n";
        }

        for (const auto & each : this->times){
            std::cout << each << "\n";
        }
    }
};

int main(){

    Employee employee;
    Time_File time_files;

    std::fstream time_file;
    std::vector <std::string> not_pound_sign_lines;

    // open file...
    time_file.open("test.txt", std::ios::in);

    // if open...
    if(time_file.is_open()){

        std::string line;
        
        // use getline to get lines of the file... (is word wrap still 1 line? Yes?)
        while(std::getline(time_file, line)){

            if(line[0] != '#'){ // add to non-pound
                time_files.lines.push_back(line);
            }
        }


        time_files.set_times();

        time_files.print_lines();


        time_file.close(); // close needs to be here, because we dont need to close unless it is open
    }
    // if it did not open, display message
    else{
        std::cout << "Could not open";
    }

    
}





/*std::vector <std::string> authors;
    std::vector <std::string> titles;
    int counter = 0;
    if (counter % 2 == 0){
                //std::cout << "Author = " << line << "\n";
                authors.push_back(line);
            }
            else{
                //std::cout << "Title = " << line << "\n";
                titles.push_back(line);
            }

            counter++;*/