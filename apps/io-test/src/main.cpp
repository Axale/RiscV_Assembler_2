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
    private:
    class Test {
        private:
        int test_num;
        std::string test_name;
        bool expected_success;
        T expected_output;
        U input;
    };

    void from_json(const nlohmann::json& j, Test& t) {
        j.at("test_num").get_to(j.test_num);
        j.at("test_name").get_to(j.test_name);
        j.at("expected_success").get_to(j.expected_success);
        j.at("expected_output").get_to(j.expected_output);
        j.at("input").get_to(j.input);
    }

    T actual;

    std::vector<Test*> test_vec;

    F function_under_test;
    bool chk_out(Test* t) {
        if(t->expected_output == actual) {
            return t->expected_success;
        } else {
            return !(t->expected_success);
        }
    }


    public:
    Tester(std::string& json_path, F funder_test) {
        function_under_test = funder_test;
        ifstream js_file(json_path.c_str(), "r");
        auto jdata = nlohmann::json::parse(js_file);
        
        for(auto iter = jdata["tests"].begin(); iter < jdata["tests"].end(); iter++) {
           auto tu = (*iter).template get<Tester::Test>();
           test_vec.push_back(tu);
        }
    }
    
    ~Tester() {
        for(Test* obj : test_vec) {
            delete obj;
        }
    }

    int run_tests() {
        for(Test* obj : test_vec) {
            actual = function_under_test(obj->input&);
            if(chk_out(obj) == false) {
                std::cout << "Failed at test #" << obj->test_num << ": " << obj->test_name << ".\n";
            } else {
                std::cout << "Test #" << obj->test_num << " passed.\n"
            }
        }
    }
};

int main(void) {
    std::string json_path ="../tst_json/test1.json" ;
    Tester<ParsedNode, std::string,  std::string (FileIO::*)(ParsedNode&)> tester(json_path, &(FileIO::prep_line_wrapper));
    return 0;

}