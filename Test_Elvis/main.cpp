/// >*.*< \\\
Test task. Parsing files using threads.

#include"Files.h"
#define PRINT_RES
namespace fs = std::filesystem;

Files Parsing(Files file) {
        std::string string;//local string, it will take string values from files 
        std::vector<std::string> delimeter;//local vector, it will take delimiters values from files 
        std::vector<std::string> substring;//local vector, it will take substring values after parsing
        size_t position = 0;//position in string
        std::string token;//just token, it will take substring values or smth like that
        string = file.Getter();
        delimeter = file.Getter_D();
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
                        string.erase(0, position + delimeter[j].length());
                        substring.insert(substring.begin() + k + 2 + counter, string);
                        substring.erase(substring.begin() + k + counter);
                        counter++;
                    }
                }
            }
        }
        file.Setter_S(substring);
        
    return(file);
}

int main(int argc, char* argv[]) {

    if (argc == 3) { 
        std::vector<std::thread> threads;//threads vector
        std::vector<Files> array_of_files;//Vector of all text files in catalog (directory)
        std::string output_filename = argv[2];//Name of output file
        std::vector<std::string> input_filenames;//Vector of input filenames
        std::string catalog_name = argv[1];//Name of catalog
        std::string test = catalog_name + "\\test";//test file path and name

        std::ofstream f;//test file to check catalog
        f.open(test);
        if (!f.is_open()) {//check catalog
            std::cout << "Wrong arguments";
            return EXIT_FAILURE;
        }
        f.close();
        remove(test.c_str());
        remove(output_filename.c_str());

        for (const auto& entry : fs::directory_iterator(catalog_name)) {//find all files from catalog, take their names
            std::string path_string{entry.path().string()};            
            input_filenames.push_back(path_string);
        }
                
        Files file;
        for_each(input_filenames.begin(), input_filenames.end(), [&file, &array_of_files](std::string input_filenames) {//Read input files
            file.Setter_N(input_filenames);
            file.ReadFile();
            array_of_files.push_back(file);
            }
        );

        threads.reserve(array_of_files.size());
        for_each(array_of_files.begin(), array_of_files.end(), [&threads](Files &F) {//Parsing files by threads
            F = Parsing(F);
            threads.push_back((std::thread([&F]() {F = Parsing(F); })));
            }
        );
        for_each(threads.begin(), threads.end(), [](std::thread& th) {//join threads
            th.join(); 
        });

        for (auto a : array_of_files) { //Print result to console
            a.WriteFile(output_filename);
        }


#ifdef PRINT_RES
        int i = 0;

        for (auto a : array_of_files) { //Print result to console
            std::cout <<a.Getter_N() << std::endl;
            a.Print(); 
            i++;
        }
#endif
        return EXIT_SUCCESS;
    }
    else {
        std::cout << "Wrong arguments";
        return EXIT_FAILURE;
    }

}