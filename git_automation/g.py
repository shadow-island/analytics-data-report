# -*- coding: utf-8 -*-
# python 3X
'''
본 App 장점:
# 최초는 내가 커밋하고싶어서 일부로 고치지않는이상 안일어나야한다,(사용자에게 선택권을 줘야함)
# 2nd round는 무조건 커밋 
Next:
Release note
#기능
#UI
Todo:
    # 1.암것도안함(이것도테스트필요) 
    # 1/3만작업?(일단 오늘 영상완료까지는 늘리다가)
    - 1 숫자만늘림 
     -2 코드 정리
     -3 git 정리 + 작업숫자만
        git rebase HEAD~6 -i
        git push --force
     -4 기능향상,batch file도
     -5 다른 application PL2efNl7MkFIC_egRbKPmX4oRr_tPs5uyc
        카톡채팅 - 시간조정기능(일단 숨기기가쉬움)    
'''

#version용으로 기본 공통
import sys
#~
import os
import datetime

def read_file(file_name):
    return_flag = True #error code
    return_data = None #payload
            
    if os.path.exists(file_name):
        #euk
        my_file = open(file_name,'r')
        return_data  = my_file.readlines()
        my_file.close()
    else:
        return_flag = False
                            
    return (return_flag, return_data)

def get_last(local_file_name, bar):
    # File이 없는경우 대비
    datetime_old_time   = datetime.datetime.now()
    int_old_sec_gap     = 0

    (return_flag, data_list)   = read_file(local_file_name)

    count = 0
    if return_flag == True:
        for line in data_list:
            #item_list값을 밖에서 쓸수없음 bc)file이 없을경우가 잇으므로
            if line.isdigit() == True:
                count = int(line)
    else:
        print ('No file and clean Mode')
    #file reading end
    return count

def check_update():
    import datetime
    
    # for both read and save
    local_file_name = 'eukM2.log'
    bar             = '~'
    #~
    
    count =  get_last(local_file_name, bar)    
    count += 1
    print ("saved value:" + str(count))
        
    my_file = open(local_file_name,"w")    
    my_file.write(str(count))
    my_file.close()    
    
    return count
    


##main    

'''
main
'''
if __name__ == '__main__':
    import sys
    if len(sys.argv) == 1:
        print('normmal mode:no argv')
    else:
        #1
        datetime_now = datetime.datetime.now()
        ##    
        txt = str(datetime_now)
        index = txt.find('.')
        print(txt[:index])
        #~
        exit(0)
        
    work = 73
    work = round(work/60 * 1.1,1)
    #source file 이름찾기?
    import codecs
    source_file = codecs.open('g.py', 'r','utf-8')
    line_list   = source_file.readlines()
    le = len(line_list)
    source_file.close()
        
    # Python Version
    def find_num(text,finding_text):
        index = text.find(finding_text)
        size        = len(finding_text)
        location    = index + size
        return text[location:location + 1]    

    major = find_num(str(sys.version_info),'major=')
    minor = find_num(str(sys.version_info),'minor=')
    micro = find_num(str(sys.version_info),'micro=')
    print("--------")
    print('Git Automation Version: ' + str(work) + 'H ' + str(le) + ' My Python Version: ' +  major + '.' + minor  + '.' + micro)
    #~

    ## global
    # 무슨 모드인지 따라 folder 정함
    if os.path.exists('euk_music_2p3.linux'):
        b_windows_or_linux = False
        print ('Office Mode')
    else:
        b_windows_or_linux = True
    ##~ end of global

    #init
    int_new_gap = 0
    
    def print_time(datetime_value):
        txt = str(datetime_value)
        index = txt.find('.')
        return txt[:index]
        
    #1
    datetime_now = datetime.datetime.now()
    print(print_time(datetime_now))
        
    #2
    import random
    maxx = 67
    random_num = random.randrange(2, maxx + 1)    
    print(random_num, '/',maxx)      
    next_gap_timedelta = datetime.timedelta(minutes = random_num)
    
    #3    
    txt = str(datetime_now + next_gap_timedelta)
    print("종료예상시간:" + print_time(txt))
    
    import time
    #random_num = 0  #debug
    for i in range(random_num,-1,-1):        
        print(i)
        if i != 0:
            time.sleep(60)
        
    #time.sleep(20)   
    print("timer end")
    
    #update
    next_round = check_update()
    if next_round >= 3:
        print ('!!!!!!!!!!!!!!!! Committed at least once !!!!!!!!!!!!!!!!')
        
    
    os.system('git commit --all -m "v11"')

