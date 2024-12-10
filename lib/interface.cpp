#include "interface.hpp"
#include <string>
#include <list>

using namespace std;

ParsedNode::ParsedNode() {
	address = 0;
	instruction = 0;
}

ParsedNode::ParsedNode(uint32_t addr, uint32_t instr) {
	address = addr;
	instruction = instr;
}

ParsedNode::~ParsedNode() {return;}

uint32_t ParsedNode::get_address() {return address;}
void ParsedNode::set_address(uint32_t addr) {address = addr;};

uint32_t ParsedNode::get_instruction() {return instruction;}
void ParsedNode::set_instruction(uint32_t instr) {instruction = instr;};

Interface::Interface() {
	lines.clear();
    this->lines_it = lines.begin();
    this->parsed_it = parsed.begin();
}

void Interface::add_line(string line) {
	lines.push_back(new string(line));
	return;
}

void Interface::add_parsed(ParsedNode& Node) {
	parsed.push_back(new ParsedNode(Node.get_address(), Node.get_instruction()));
	return;
}

string* Interface::step_lines() {
	string* out = *(this->lines_it);
	lines_it++;
	return out;
}

ParsedNode* Interface::step_parsed() {
	ParsedNode* out = *(this->parsed_it);
	parsed_it++;
	return out;
}