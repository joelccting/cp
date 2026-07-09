@echo off
REM Delete all .exe files in current directory and subdirectories
for /r %%i in (*.exe) do (
    echo Deleting "%%i"
    powershell -command "Remove-Item '%%i' -Recycle"
)
echo Done!
pause
