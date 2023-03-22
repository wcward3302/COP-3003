Project read me file

will update directory to show different stages of development (IE iteration 1, iteration 2, etc.)
"Stage 1 proof of concept" video shows code compiling, running, and operating as intended at the moment. 
stage-1.cpp is source code, decent comments for each block

At the moment:
- Does all from stage 1 and
- Uses custom sprites for ship and wall
- Has a temp collision detection method, will be updated and made better
- Custom ship image inserts, has size and coordinates. Same goes for the walls. 



G++ command to compile and pass SFML library sources: 

g++ -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system -o test.out stage2.cpp classes.cpp
