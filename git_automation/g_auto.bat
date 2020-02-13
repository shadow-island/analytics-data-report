chcp 949
:_loop
del eukM2.log
py g.py
timeout /t 13
git commit --all -m "ga"
git push
goto _loop