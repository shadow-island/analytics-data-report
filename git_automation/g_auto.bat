chcp 949
del eukM2.log
:_loop
py g.py
timeout /t 40
git commit --all -m "ga1"
git push
goto _loop