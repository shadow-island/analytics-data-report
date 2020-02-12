:_loop
py g.py
timeout /t 3
git commit --all -m "ga"
git push
goto _loop