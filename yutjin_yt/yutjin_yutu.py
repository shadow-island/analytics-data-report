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

for i in range(0,len(data)):
    value = data[i][1] 
    if len(value) > 8:
        channel_data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/channels?part=statistics&id=" + value + "&key="+key).read()     
    else:
        channel_data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/channels?part=statistics&forUsername="+value+"&key="+key).read()
    subs = json.loads(channel_data)["items"][0]["statistics"]["subscriberCount"]
     
    print(str(i+1) + ':' + str(data[i][0]) + '의 구독자 수는 '+ '{:,d}'.format(int(subs))+' 입니다.')
exit(0)
