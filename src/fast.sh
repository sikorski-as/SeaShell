#!/usr/bin/sh
CURR=`pwd`
cd `dirname $0`
flex -o lexer.cpp lexer.flex
bison -d -o parser.cpp parser.ypp
cd $CURR