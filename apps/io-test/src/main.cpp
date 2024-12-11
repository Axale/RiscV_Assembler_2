#define IO_TEST
#include "interface.hpp"
#include "fileio.hpp"
#include "nlohmann/json.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

// This function has two objects: one is the actual object that is being tested, and the other has the expected state of the object.
template <typename T, typename U, typename F> class Tester {
    public:
    class Test {
        public:
        int test_num;
        std::string test_name;
        bool expected_success;
        T expected_output;
        U input;
        Test() : test_num(0), test_name(""), expected_success(false), expected_output(""), input() {}
    };
    
    private:
    T actual;
    FileIO FIO;

    std::vector<Test> test_vec;

    F function_under_test;
    bool chk_out(Test& t) {
        if(t.expected_output == actual) {
            return t.expected_success;
        } else {
            return !(t.expected_success);
        }
    }


    public:

    Tester(std::string& json_path, F funder_test) {
        function_under_test = funder_test;
    }

    int init_tests(std::string& path) {
        ifstream js_file(path.c_str(), std::ifstream::in);
        if(js_file.fail()) {
            return -1;
        }

        nlohmann::json jdata = nlohmann::json::parse(js_file);
        test_vec = jdata.get<std::vector<Test>>();
        js_file.close();
        return 0;
    }
    
    void run_tests() {
        for(Test obj : test_vec) {
            actual = (FIO.*function_under_test)(obj.input);
            if(chk_out(obj) == false) {
                std::cout << "Failed at test #" << obj.test_num << ": " << obj.test_name << ".\n";
            } else {
                std::cout << "Test #" << obj.test_num << " passed.\n";
            }
        }
    }
};

void from_json(const nlohmann::json& js, ParsedNode& pn){
	js.at("address").get_to(pn.address);
	js.at("instruction").get_to(pn.instruction);
}

void from_json(const nlohmann::json& j, Tester<std::string, ParsedNode,  std::string (FileIO::*)(ParsedNode&)>::Test& t) {
    j.at("test_num").get_to(t.test_num);
    j.at("test_name").get_to(t.test_name);
    j.at("expected_success").get_to(t.expected_success);
    j.at("expected_output").get_to(t.expected_output);
    j.at("input").get_to(t.input);
}

int main(void) {
    std::string json_path("C:\\Users\\wbhag\\Desktop\\Python Stuff\\riscv_assembler_v2\\json\\test1.json") ;
    Tester< std::string,  ParsedNode,  std::string (FileIO::*)(ParsedNode&)> tester(json_path, &(FileIO::prep_line_wrapper));
    if(tester.init_tests(json_path) < 0) {
        return -1;
    }

    tester.run_tests();
    return 0;

}