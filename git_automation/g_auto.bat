chcp 949
del eukM2.log
:_loop
	py g.py
	git commit --all -m "ga5m"
	git push	
	timeout /t 300
goto _loop