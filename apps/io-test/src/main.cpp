#define IO_TEST
#include "interface.hpp"
#include "fileio.hpp"
#include <nlohmann/json.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

template <typename IN, typename OUT, typename RET> class Tester {
    public:

    class Test {
        public:
        int test_num;
        std::string test_name;
        bool expected_success;
        RET expected_return;
        OUT expected_output;
        IN input;
        Test() : test_num(0), test_name(""), expected_success(false), expected_return(),expected_output(), input() {}
    };
    
    private:

    std::vector<Test> test_vec;
    // check function
    bool (*t_func)(IN&, OUT&, RET&);
    public:

    Tester(bool (*t_fun)(IN&, OUT&, RET&)) {
        t_func = t_fun;
    }


    // Initializes an array of tests from a json file.
    // Returns an into to makr an error
    int init_tests(std::string& path) {
        
        ifstream js_file(path.c_str(), std::ifstream::in);
        if(js_file.fail()) {
            return -1;
        }

        nlohmann::json jdata = nlohmann::json::parse(js_file);
        
        if(jdata.empty()) {
            return -1;
        }

        test_vec = jdata.get<std::vector<Test>>();
        js_file.close();
        return 0;
    }
    
    void run_tests() {

        // loops through the test vector
        for(Test obj : test_vec) {
                std::cout << "\nTest #" << obj.test_num << ": " << obj.test_name << ".\n";
            bool success = t_func(obj.input, obj.expected_output, obj.expected_return);
            if(success == false) {
                std::cout << "Test Failed!\n";
            } else {
                std::cout << "Test Passed!\n";
            }
        }
    }
};


void from_json(const nlohmann::json& js, ParsedNode& pn){
	js.at("address").get_to(pn.address);
	js.at("instruction").get_to(pn.instruction);
}

void from_json(const nlohmann::json& j, Tester<ParsedNode, std::string, std::string>::Test& t) {
    j.at("test_num").get_to(t.test_num);
    j.at("test_name").get_to(t.test_name);
    j.at("expected_success").get_to(t.expected_success);
    j.at("expected_output").get_to(t.expected_output);
    j.at("expected_return").get_to(t.expected_return);
    j.at("input").get_to(t.input);
}

FileIO fio;
bool prep_line_chk(ParsedNode& Input, std::string& NA, std::string& expected_return) {
    std::string act_return = fio.prep_line_wrapper(Input);
    std::cout << "Expected: " << expected_return << "\n";
    std::cout << "Actual:   " << act_return << "\n";
    return act_return == expected_return;
}

int main(void) {
    std::string json_path("C:\\Users\\wbhag\\Desktop\\Python Stuff\\riscv_assembler_v2\\json\\test1.json") ;
    Tester<ParsedNode, std::string, std::string> tester(&(prep_line_chk));
    if(tester.init_tests(json_path) < 0) {
        return -1;
    }

    tester.run_tests();
    std::cout << "All Tests Finished!\n";
    return 0;

}
