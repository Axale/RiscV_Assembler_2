# CMake generated Testfile for 
# Source directory: C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/inline_ns
# Build directory: C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/inline_ns
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test-abi_compat_inline_ns "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/inline_ns/Debug/abi_compat_inline_ns.exe")
  set_tests_properties(test-abi_compat_inline_ns PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/inline_ns/CMakeLists.txt;10;add_test;C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/inline_ns/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test-abi_compat_inline_ns "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/inline_ns/Release/abi_compat_inline_ns.exe")
  set_tests_properties(test-abi_compat_inline_ns PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/inline_ns/CMakeLists.txt;10;add_test;C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/inline_ns/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test-abi_compat_inline_ns "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/inline_ns/MinSizeRel/abi_compat_inline_ns.exe")
  set_tests_properties(test-abi_compat_inline_ns PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/inline_ns/CMakeLists.txt;10;add_test;C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/inline_ns/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test-abi_compat_inline_ns "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/inline_ns/RelWithDebInfo/abi_compat_inline_ns.exe")
  set_tests_properties(test-abi_compat_inline_ns PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/inline_ns/CMakeLists.txt;10;add_test;C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/inline_ns/CMakeLists.txt;0;")
else()
  add_test(test-abi_compat_inline_ns NOT_AVAILABLE)
endif()
