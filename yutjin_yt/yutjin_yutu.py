
# -*- coding: utf-8 -*-
# python 3X
'''
'''



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


list_id = 'UUClVppyt5FlY8rCTLGDgOIA'
list_id = input('list?')
base_url = 'https://www.googleapis.com/youtube/v3/playlistItems?part=snippet&maxResults=50&playlistId=' + list_id + '&key=' + key
nextPageToken = ""


total_n = 1
import datetime
datetime_total = datetime.datetime(1,1,1,0,0,0)
for n in range(2):
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
        
        print()
        total_n += 1
        
        
    if "nextPageToken" in json.loads(json_data):
        nextPageToken = json.loads(json_data)["nextPageToken"]
        print(nextPageToken)
        n += 1
    else:
        break
print(datetime_total)
input('pause')
exit(0)







for i in range(0,len(data)):
    value = data[i][1] 
    if len(value) > 8:
        channel_data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/channels?part=statistics&id=" + value + "&key="+key).read()     
    else:
        channel_data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/channels?part=statistics&forUsername="+value+"&key="+key).read()
    subs = json.loads(channel_data)["items"][0]["statistics"]["subscriberCount"]
     
    print(str(i+1) + ':' + str(data[i][0]) + '의 구독자 수는 '+ '{:,d}'.format(int(subs))+' 입니다.')
exit(0)
