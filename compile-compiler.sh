#!/bin/csh -f

cd assignments
cd PA2
make clean
make lexer
cd ..
cd PA3
make clean
make parser
cd ..
cd PA4
make clean
make semant
cd ..
cd PA5
make clean
make cgen
