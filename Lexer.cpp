#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "include/Lexer.h"
using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::getline;


using namespace std;
Lexer::Lexer()
{
    //ctor
}

Lexer::~Lexer()
{
    //dtor
}

string Lexer::lecture(const string& fileName) {

    std::ifstream t(fileName.c_str());
    if (t.is_open())
    {
    t.seekg(0, std::ios::end);
    size_t size = t.tellg();
    std::string lines(size, ' ');
    t.seekg(0);
    t.read(&lines[0], size);
        return lines;
    }
    else cout << "Unable to open file";
        exit(-1);
        return NULL;
}

string Lexer::parseToSymbols(const string& example) {
    //std::string example = lines;
    std::string symbols;
    std::string word;

    // Notice how you can loop through a string just like a vector<char>
    for(size_t i = 0; i < example.size(); ++i) {
        char c = example[i];

        // When we see whitespace, print the current word and clear it
        if(c == ' ' || c == '\t' || c == '\n') {
            // Don't print anything if we don't have a word
            if(!word.empty()) {
                std::cout << word << std::endl;
                word.clear();
            }
        } else if(c=='=' || c==',' || c==';' || c=='+' || c==':' || c=='-' || c=='*' || c=='/') {
            if(!word.empty()) {
                std::cout << word << std::endl;
                word.clear();
            }
            word += c;
            if(c == ':') {
                word += example[++i];
            }
            std::cout << word << std::endl;
            word.clear();
            if(c == '=') {
                int a = i+1;
                if(example[a]=='-') {
                    word += example[++i];
                }
            }
        } else {
            // Append the current character to the end of the string
            word += c; // or word.push_back(c)
        }
    }
    // In case the line doesn't end with whitespace
    if(!word.empty()) {
        std::cout << word << std::endl;
    }
    return symbols;
}

//Symbole Lexer::getNext();
