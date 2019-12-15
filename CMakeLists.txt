cmake_minimum_required(VERSION 3.10)
project(uxp)

set(CMAKE_CXX_STANDARD 14)

add_executable(uxp
        src/main.cpp
        src/structures/Assignable.cpp
        src/structures/BackTickExpr.cpp
        src/structures/Command.cpp
        src/structures/Indentifier.cpp
        src/structures/Node.cpp
        src/structures/PipeExpr.cpp
        src/structures/Program.cpp
        src/structures/RedirectionExpr.cpp
        src/structures/VariableAssignment.cpp
        src/structures/VariableCall.cpp

        src/modules/Executor.cpp src/modules/Executor.h
        src/modules/Interpreter.cpp src/modules/Interpreter.h
        src/modules/Shell.cpp src/modules/Shell.h
        )

add_executable(exec_test
        src/structures/Assignable.cpp
        src/structures/BackTickExpr.cpp
        src/structures/Command.cpp
        src/structures/Indentifier.cpp
        src/structures/Node.cpp
        src/structures/PipeExpr.cpp
        src/structures/Program.cpp
        src/structures/RedirectionExpr.cpp
        src/structures/VariableAssignment.cpp
        src/structures/VariableCall.cpp

        tests/PwdTests.cpp
        tests/CdTests.cpp
        tests/EchoTests.cpp
        tests/VariableAssignmentTests.cpp
        tests/TestMain.cpp
)
