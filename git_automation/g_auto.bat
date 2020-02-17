chcp 949
cls
:_loop	
	py g.py time
	rem git commit --all -m "v9"
	git push
	py g.py	
goto _loop