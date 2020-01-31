# -*- coding: utf-8 -*-
# python 3X
'''
'''



db_xls = "db.xlsx"

import openpyxl
from openpyxl import Workbook
import os

if os.path.isfile(db_xls) == True:                
    wb = openpyxl.load_workbook(db_xls)
    sheet_list = wb.get_sheet_names()
    #print sheet_list
    sheet = wb.get_sheet_by_name(sheet_list[0])
    s_value = sheet.cell(row = 1, column = 1).value
    print(s_value)
    '''
    for i in range(1,sheet.max_row + 1):
        i_value = int(sheet.cell(row = i, column = 2).value)                

        print_text = sheet.cell(row = i, column = 1).value + ':' + str(sheet.cell(row = i, column = 2).value)
        random_num = random.randrange(1,i_value + 1)
        if (random_num == 1):                         
            try:
                print (str(i_value) + '-' + str(random_num) + ':' + print_text + ' Ok')                 
            except:
                pass
            
            out_txt = sheet.cell(row = i, column = 1).value + '\n'
            if b_windows_or_linux == False:                
                out_txt = out_txt.replace(mp3_folder_no_endslash + '\\','/my/ongaku/')
                out_txt = out_txt.replace('\\','/')
            txt_file.write(out_txt)
            count = count + 1
        else:
            try :
                print (print_text + ' X')                
            except:
                pass
    '''
else:
    print(db_xls + " 없음")

exit(0)
key = "개인이 발급 받은 구글API키"



data = [
    ['',        ''],
 
]

import urllib.request
import json

for d in data:
    value = d[1] 
    if len(value) > 8:
        channel_data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/channels?part=statistics&id=" + value + "&key="+key).read()     
    else:
        channel_data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/channels?part=statistics&forUsername="+value+"&key="+key).read()
    subs = json.loads(channel_data)["items"][0]["statistics"]["subscriberCount"]
     
    print(str(d[0]) + '의 구독자 수는 '+ '{:,d}'.format(int(subs))+' 입니다.')