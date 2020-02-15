chcp 949
rem del eukM2.log
:_loop	
	echo 시각: %time%
	time /t
	git commit --all -m "v4"
	git push
	py g.py	
goto _loop