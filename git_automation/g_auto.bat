chcp 949
rem del eukM2.log , echo %time%
:_loop	
	py g.py time
	git commit --all -m "v6"
	git push
	py g.py	
goto _loop