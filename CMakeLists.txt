cmake_minimum_required(VERSION 3.10)
project(uxp)

set(CMAKE_CXX_STANDARD 14)

add_executable(uxp
        src/main.cpp

        src/modules/Shell.cpp src/modules/Shell.h
        src/structures/Program.cpp src/structures/Program.h
        src/structures/VarPip.cpp src/structures/VarPip.h
        src/structures/Variable.cpp src/structures/Variable.h
        src/structures/Pipeline.cpp src/structures/Pipeline.h
        src/structures/Command.cpp src/structures/Command.h
        src/structures/Value.cpp src/structures/Value.h
        src/modules/Context.cpp src/modules/Context.h
        src/modules/Builtins.cpp src/modules/Builtins.h)

add_executable(tests
        tests/TestMain.cpp

        src/modules/Shell.cpp src/modules/Shell.h
        src/structures/Program.h src/structures/Program.cpp
        src/structures/VarPip.h src/structures/VarPip.cpp
        src/structures/Variable.h src/structures/Variable.cpp
        src/structures/Pipeline.h src/structures/Pipeline.cpp
        src/structures/Command.h src/structures/Command.cpp
        src/structures/Value.h src/structures/Value.cpp
        src/modules/Context.cpp src/modules/Context.h
        src/modules/Builtins.cpp src/modules/Builtins.h

        tests/ErrorTests.h tests/ErrorTests.cpp
        tests/BackTickExprTests.h tests/BackTickExprTests.cpp
        tests/PwdTests.h tests/PwdTests.cpp
        tests/CdTests.h tests/CdTests.cpp
        tests/EchoTests.h tests/EchoTests.cpp
        tests/VariableAssignmentTests.h tests/VariableAssignmentTests.cpp
        tests/ExportTests.h tests/ExportTests.cpp
        tests/PipeTests.h tests/PipeTests.cpp
        tests/RedirectionTests.h tests/RedirectionTests.cpp
        tests/ContextTests.h tests/ContextTests.cpp)

add_executable(parse
        src/main.cpp
        src/modules/Shell.cpp src/modules/Shell.h

        src/structures/Program.h src/structures/Program.cpp
        src/structures/VarPip.h src/structures/VarPip.cpp
        src/structures/Variable.h src/structures/Variable.cpp
        src/structures/Pipeline.h src/structures/Pipeline.cpp
        src/structures/Command.h src/structures/Command.cpp
        src/structures/Value.h src/structures/Value.cpp
        src/modules/Context.cpp src/modules/Context.h
        src/modules/Builtins.cpp src/modules/Builtins.h)