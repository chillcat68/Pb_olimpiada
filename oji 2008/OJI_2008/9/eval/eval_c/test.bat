@echo off
echo Testul %2
echo _________
copy teste\%2.in concurs.in/y >nul
timer %1 1
copy teste\%2.ok concurs.ok/y >nul
copy teste\%2.in concurs.in/y >nul
verif.exe %1 %2
pause
del concurs.in 
del concurs.out
del concurs.ok

