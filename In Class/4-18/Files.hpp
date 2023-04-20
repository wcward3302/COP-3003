#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include <string>
#include <cctype>
#include <vector>

class Files {

public:
    std::string file_name;

    virtual void change_filename(std::string) = 0;
    virtual void load_file() = 0;
    virtual void write_file(std::string) = 0;
};

#endif
