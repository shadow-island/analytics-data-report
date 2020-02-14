chcp 949
del eukM2.log
:_loop
	py g.py
	git commit --all -m "v2"
	git push
	time /t
goto _loop