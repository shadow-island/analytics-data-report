chcp 949
del eukM2.log
:_loop
	time /t
	py g.py
	git commit --all -m "9m"
	git push
	time /t
	timeout /t 540
goto _loop