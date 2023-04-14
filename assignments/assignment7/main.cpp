#include "class.cpp"

int main(){

    BookFile books;

    books.read_file("books.txt");
    books.split_data();
    books.append_correctedfile();
    books.display_file_content("books.txt");
    books.display_file_content("title_author.txt");

    return 0;
}