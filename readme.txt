How to compile all the algorithms into executables:
1. Open the bash console on the flip server.
2. In the console, navigate to the directory containing all the source files
3. Type in "make" into the console.
4. All executables should compile correctly.

Executeable Guide (To be followed after compiling):
1. Run "changeslow [testfilename]" in the console to run the recursive implemention (algorithm 1)
2. Run "changegreedy [testfilename]" in the console to run the greedy implemention (algorithm 2)
3. Run "changedp [testfilename]" in the console to run the dynamic programming implemention (algorithm 3)

Behavior after running each executable:
- The results will be put into the file: [testfilename]change.txt

Extras:
- Run "make clean" to clean all the compiled executables and to clean the results file.
