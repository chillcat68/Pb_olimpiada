@echo off
echo Testul %2
echo _________
copy teste\%2-piata.in piata.in/y >nul
timer %1 1
copy teste\%2-piata.ok piata.ok/y >nul
verif.exe %1 %2
pause
del piata.in 
del piata.out
del piata.ok

