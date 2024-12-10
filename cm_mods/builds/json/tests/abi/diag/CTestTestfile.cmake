# CMake generated Testfile for 
# Source directory: C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/diag
# Build directory: C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/diag
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test-abi_compat_diag "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/diag/Debug/abi_compat_diag.exe")
  set_tests_properties(test-abi_compat_diag PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/diag/CMakeLists.txt;17;add_test;C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/diag/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test-abi_compat_diag "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/diag/Release/abi_compat_diag.exe")
  set_tests_properties(test-abi_compat_diag PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/diag/CMakeLists.txt;17;add_test;C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/diag/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test-abi_compat_diag "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/diag/MinSizeRel/abi_compat_diag.exe")
  set_tests_properties(test-abi_compat_diag PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/diag/CMakeLists.txt;17;add_test;C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/diag/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test-abi_compat_diag "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/cm_mods/builds/json/tests/abi/diag/RelWithDebInfo/abi_compat_diag.exe")
  set_tests_properties(test-abi_compat_diag PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/diag/CMakeLists.txt;17;add_test;C:/Users/wbhag/Desktop/CS/Personal Programming Ventures/RiscV_Assembler_2/third-party/json/tests/abi/diag/CMakeLists.txt;0;")
else()
  add_test(test-abi_compat_diag NOT_AVAILABLE)
endif()
