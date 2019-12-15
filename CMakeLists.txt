cmake_minimum_required(VERSION 3.10)
project(uxp)

set(CMAKE_CXX_STANDARD 14)

add_executable(uxp src/main.cpp 
src/structures/modules/parser/Assignable.cpp 
src/structures/modules/parser/BackTickExpr.cpp 
src/structures/modules/parser/Command.cpp 
src/structures/modules/parser/Indentifier.cpp 
src/structures/modules/parser/Node.cpp 
src/structures/modules/parser/PipeExpr.cpp 
src/structures/modules/parser/Program.cpp 
src/structures/modules/parser/RedirectionExpr.cpp 
src/structures/modules/parser/VariableAssignment.cpp 
src/structures/modules/parser/VariableCall.cpp)
