echo off
set plugin = %1
set project = %2
md %cd%\%2\Plugins
mklink /d ..\%2\Plugins\%1 %cd%\%1 
echo adding ..\%1 to ..\%2\Plugins