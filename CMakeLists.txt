cmake_minimum_required(VERSION 3.10)
project(uxp)

set(CMAKE_CXX_STANDARD 14)

add_executable(uxp
        src/main.cpp

        src/structures/Node.cpp src/structures/Node.h
        src/structures/Program.cpp src/structures/Program.h

        src/structures/VarPip.cpp src/structures/VarPip.h
        src/structures/Variable.cpp src/structures/Variable.h
        src/structures/Pipeline.cpp src/structures/Pipeline.h
        src/structures/Command.cpp src/structures/Command.h
        src/structures/Value.cpp src/structures/Value.h

        src/modules/Context.cpp src/modules/Context.h
        )

#add_executable(uxp
#        src/main.cpp
#        src/structures/Assignable.cpp
#        src/structures/BackTickExpr.cpp
#        src/structures/Command.cpp
#        src/structures/Indentifier.cpp
#        src/structures/Node.cpp
#        src/structures/PipeExpr.cpp
#        src/structures/Program.cpp
#        src/structures/RedirectionExpr.cpp
#        src/structures/VariableAssignment.cpp
#        src/structures/VariableCall.cpp
#
#        src/modules/Executor.cpp src/modules/Executor.h
#        src/modules/Interpreter.cpp src/modules/Interpreter.h
#        src/modules/Context.cpp src/modules/Context.h
#        src/modules/Shell.cpp src/modules/Shell.h
#        )

#add_executable(exec_test
#
#        src/modules/Executor.cpp src/modules/Executor.h
#        src/modules/Context.cpp src/modules/Context.h
#        src/modules/Cleaner.cpp src/modules/Cleaner.h
#
#        src/main.cpp src/structures/Node.cpp src/structures/Node.h)

#add_executable(parse
#        src/structures/Assignable.cpp
#        src/structures/BackTickExpr.cpp
#        src/structures/Command.cpp
#        src/structures/Indentifier.cpp
#        src/structures/Node.cpp
#        src/structures/PipeExpr.cpp
#        src/structures/Program.cpp
#        src/structures/RedirectionExpr.cpp
#        src/structures/VariableAssignment.cpp
#        src/structures/VariableCall.cpp
#
#        src/lexer.cpp
#
#        src/modules/Executor.cpp src/modules/Executor.h
#        src/modules/Context.cpp src/modules/Context.h
#        src/modules/Cleaner.cpp src/modules/Cleaner.h
#
#        src/parser.cpp src/parser.hpp
#        )

