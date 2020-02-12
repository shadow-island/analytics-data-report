py g.py
:_loop
timeout /t 1
git commit --all -m "ga"
git push
goto _loop