#include "interface.hpp"
#include "fileio.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int FileIO::file_input(string& file_name, Interface& data_interface) {
    ifstream FileIn(file_name);

    if(FileIn.bad()) {
        cout << "Invalid File\n";
        return -1;
    }

    string str;
    for(; FileIn.eof() != true;) {
        getline(FileIn, str);
        data_interface.add_line(str);
    }

    return 0;
    
}

string FileIO::prep_line(ParsedNode& Node) {
    stringstream stream ;
    stream << ":04"
    << std::setfill('0') << std::setw(sizeof(int32_t))
    << std::hex << Node.get_address();
    
    stream << "00" << std::setfill('0') << std::setw(sizeof(int32_t))
    << std::hex << Node.get_instruction();
    
    string inter = stream.str();
}

int FileIO::file_output(Interface& data_interface) {
    
}