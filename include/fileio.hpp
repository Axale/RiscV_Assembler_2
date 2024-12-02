#ifndef __FILEIO_HPP__
#define __FILEIO_HPP__
#include "interface.hpp"

// File IO class that abstracts two methods: one for getting the code, and the other for placing the raw binary in a file.
class FileIO {
    private:
    string prep_line(ParsedNode& node);
    public:
    int file_input(string& file_name, Interface& data_interface);
    int file_output(Interface& file_name);
};
#endif