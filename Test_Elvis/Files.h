#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<filesystem>

class Files {
public:
    Files();
    void Setter(std::u8string name);
    void Setter(std::vector<std::string> delimiters);
    void Setter(std::string text);
    void ReadFile();
    void Print();
private:
    std::u8string name;//Name of file from catalog
    std::string text;//file contents
    std::vector<std::string> delimiters;
};