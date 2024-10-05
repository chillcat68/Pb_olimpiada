@echo off
cls
echo Problema  - iepuri
echo __________________
echo Testul %2
copy teste\iepuri%2.in iepuri.in
timer %1 1

if errorlevel 2 goto timeout

copy teste\iepuri%2.ko iepuri.ko
verif.exe
pause
goto sfarsit

:timeout
echo.
echo TIMP DEPASIT!
pause
echo.

:sfarsit
if exist iepuri.out del iepuri.out
if exist iepuri.in del iepuri.in
if exist iepuri.ko del iepuri.ko
