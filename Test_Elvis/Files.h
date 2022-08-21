#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<filesystem>
#include<algorithm>

class Files {
public:
    Files();
    void Setter(std::u8string name);//to set names
    void Setter(std::vector<std::string> delimiters);//to set delimeters
    void Setter_S(std::vector<std::string> substring);//to set substrings
    void Setter(std::string text);//to set text
    std::string Getter();//to get text
    std::vector<std::string> Getter_D();//to get delimeters vector
    std::vector<std::string> Getter_S();//to get substrings vector
    void ReadFile();
    void Print();
private:
    std::u8string name;//Name of file from catalog
    std::string text;//file contents, just a string
    std::vector<std::string> delimiters;//delimiters from file
    std::vector<std::string> substring;//parsing result

};