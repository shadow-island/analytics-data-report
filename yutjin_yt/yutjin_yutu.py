
# -*- coding: utf-8 -*-
# python 3X
'''
최소한 오후 6:03 2020-02-15 이전에 개발 
'''

work = 74
work = round(work/60 * 1.1,1)
#source file 이름찾기?
import codecs
source_file = codecs.open('yutjin_yutu.py', 'r','utf-8')
line_list   = source_file.readlines()    
source_file.close()

count = 0
for _ in line_list:
    count += 1
print('Yutjin Youtube Version: ' + str(work) + 'H ' + str(count) + '\n')

# Python Version
def find_num(text,finding_text):
    index       = text.find(finding_text)
    size        = len(finding_text)
    location    = index + size
    return text[location:location + 1]    
import sys
major = find_num(str(sys.version_info),'major=')
minor = find_num(str(sys.version_info),'minor=')
micro = find_num(str(sys.version_info),'micro=')
print ('My Python Version: ' +  major + '.' + minor  + '.' + micro)
#~


db_xls = "db.xlsx"

import openpyxl
from openpyxl import Workbook
import os

data = []

if os.path.isfile(db_xls) == True:                
    wb = openpyxl.load_workbook(db_xls)
    sheet_list = wb.get_sheet_names()
    #print sheet_list
    sheet = wb.get_sheet_by_name('k')
    s_value = sheet.cell(row = 1, column = 1).value
    print(s_value)
    key = s_value
    sheet = wb.get_sheet_by_name('c')
    
    for i in range(1,sheet.max_row + 1):
        record = []
        record.append(sheet.cell(row = i, column = 1).value)
        record.append(sheet.cell(row = i, column = 2).value)
        data.append(record)
else:
    print(db_xls + " 없음")
    


import urllib.request
import json


print('1)list\n')
print('2)sub\n')
input_menu = input('?')
if input_menu != '2':
    list_id = 'UUClVppyt5FlY8rCTLGDgOIA'
    list_id = 'UC0Fq24M32ruKPcMH2xxxxxx' # UC로 시작하면 채널명임
    if len(input_menu) == 1:
        list_id = input('list?')
    else:
        list_id = input_menu
    
    while(True):    
        base_url = 'https://www.googleapis.com/youtube/v3/playlistItems?part=snippet&maxResults=50&playlistId=' + list_id + '&key=' + key
        nextPageToken = ""

        total_n = 1
        import datetime
        datetime_total = datetime.datetime(1,1,1,0,0,0)
        part_mode = False
        for n in range(3):
            is_breaker = False
            this_url = base_url + "&pageToken=" + nextPageToken
            json_data = urllib.request.urlopen(this_url).read()     

            item_data = json.loads(json_data)["items"]
            print(len(item_data))
            for i in range(len(item_data)):
                item_data = json.loads(json_data)["items"][i]['snippet']['title']
                print(str(total_n) + ":"+ item_data)        
                videoId = json.loads(json_data)["items"][i]['snippet']['resourceId']['videoId']
                print(videoId)
                         
                v_json_data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/videos?id=" + str(videoId) + "&part=contentDetails&key=" + key).read()
                v_item_data = json.loads(v_json_data)["items"][0]["contentDetails"]['duration']
                #debug print(v_item_data)
                v_item_data = v_item_data.replace('PT','')        
                m = s = 0
                if v_item_data.find('M') == -1:
                    v_item_data = '0:' + v_item_data
                else:
                    v_item_data = v_item_data.replace('M',':')        
                    
                if v_item_data.find('S') == -1:
                    v_item_data = v_item_data + '0'
                else:
                    v_item_data = v_item_data.replace('S','')        
                
                #print(v_item_data)        
                date_time_obj = datetime.datetime.strptime(v_item_data, '%M:%S')        
                datetime_now = datetime.timedelta(minutes = date_time_obj.minute, seconds = date_time_obj.second)
                
                datetime_total += datetime_now
                print(datetime_now)           
                print(str(datetime_total.hour) + ":" + str(datetime_total.minute))
                print()
                
                if part_mode == True and total_n == 17:
                    print(datetime_total)
                    is_breaker = True
                    break                
                total_n += 1
                
            if is_breaker == True:
                break
            
            if "nextPageToken" in json.loads(json_data):
                nextPageToken = json.loads(json_data)["nextPageToken"]
                print(nextPageToken)
                n += 1
            else:
                break
        print(datetime_total)
        input("do you want to check this list again?")
else:
    print()
    print()
    print()
    print()
    print()
    print()
    print()
    print()
    print()
    print()
    #글꼴 50,너비61
    prev_subs = 0
    total = len(data)
    for i in range(total -1 ,-1, -1):
        value = data[i][1]
        le = len(value)
        #print(le)
        if le <= 10:
            #print('--name style')
            channel_data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/channels?part=statistics&forUsername="+value+"&key="+key).read()
        else:
            channel_data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/channels?part=statistics&id=" + value + "&key="+key).read()     
        
        import time
        time.sleep(2)
        
        #print(channel_data)
        subs = int(json.loads(channel_data)["items"][0]["statistics"]["subscriberCount"])
        if prev_subs > subs:
            print('역전?')
        prev_subs = subs
        view = json.loads(channel_data)["items"][0]["statistics"]["viewCount"]
        print(str(i+1) + ':' + str(data[i][0]) + '의 구독자 수는 '+ str(subs) +'명,조회수는 ' + view  +'입니다')
        #break

input('pause')
exit(0)
