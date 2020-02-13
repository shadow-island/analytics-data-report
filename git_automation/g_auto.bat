chcp 949
del eukM2.log
:_loop
	py g.py
	git commit --all -m "ga3m"
	git push	
	timeout /t 180
goto _loop