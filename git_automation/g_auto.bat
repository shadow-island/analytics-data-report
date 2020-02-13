chcp 949
del eukM2.log
:_loop
	time /t
	py g.py
	git commit --all -m "14m"
	git push
	time /t
	timeout /t 840
goto _loop