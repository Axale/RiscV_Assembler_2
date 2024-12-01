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
  	int address;
  	int instruction;
public:
  	ParsedNode(int address, int instruction);
  	~ParsedNode();
	
	// Getters/Setters
	int get_address(); void set_address(int address);
	int get_instruction(); void set_instruction(int instruction);
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
