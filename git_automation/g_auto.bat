:_loop
py g.py
timeout /t 6
git commit --all -m "ga"
git push
goto _loop