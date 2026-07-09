@echo off
REM Delete all .exe files in current directory and subdirectories
for /r %%i in (*.exe) do (
    echo Deleting "%%i"
    del "%%i"
)
echo Done!
pause
