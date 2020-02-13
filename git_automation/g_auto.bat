chcp 949
del eukM2.log
:_loop
	time /t
	py g.py
	git commit --all -m "16m"
	git push
	time /t
	timeout /t 960
goto _loop