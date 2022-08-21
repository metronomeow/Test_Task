#include"Files.h"

Files::Files() {

}

void Files::Setter(std::u8string name) {
    this->name = name;
}

void Files::Setter(std::vector<std::string> delimiters) {
    this->delimiters = delimiters;
}

void Files::Setter(std::string text) {
    this->text = text;
}

void Files::ReadFile() {
    std::ifstream F;
    std::string text_from_file;
    std::vector<std::string> delimiters;
    F.open(name);
    if (F.is_open()) {
        F >> text_from_file;
        this->Setter(text_from_file);
        if (!F.eof()) {
            F >> text_from_file;
            delimiters.push_back(text_from_file);
        }
        this->Setter(delimiters);
    }
    F.close();
}

void Files::Print() {
    std::cout << text << std::endl;
    std::cout << delimiters[0] << std::endl;
}