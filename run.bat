@echo off
setlocal
cd /d "%~dp0"

rem Kill any stale solution.exe that might be locking the binary
taskkill /F /IM solution.exe >nul 2>&1

g++ solution.cpp -o output\solution.exe
if errorlevel 1 (
    echo.
    echo COMPILE FAILED - fix the errors above.
    exit /b 1
)

type input.txt | output\solution.exe > output.txt
type output.txt
echo.

endlocal