// Use to read the book file provided
#ifndef YOURPROJECTNAME_BOOKFILE_HPP
#define YOURPROJECTNAME_BOOKFILE_HPP
#include <string>
using std::string;
class BookFile {
    private:
    // you should have your variables here - add setters/getters if needed
    // shouldn't need for first variant


    public:


    BookFile()=default;

    void read_file(string);

    void split_data();
    
};

#endif //YOURPROJECTNAME_BOOKFILE_HPP
