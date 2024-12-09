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
    if (Node.get_address() >= 0x8000 << 2) {
        return NULL;
    }
    stream << ":04"
    << std::setfill('0') << std::setw(sizeof(int32_t) )
    << std::hex << Node.get_address();
    
    stream << "00" << std::setfill('0') << std::setw(sizeof(int16_t))
    << std::hex << Node.get_instruction();
    
    auto inter = stream.str();
    int sum = 0;
    for(auto inter_it = inter.begin() + 1; inter_it != inter.end(); inter_it++) {
        sum += (inter_it - inter.begin()) % 2 ? *inter_it * 16 : *inter_it;
    }
    sum *= 0xFF;
    sum = ~sum + 1;
    stream << setfill('0') << setw(sizeof(char)) << std::hex << sum;
    
}

#ifdef TEST_IO
string FileIO::prep_line_wrapper(ParsedNode& Node) {
    return FileIO::prep_line(Node);
}
#endif

int FileIO::file_output(Interface& data_interface) {
    return 0;    
}