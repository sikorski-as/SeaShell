cmake_minimum_required(VERSION 3.10)
project(uxp)

set(CMAKE_CXX_STANDARD 14)

# add_executable(uxp
#         src/main.cpp
#         src/structures/Assignable.cpp
#         src/structures/BackTickExpr.cpp
#         src/structures/Command.cpp
#         src/structures/Identifier.cpp
#         src/structures/Node.cpp
#         src/structures/PipeExpr.cpp
#         src/structures/Program.cpp
#         src/structures/RedirectionExpr.cpp
#         src/structures/VariableAssignment.cpp
#         src/structures/VariableCall.cpp

#         src/modules/Executor.cpp src/modules/Executor.h
#         src/modules/Interpreter.cpp src/modules/Interpreter.h
#         src/modules/Context.cpp src/modules/Context.h
#         src/modules/Shell.cpp src/modules/Shell.h
#         )

# add_executable(exec_test
#         src/structures/Assignable.cpp
#         src/structures/BackTickExpr.cpp
#         src/structures/Command.cpp
#         src/structures/Identifier.cpp
#         src/structures/Node.cpp
#         src/structures/PipeExpr.cpp
#         src/structures/Program.cpp
#         src/structures/RedirectionExpr.cpp
#         src/structures/VariableAssignment.cpp
#         src/structures/VariableCall.cpp

#         src/modules/Executor.cpp src/modules/Executor.h
#         src/modules/Context.cpp src/modules/Context.h
#         src/modules/Cleaner.cpp src/modules/Cleaner.h

#         tests/PwdTests.cpp
#         tests/CdTests.cpp
#         tests/EchoTests.cpp
#         tests/VariableAssignmentTests.cpp
#         tests/ExportTests.cpp
#         tests/PipeTests.cpp
#         tests/RedirectionTests.cpp
#         tests/TestMain.cpp
# )

add_executable(parse

        src/structures/Assignable.cpp src/structures/Assignable.h
        src/structures/BackTickExpr.cpp src/structures/BackTickExpr.h
        src/structures/Command.cpp src/structures/Command.h
        src/structures/Identifier.cpp src/structures/Identifier.h
        src/structures/Node.cpp src/structures/Node.h
        src/structures/PipeExpr.cpp src/structures/PipeExpr.h
        src/structures/Program.cpp src/structures/Program.h
        src/structures/RedirectionExpr.cpp src/structures/RedirectionExpr.h
        src/structures/VariableAssignment.cpp src/structures/VariableAssignment.h
        src/structures/VariableCall.cpp src/structures/VariableCall.h
        
        src/lexer.cpp

        src/modules/Executor.cpp src/modules/Executor.h
        src/modules/Context.cpp src/modules/Context.h
        src/modules/Cleaner.cpp src/modules/Cleaner.h

        src/parser.cpp src/parser.hpp
        src/main.cpp
)