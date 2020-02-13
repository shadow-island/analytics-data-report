chcp 949
del eukM2.log
:_loop
	py g.py
	git commit --all -m "6m"
	git push	
	timeout /t 360
goto _loop