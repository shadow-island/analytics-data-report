chcp 949
rem ----------
:_loop	
	py g.py time
	git commit --all -m "v7"
	git push
	py g.py	
goto _loop