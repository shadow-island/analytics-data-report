chcp 949
del eukM2.log
:_loop
	time /t
	py g.py
	git commit --all -m "v1"
	git push
	time /t
goto _loop