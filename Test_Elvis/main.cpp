#include<iostream>
#include<vector>
#include<string>
#include<filesystem>
#include<fstream>

namespace fs = std::filesystem;

void ReadFiles(std::vector<std::u8string> in_filenames) {
    std::ifstream F;
    for (int i = 0; i < in_filenames.size(); i++) {
        std::string text_from_file;
        F.open(in_filenames[i]);
        if (F.is_open()) {
            F >> text_from_file;
            std::cout << "Yes!!!" << std::endl;
            std::cout << text_from_file;

        }
        F.close();
    }
}

class Files {
public:
    Files();
    Files(std::u8string name);
    void Setter(std::u8string name);
private:
    std::u8string name;
    std::string text;
};

Files::Files() {

}

Files::Files(std::u8string name) {
    this->name = name;
}

void Files::Setter(std::u8string name) {
    this->name = name;
}

int main(int argc, char* argv[]) {

    if (argc == 3) { 

        std::vector<Files> array_of_files;//Vector of all text files in catalog (directory)
        std::string output_filename = argv[2];//Name of output file
        std::vector<std::u8string> input_filenames;//Vector of input filenames
        std::string catalog_name = argv[1];//Name of catalog

        for (const auto& entry : fs::directory_iterator(catalog_name)) {
            std::u8string path_string{entry.path().u8string()};            
            input_filenames.push_back(path_string);
        }

        ReadFiles(input_filenames);
        
        Files file;
        for (int i = 0; i < input_filenames.size(); i++) {
            file.Setter(input_filenames[i]);
            array_of_files.push_back(file);
        }
        return EXIT_SUCCESS;
    }
    else return EXIT_FAILURE;

}