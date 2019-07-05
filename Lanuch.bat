@echo off
start /d "C:\Program Files (x86)\Bus Hound\"  bushound.exe
start  /d  ".\" ScanService.exe
rem ping×öÔÝÍ£2sÓÃ
ping -n 2 127.1 >null
start "" ".\EXScanPro.exe"
exit


