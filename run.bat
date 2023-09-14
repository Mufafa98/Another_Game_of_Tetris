@echo off
echo -----Starting----
echo.

g++ -g -c src/*.cpp -Iinclude -Iinclude\SFML-2.6.0\include -std=c++17 
g++ -g *.o -o bin/Another_Game_of_Tetris.exe -Linclude\SFML-2.6.0\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++17 



del *.o
cd bin
Another_Game_of_Tetris.exe
cd ..


echo.
echo -------End-------
REM pause