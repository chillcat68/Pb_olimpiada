@echo off
echo Testul %2
echo _________
copy teste\colaj%2.in colaj.in/y >nul
timer %1 1
copy teste\colaj%2.ok colaj.ok/y >nul
verif.exe %1 %2
pause
del colaj.in 
del colaj.out
del colaj.ok

