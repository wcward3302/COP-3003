#include "class.cpp"

int main(){

    // create class object with constructor
    BookFile books = BookFile();

    // read in file, split data, append to 2nd file, display contents of both
    
    books.read_file("books.txt");
    books.split_data();
    books.append_correctedfile();
    books.display_file_content("books.txt");
    books.display_file_content("title_author.txt");

    return 0;
}