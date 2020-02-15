chcp 949
del eukM2.log
:_loop	
	time /t
	git commit --all -m "v3"
	git push
	py g.py	
goto _loop