chcp 949
del eukM2.log
:_loop
py g.py
timeout /t 20
git commit --all -m "ga"
git push
goto _loop