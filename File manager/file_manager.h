#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class File {
private:
    const char* name;
    ofstream out;
public:
    File(const char* mName);
    File(File& mFile);
    File();
    void clear();                                                       // clears the file
    void write(const char* txt);                                        // clears and writes new text into the file (const char*)
    void write(const vector<string>& vec);                              // clears and writes new text into the file (std::vector <std::string>)
    vector<string> read_vec();                                          // returns text in file (std::vector <std::string>)
    string read();                                                      // returns text in the file (std::string)
    friend File& operator>>(File& file, string& str);                   // writes everething that in the file in the std::string
    friend File& operator<<(File& file, const char* text);              // writes text in the next line of file
    friend ostream& operator<<(ostream& out, File& file);               // writes everesing that in the file in the console
    friend File& operator<<(File& file, const vector<string>& vec);     // writes everething that in std::vector <std::string> in the file (every new string in other line)
};
#endif