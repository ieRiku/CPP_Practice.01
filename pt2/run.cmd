@echo off
if "%~1"=="" (
    echo Usage: run.cmd input.cpp
    exit /b 1
)
g++ %* -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32