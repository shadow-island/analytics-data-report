chcp 949
del eukM2.log
:_loop
	py g.py
	git commit --all -m "7m"
	git push	
	timeout /t 420
goto _loop