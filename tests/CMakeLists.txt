# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("my_test")

# 启用测试
enable_testing()

macro(test_for file_name)
  add_executable (${file_name} "${file_name}.cpp")
  target_link_libraries(${file_name} number)
  target_include_directories(${file_name} PRIVATE
    ${PROJECT_SOURCE_DIR}/../include
  )
  add_test(NAME ${file_name}.cpp ${file_name})
endmacro()

add_executable (Number-add-001-zzz "Number-add-001-zzz.cpp")
  target_link_libraries(Number-add-001-zzz number)
  target_include_directories(Number-add-001-zzz PRIVATE
    ${PROJECT_SOURCE_DIR}/../include
  )
  add_test(NAME Number-add-001-zzz.cpp Number-add-001-zzz)



