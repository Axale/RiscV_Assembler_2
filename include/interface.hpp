 
// 
class parsed_node {
private:
  	int address;
  	int opcode;
public:
  	parsed_node(int address, int opcode);
  	~parsed_node();
	int get_address();
	int get_opcode();
};

class interface {
private:
  	/* data */
public:
  	interface();
  	~interface();
};
