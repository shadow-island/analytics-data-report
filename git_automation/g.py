# -*- coding: utf-8 -*-
# python 3X
'''
본 App 동작설명
    최초는 내가 커밋하고싶어서 일부로 고치지않는이상 안일어나야한다(사용자에게 선택권을 줘야함)
# 2nd round는 무조건 커밋 
Next: Release note
#기능 #UI
Todo:

    # 1/2만작업?(일단 오늘 영상완료까지는 늘리다가) # 
    # 1.암것도안함(이것도테스트필요) 
    # 1/3만작업?(일단 오늘 영상완료까지는 늘리다가) # kaisha 1/2작업?
    - 1 다른 application 1 .playlist batch (구독자 update)
     -2 코드 정리
     -3 git 정리 + 작업숫자만        
        밑에할차례?
        git rebase HEAD~8 -i 
        git push --force
     -4 기능향상(딱히?) commit이름 바꾸기 ver file이용?->  EMAIL?, C#화?(제자리 출력? -> 한번더 멈춘현상발생시)
'''

#version용으로 기본 공통
import sys
#~

import os
import datetime

def read_file(file_name):
    return_data = None #payload
            
    if os.path.exists(file_name):
        #euk
        my_file = open(file_name,'r')
        return_data  = my_file.readlines()
        my_file.close()
                            
    return return_data

def get_last(local_file_name, bar):
    # File이 없는경우 대비
    datetime_old_time   = datetime.datetime.now()
    int_old_sec_gap     = 0

    data_list   = read_file(local_file_name)

    count = 0
    if data_list != None:
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
    
    count =  get_last(local_file_name, bar)
    count += 1
    print ("saved value:" + str(count))
        
    my_file = open(local_file_name,"w")    
    my_file.write(str(count))
    my_file.close()    
    
    return count  

def print_time(datetime_value):
    txt = str(datetime_value)
    index = txt.find('.')
    txt = txt[:index]
    
    index = txt.find(' ')
    txt = txt[index + 1:]
    
    return txt

#global    
step_round = 0
count = 0
total = 0
datetime_target = datetime.datetime.now()

import  threading
def timer_start():  
    global count 
    count -= 1
    
    datetime_now = datetime.datetime.now()    
    #print('목표' + print_time(datetime_target) + " 현재시간:" + print_time(datetime_now))    
    text = print_time(str(datetime_target - datetime_now))
    print(text + ' ', end='' , flush = True)
    timer = threading.Timer(15, timer_start) #글꼴 크기는 제일작은것 즉 RDP기준으로하자 그외는 늘리지말것
    #if count > 0:
    #  	date1 is considered less than date2 when date1 precedes date2 in time. (4)
    if datetime_now < datetime_target:
        timer.start()
    else:
        next_round = check_update()
        run()
    return
        
def run():
    global step_round
    step_round += 1
    print("\nRound:" + str(step_round))
    print('[commit]')
    os.system('git status')
    os.system('git commit --all -m "' + 'v0 Round ' + str(step_round) + 'min"')
    print('[git push]')
    os.system('git push')
    
    import random
    
    random_num = random.randrange(2, g_maxx + 1)    
    print(random_num, '/', g_maxx)
    next_gap_timedelta = datetime.timedelta(minutes = random_num)
    
    #1
    datetime_now = datetime.datetime.now()
    print("시작시간:" + print_time(datetime_now))        
    #2 
    global datetime_target
    datetime_target = datetime_now + next_gap_timedelta
    txt = str(datetime_now + next_gap_timedelta)
    print("종료예상시간:" + print_time(txt))
    #3
    
    if step_round >= 2:
        print ('!!!!!!!!!!!!!!!! Committed at least once !!!!!!!!!!!!!!!!')
            
    '''
    #아침에 도는가보고, 끝까지가면늘림, 4~9      
    ''' 
    print("\nRound:" + str(step_round) + ' timer start')
    if step_round <= 12:
        timer_start()
    else:
        print('step_round end')
    
##main    
'''
main
'''
if __name__ == '__main__':
    work    = 262
    g_maxx  = 4*60 + 22 #(chrome RDP에 맞춤)#font26이 최대 
    
    import sys
    if len(sys.argv) == 1:        
        #print('normmal mode:no argv')
        pass
    else:
        #1
        datetime_now = datetime.datetime.now()
        ##    
        txt = str(datetime_now)
        index = txt.find('.')
        print(txt[:index])
        #~
        exit(0)
    
    work = round(work/60 * 1.1, 1)
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
    
    print('--------Git Automation Version: ' + str(work) + 'H ' + str(le) + ' My Python Version: ' +  major + '.' + minor  + '.' + micro)
    #~

    ## global
    # 무슨 모드인지 따라 folder 정함
    if os.path.exists('euk_music_2p3.linux'):
        b_windows_or_linux = False
        print ('Office Mode')
    else:
        b_windows_or_linux = True
    ##~ end of global
    
    # for both read and save
    local_file_name = 'eukM2.log'
    bar             = '~'
    #~
    print(get_last(local_file_name, bar))

    #global count
    run()