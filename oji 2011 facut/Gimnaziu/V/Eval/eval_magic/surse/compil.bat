@echo off
set path=c:\borlandc\bin;c:\bp\bin;%path%
for %%f in (*.pas) do call bpc %%f
for %%f in (*.cpp *c) do call bcc %%f

del *.obj