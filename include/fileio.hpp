#ifndef __FILEIO_HPP__
#define __FILEIO_HPP__
#include "interface.hpp"
#define TEST_IO

// File IO class that abstracts two methods: one for getting the code, and the other for placing the raw binary in a file.
class FileIO {
    private:
    string prep_line(ParsedNode& node);
    public:
    int file_input(string& file_name, Interface& data_interface);
    int file_output(Interface& file_name);
#ifdef TEST_IO
    string prep_line_wrapper(ParsedNode& node);
#endif

};
#endif