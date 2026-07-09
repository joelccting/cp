@echo off
REM Recursively send all .exe files in subfolders to Recycle Bin

for /r %%i in (*.exe) do (
    echo Recycling "%%i"
    powershell -command "Remove-Item '%%i' -Recycle"
)

echo Done!
pause
