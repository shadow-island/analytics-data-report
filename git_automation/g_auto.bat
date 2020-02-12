:_loop
py g.py
timeout /t 8
git commit --all -m "ga"
git push
goto _loop