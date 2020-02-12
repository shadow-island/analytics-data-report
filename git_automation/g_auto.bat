:_loop
py g.py
timeout /t 7
git commit --all -m "ga"
git push
goto _loop