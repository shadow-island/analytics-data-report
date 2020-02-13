chcp 949
del eukM2.log
:_loop
	py g.py
	git commit --all -m "8m"
	git push	
	timeout /t 480
goto _loop