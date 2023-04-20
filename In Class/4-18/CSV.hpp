#include "Files.hpp"

class CSV_files : Files {

public:
    void change_filename(std::string) override;
    void load_file() override;
    void write_file(std::string) override;

};