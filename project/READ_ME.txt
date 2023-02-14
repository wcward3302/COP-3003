Project read me file

will update directory to show different stages of development (IE iteration 1, iteration 2, etc.)
"Stage 1 proof of concept" video shows code compiling, running, and operating as intended at the moment. 
stage-1.cpp is source code, decent comments for each block

At the moment:
- project pops up a window
- displays text, shape, and background
- taks in user input from keyboard
- uses input to move shape around screen



G++ command to compile and pass SFML library sources: 

g++ -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system -o test.out stage-1.cpp
