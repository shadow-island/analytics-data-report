chcp 949
cls
rem ----------
:_loop	
	py g.py time
	git commit --all -m "v8"
	git push
	py g.py	
goto _loop