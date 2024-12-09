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