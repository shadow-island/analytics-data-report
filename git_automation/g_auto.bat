chcp 949
del eukM2.log
:_loop
py g.py
timeout /t 50
git commit --all -m "ga50s"
git push
goto _loop