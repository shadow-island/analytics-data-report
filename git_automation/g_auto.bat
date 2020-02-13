chcp 949
del eukM2.log
:_loop
	py g.py
	git commit --all -m "ga2m"
	git push	
	timeout /t 120
goto _loop