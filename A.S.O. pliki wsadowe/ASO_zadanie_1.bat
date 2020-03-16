@echo off
echo [1] stona TEB
echo [2] E-learning 
echo [3] FaceBook
echo [4] niebezpieczkik.pl 

set /p wybor=Wybierz strone do otwarcia: 
if %wybor%==1 start http://teb.pl
if %wybor%==2 start https://e-teb.pl
if %wybor%==3 start https://www.facebook.com/technikumTEBKatowice/
if %wybor%==4 start https://niebezpiecznik.pl  

