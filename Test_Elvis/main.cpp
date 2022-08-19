#include<iostream>
#include<vector>
#include<string>
#include<filesystem>

namespace fs = std::filesystem;

class FileNames {
public:
    FileNames();
    FileNames(std::u8string name);
    void Setter(std::u8string name);
private:
    std::u8string name;
    std::string text;
};

FileNames::FileNames() {

}

FileNames::FileNames(std::u8string name) {
    this->name = name;
}

void FileNames::Setter(std::u8string name) {
    this->name = name;
}

int main(int argc, char* argv[]) {
    //std::string catalog_name;
    if (argc == 3) {

        unsigned int Counter=0;
        std::vector<FileNames> Array_of_Files;
        std::string Names;
        std::vector<std::u8string> files_names;
        std::string catalog_name = argv[1];
        for (const auto& entry : fs::directory_iterator(catalog_name)) {
            std::u8string path_string{entry.path().u8string()};
            //std::string path;
           // path_string << path;
            //std::cout << path_string << std::endl;
            files_names.push_back(path_string);
            Counter++;
        }

        
        
            //FileNames file(files_names[i]);
        for (int i = 0; i < Counter; i++) {
            Array_of_Files[i].Setter(files_names[i]);
        }
        return EXIT_SUCCESS;
    }
    else return EXIT_FAILURE;

}