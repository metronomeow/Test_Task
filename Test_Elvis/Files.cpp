#include"Files.h"

Files::Files() {

}

void Files::Setter_N(std::string name) {
    this->name = name;
}

std::string Files::Getter_N()
{
    return this->name;
}

void Files::Setter(std::vector<std::string> delimiters) {
    this->delimiters = delimiters;
}

void Files::Setter_S(std::vector<std::string> substring) {
    this->substring = substring;
}

void Files::Setter(std::string text) {
    this->text = text;
}

std::string Files::Getter() {
    return(this->text);
}

std::vector<std::string> Files::Getter_D() {
    return(this->delimiters);
}

std::vector<std::string> Files::Getter_S() {
    return(this->substring);
}

void Files::ReadFile() {
    std::ifstream F;
    std::string text_from_file;
    std::vector<std::string> delimiters;
    F.open(name);
    if (F.is_open()) {
        F >> text_from_file;
        this->Setter(text_from_file);
        while (!F.eof()) {
            F >> text_from_file;
            delimiters.push_back(text_from_file);
        }
        this->Setter(delimiters);
    }
    F.close();
}

void Files::WriteFile(std::string output_filename) {
    std::ofstream F;
    F.open(output_filename, std::ios_base::app);
    if (F.is_open()) {
        F << name.c_str()<<std::endl;
        for (std::string s : substring) {
            F << s << std::endl;
        }       
    }
    else {
        std::cout << "Output file is damaged!";
        exit(1);
    }
    F.close();
}

void Files::Print() {
   //std::cout << text << std::endl;
   //for_each(delimiters.begin(), delimiters.end(), [](std::string a) {std::cout << a << std::endl; });
    for_each(substring.begin(), substring.end(), [](std::string a) {std::cout << a << std::endl; });
}