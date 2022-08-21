#include"Files.h"

namespace fs = std::filesystem;

void Parsing(std::vector<Files> array_of_files) {
    for (int i = 0; i < array_of_files.size(); i++) {

    }
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
                
        Files file;
        for (int i = 0; i < input_filenames.size(); i++) {
            file.Setter(input_filenames[i]);
            file.ReadFile();
            array_of_files.push_back(file);            
        }
        //for (int i = 0; i < array_of_files.size(); i++) { array_of_files[i].Print(); }


        return EXIT_SUCCESS;
    }
    else {
        std::cout << "Wrong arguments";
        return EXIT_FAILURE;
    }

}