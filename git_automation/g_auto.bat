chcp 949
cls
:_loop	
	py g.py time
	rem git commit --all -m "v9"	
	py g.py	
	git push
goto _loop