# -*- coding: utf-8 -*-  
'''
Created on Sep 16, 2016

@author: euk
'''

# Functions
def remove(text,removing_text):
    return text.replace(removing_text,'')

def extract_from(str_html, starting_text):        
    index       = str_html.find(starting_text)                            
    size        = len(starting_text)        
    str_html    = str_html[index + size:]
    return str_html
                               
def extract(str_html, starting_text, ending_text):    
    str_html = extract_from(str_html, starting_text)
    
    index       = str_html.find(ending_text)
    str_html    = str_html[:index]
    return str_html  

# Procedure

# this is called by any main application
def print_data(basic_url):
    import os
    import urllib.request
    
    file_name  = 'hot.csv'
    # file 있는경우 
    if os.path.exists(file_name):
        my_file     = open(file_name,'r')
        data_list   = my_file.readlines()
        my_file.close()
 
        number = 1   
        for line in data_list:            
            line = remove(line,'\n')     
            url_part_utf8 = urllib.request.quote(line.encode('utf8'))       
            url = basic_url + url_part_utf8
            
            #print(url)
            ### f?        
            urllib_common = urllib.request
            # utf8때문에 아래 헤더 필요
            req = urllib_common.Request(url, headers={'User-Agent' : "Magic Browser"})
            try:
                raw_html = urllib_common.urlopen( req ).read()
            except: 
                print('error!')
                print('잘못된주소? or Internet 안됨')
                quit()
                
            # UTF-8 방식의 byte code → Unicode:
            unicode_html = str(raw_html.decode("utf-8"))
            ###~
            title = extract(unicode_html,'title>','</title>')
            
            #print(title) 
        
            print(str(number)+'.')
            print('<a href="' + url +'">' +  title + '</a><br><br>')
            number = number + 1
            #input('ready?')
    return
    