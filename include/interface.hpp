#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__
#include <vector>
#include <string>
#include <list>
#include <iterator>

using namespace std;

// Node for the list of opcodes.
// Has the address so I can easily do org instructions. 
// Its mainly a data storage class, so no fancy methods
class ParsedNode {
private:
  	uint32_t address;
  	uint32_t instruction;
public:
  	ParsedNode(uint32_t address, uint32_t instruction);
  	~ParsedNode();
	
	// Getters/Setters
	uint32_t get_address(); void set_address(uint32_t address);
	uint32_t get_instruction(); void set_instruction(uint32_t instruction);
};

// Data interface between File I/O and Parser
// Holds a list of strings to hold lines of text for the parser, and a list of parsed instructions for output 
class Interface {
private:
	list<string*> lines;
	list<string*>::iterator lines_it;

	list<ParsedNode*> parsed;
	list<ParsedNode*>::iterator parsed_it;
public:
  	Interface();

	// Adding functions
	void add_line(string line);
	void add_parsed(ParsedNode& Node);

	// Step functions 
	string* step_lines();
	ParsedNode* step_parsed();
};

#endif