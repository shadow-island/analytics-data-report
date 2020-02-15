chcp 949
rem del eukM2.log
:_loop	
	echo %time%
	git commit --all -m "v5"
	git push
	py g.py	
goto _loop