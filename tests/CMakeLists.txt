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

aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCES)
macro(test_for file_name)
  add_executable (${file_name} "${file_name}.cpp" ${SOURCES})
  target_include_directories(${file_name} PRIVATE
    ${PROJECT_SOURCE_DIR}/../include
  )
  add_test(NAME ${file_name}.cpp COMMAND ${file_name})
endmacro()

test_for("Number-add-001-zzz")
test_for("Number-sub-001-zzz")
test_for("Number-mul-001-zzz")



