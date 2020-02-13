:_loop
del eukM2.log
py g.py
timeout /t 12
git commit --all -m "ga"
git push
goto _loop