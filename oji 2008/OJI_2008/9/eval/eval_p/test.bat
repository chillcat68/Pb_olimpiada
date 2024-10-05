@echo off
echo Testul %2
echo _________
copy teste\%2-pl.in pluricex.in/y >nul
timer %1 1
copy teste\%2-pl.o pluricex.ok/y >nul
copy teste\%2-pl.in pluricex.in/y >nul
verif.exe %1 %2
pause
del pluricex.in 
del pluricex.out
del pluricex.ok

