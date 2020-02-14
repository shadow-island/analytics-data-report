# -*- coding: utf-8 -*-
# python 3X
'''
본 App 장점:
Next:
Release note
#기능
#UI
'''

import os
import sys
import datetime

def read_file(file_name):
    return_flag = True
    return_data = None
            
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
    #datetime_old_time   = datetime.datetime(2014, 8, 3, 0,0,0)
    datetime_old_time   = datetime.datetime.now()
    int_old_sec_gap     = 0

    (return_flag, data_list)   = read_file(local_file_name)

    count = 0
    if return_flag == True:
        for line in data_list:
            #item_list값을 밖에서 쓸수없음 bc)file이 없을경우가 잇으므로
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
    
    print ("previous value: " + str(count))
    count += 1

        
    my_file = open(local_file_name,"w")    
    my_file.write(str(count))
    my_file.close()    
    
    return int_new_gap

##main    
'''
main
'''
if __name__ == '__main__':
    work = 33
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
    print('----')
    print('Git Automation Version: ' + str(work) + 'H ' + str(le) + ' My Python Version: ' +  major + '.' + minor  + '.' + micro)
    #~

    ## global
    b_windows_or_linux = True
    db_xls = 'db.xlsx'    

    # 무슨 모드인지 따라 folder 정함
    if os.path.exists('euk_music_2p3.linux'):
        b_windows_or_linux = False
        print ('Office Mode')
    else:
        b_windows_or_linux = True
        #print ('Home windows Mode')
    ##~ end of global

    #init
    int_new_gap = 0
    check_update()
    print(datetime.datetime.now())
    # 숫자만 늘림
    # 1/3 작업모드    
    # 1 코드 정리 + 작업숫자만
    # 2 git 정리 + 작업숫자만
    # 3 기능추가
    
    import random
    maxx = 26
    random_num = random.randrange(2, maxx + 1) #17
    print(random_num, '/',maxx)
    print("timer start...")
    import time
    time.sleep(random_num*60)    
    print("timer end")
