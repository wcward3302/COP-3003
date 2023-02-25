#include <string>
#include <iostream>

class Book {

public:
    std::string title;
    std::string author;
    long isbn;

    void set_all(std::string, std::string, long);
    void get_all();

    Book(){
        this->title = "Unknown";
        this->author = "Unknown";
        this->isbn = 1;
    }

    Book(std::string title, std::string author, long isbn ){
        this->title = title;
        this->author = author;
        this->isbn = isbn;
    }
};

void Book::get_all(){
    std::cout << this->title << "\n";
    std::cout << this->author << "\n";
    std::cout << this->isbn << "\n";
}




int main(){
    Book book ("x", "x", 5);
    Book book2 Book();

    Book book2 ();

    book.get_all();

}