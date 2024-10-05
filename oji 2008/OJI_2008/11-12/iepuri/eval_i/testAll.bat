@echo off
del *.out
for %%i IN (0 1 2 3 4 5 6 7 8 9) DO  call test.bat %1 %%i
afiseaza %1
del punctaj.txt
pause






