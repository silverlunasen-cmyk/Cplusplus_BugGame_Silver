# Cplusplus_BugGame_Silver

### References (where i found half the code)

* https://cplusplus.com/doc/tutorial/typecasting/
* https://www.w3schools.com/cpp/cpp_auto.asp
* https://cplusplus.com/reference/vector/vector/
* https://cplusplus.com/reference/


### Known bugs (pun intended) and other information
* ~~For whatever reason, the bugs.txt only takes in 5 items, it is confusing and I am unsure how to fix it~~ | this was fixed, the issue was that I accidentally included a semicolon at the end of line 5.
* The game could potentially go on for a long time, so the win condition could be hard to find
* The history.txt file that is printed when you go to section 8, saves itself to the cmake-build-debug folder, not neccisarily a bug, just something i thought to point out.
* The vampire bug drains 5 health of it's rival (takes 5 off and gets the 5), and moves any space between 1 and 3;
