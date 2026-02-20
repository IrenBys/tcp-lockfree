# CMakeList.txt: проект CMake для tcp-lockfree; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.10)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("tcp-lockfree")

# Добавьте источник в исполняемый файл этого проекта.
# add_executable (tcp-lockfree "tcp-lockfree.cpp" "tcp-lockfree.h" "server/main.cpp")
add_executable (server "server/server.cpp" "server/server.h" "server/main.cpp")
# add_executable (server "client/client.cpp" "client/client.h" "common/*.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  #set_property(TARGET tcp-lockfree PROPERTY CXX_STANDARD 20)
  set_property(TARGET server PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
