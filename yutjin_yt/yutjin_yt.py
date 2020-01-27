# -*- coding: utf-8 -*-
# python 3X
'''
본 App 장점:
'''
import urllib.request
import json

#idn=input("Enter username: ")
idn = ""
idn = ""
#name=input("Enter username: ")

key = "개인이 발급 받은 구글API키"
key = "xxxxxxxxx"
 
data = urllib.request.urlopen("https://www.googleapis.com/youtube/v3/channels?part=statistics&id="+idn+"&key="+key).read()
 
subs = json.loads(data)["items"][0]["statistics"]["subscriberCount"]
 
print(idn + ' 님의 구독자 수는 '+ '{:,d}'.format(int(subs))+' 입니다.')
