cp ..\..\debug\flipbyte.exe flipbyte.exe 

REM [run without params]
flipbyte.exe
@IF NOT ERRORLEVEL 1 GOTO err

REM [run with not num param]

flipbyte.exe not_a_number
@IF NOT ERRORLEVEL 1 GOTO err

REM [run with number less then 0]

flipbyte.exe -1
@IF NOT ERRORLEVEL 1 GOTO err

REM [run with number more then 255]

flipbyte.exe 256
@IF NOT ERRORLEVEL 1 GOTO err

REM [run with number = 0]
flipbyte.exe 0 > output.txt
@IF ERRORLEVEL 1 GOTO err
fc /B output.txt !0.txt
@IF ERRORLEVEL 1 GOTO err

REM [run with number = 255]
flipbyte.exe 255 > output.txt
@IF ERRORLEVEL 1 GOTO err
fc /B output.txt !255.txt
@IF ERRORLEVEL 1 GOTO err

REM [run with number = 6]
flipbyte.exe 6 > output.txt
@IF ERRORLEVEL 1 GOTO err
fc /B output.txt !6.txt
@IF ERRORLEVEL 1 GOTO err

REM [run with number = 96]
flipbyte.exe 96 > output.txt
@IF ERRORLEVEL 1 GOTO err
fc /B output.txt !96.txt
@IF ERRORLEVEL 1 GOTO err

@ECHO Program testing succeeded :-)

EXIT

:err
@ECHO Program testing failed :-(
EXIT
