#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<filesystem>
#include<algorithm>
#include<thread>

class Files {
public:
    Files();
    void ReadFile();
    void WriteFile(std::string output_filename);
    void Print();
    void Setter_N(std::string name);//to set names
    std::string Getter_N();//to set names
protected:
    void Setter(std::vector<std::string> delimiters);//to set delimeters
    void Setter(std::string text);//to set text
    void Setter_S(std::vector<std::string> substring);//to set substrings
    std::string Getter();//to get text
    std::vector<std::string> Getter_D();//to get delimeters vector
    std::vector<std::string> Getter_S();//to get substrings vector
private:
    std::string name;//Name of file from catalog
    std::string text;//file contents, just a string
    std::vector<std::string> delimiters;//delimiters from file
    std::vector<std::string> substring;//parsing result

friend Files Parsing(Files file);
};