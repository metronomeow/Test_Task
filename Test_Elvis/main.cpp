/// >*.*< \\\
Test task. Parsing files using threads.

#include"Files.h"
namespace fs = std::filesystem;

std::vector<Files> Parsing(std::vector<Files> array_of_files) {
        std::string string;//local string, it will take string values from files 
        std::vector<std::string> delimeter;//local vector, it will take delimiters values from files 
        std::vector<std::string> substring;//local vector, it will take substring values after parsing
        size_t position = 0;//position in string
        std::string token;//just token, it will take substring values or smth like that
    for (int i = 0; i < array_of_files.size(); i++) {
        string = array_of_files[i].Getter();
        delimeter = array_of_files[i].Getter_D();
        substring.push_back(string);
        for (int j = 0; j < delimeter.size(); j++) {
            for (int k = 0; k < substring.size(); k++) {
                string = substring[k];
                position = 0;
                if (!string.empty() && !delimeter.empty()) {
                        size_t counter=0;
                    while ((position = string.find(delimeter[j])) != std::string::npos) {
                        token = string.substr(0, position);
                        substring.insert(substring.begin() + k + 1 + counter,token);
                        //std::cout << token << std::endl;
                        string.erase(0, position + delimeter[j].length());
                        substring.insert(substring.begin() + k + 2 + counter, string);
                        substring.erase(substring.begin() + k + counter);
                        counter++;
                    }
                    //std::cout << string << std::endl;
                }
            }
        }
        array_of_files[i].Setter_S(substring);
        substring.clear();
    }
    return(array_of_files);
}

int main(int argc, char* argv[]) {

    if (argc == 3) { 

        std::vector<Files> array_of_files;//Vector of all text files in catalog (directory)
        std::string output_filename = argv[2];//Name of output file
        std::vector<std::u8string> input_filenames;//Vector of input filenames
        std::string catalog_name = argv[1];//Name of catalog
        std::string test = catalog_name + "\\test";

        std::ifstream f;
        f.open(test);
        if (!f.is_open()) {
            std::cout << "Wrong arguments";
            return EXIT_FAILURE;
        }

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
        
        array_of_files = Parsing(array_of_files);
        for (int i = 0; i < array_of_files.size(); i++) { std::cout << i << std::endl; array_of_files[i].Print(); }

        return EXIT_SUCCESS;
    }
    else {
        std::cout << "Wrong arguments";
        return EXIT_FAILURE;
    }

}