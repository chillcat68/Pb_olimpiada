@echo off
for %%i IN (1 2 3 4 5 6 7 8 9 0) DO  call test.bat %1 %%i
afiseaza %1
del punctaj.txt
pause

