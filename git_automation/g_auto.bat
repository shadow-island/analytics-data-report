chcp 949
del eukM2.log
:_loop
	py g.py
	timeout /t 60
	git commit --all -m "ga1m"
	git push
goto _loop