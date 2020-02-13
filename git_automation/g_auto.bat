chcp 949
del eukM2.log
:_loop
	py g.py
	git commit --all -m "9m"
	git push	
	timeout /t 540
goto _loop