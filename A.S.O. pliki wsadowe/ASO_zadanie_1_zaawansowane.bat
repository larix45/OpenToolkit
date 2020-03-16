@echo off
:wybor
echo [1] teb.pl
echo [2] e-teb.pl
echo [3] facebook TEB'u
echo [4] niebezpiecznik.pl 

set /p wybor=Wybierz co otworzyc: 
if %wybor%==1 (
start http://teb.pl
exit
)
if %wybor%==2 (
start https://e-teb.pl
exit
)
if %wybor%==3 (
start https://www.facebook.com/technikumTEBKatowice/
exit
)
if %wybor%==4 (
start https://niebezpiecznik.pl
exit
)  
echo ===WYBIERZ JESZCZE RAZ!===                                      
goto wybor
