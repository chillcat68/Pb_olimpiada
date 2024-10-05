@echo off
echo Testul %2
echo _________
copy teste\%2.in numar.in/y >nul
timer %1 1
copy teste\%2.ko numar.ko/y >nul
verif.exe %1 %2
pause
del numar.in
if EXIST numar.out del numar.out
del numar.ko

