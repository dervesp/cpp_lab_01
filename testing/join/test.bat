cp ..\..\debug\join.exe join.exe

REM [run without params]
join.exe
@IF NOT ERRORLEVEL 1 GOTO err

REM [run with one param]

join.exe input1.txt
@IF NOT ERRORLEVEL 1 GOTO err

REM [run with unexisting input file]

join.exe unexistingInput.txt output.txt
@IF NOT ERRORLEVEL 1 GOTO err

REM [run with one input file]
join.exe input1.txt output.txt
@IF ERRORLEVEL 1 GOTO err
copy /b input1.txt !copy_output.txt
fc /B output.txt !copy_output.txt
@IF ERRORLEVEL 1 GOTO err

REM [run with two input files]
join.exe input1.txt input2.txt output.txt
@IF ERRORLEVEL 1 GOTO err
copy /b input1.txt+input2.txt !copy_output.txt
fc /B output.txt !copy_output.txt
@IF ERRORLEVEL 1 GOTO err

REM [run with three input files]
join.exe input1.txt input2.txt input3.txt output.txt
@IF ERRORLEVEL 1 GOTO err
copy /b input1.txt+input2.txt+input3.txt !copy_output.txt
fc /B output.txt !copy_output.txt
@IF ERRORLEVEL 1 GOTO err

REM [run with empty input file]
join.exe inputEmpty.txt output.txt
@IF ERRORLEVEL 1 GOTO err
copy /b inputEmpty.txt  !copy_output.txt
fc /B output.txt !copy_output.txt
@IF ERRORLEVEL 1 GOTO err

REM [run with long input files]
join.exe inputLong1.txt inputLong2.txt output.txt
@IF ERRORLEVEL 1 GOTO err
copy /b inputLong1.txt+inputLong2.txt  !copy_output.txt
fc /B output.txt !copy_output.txt
@IF ERRORLEVEL 1 GOTO err

@ECHO Program testing succeeded :-)

EXIT

:err
@ECHO Program testing failed :-(
EXIT
