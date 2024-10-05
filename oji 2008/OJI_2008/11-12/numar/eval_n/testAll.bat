@echo off
if EXIST numar.pct del numar.pct
for %%i IN (1 2 3 4 5 6 7 8 9 10) DO  call test.bat %1 %%i
afiseaza %1
del numar.pct
pause





