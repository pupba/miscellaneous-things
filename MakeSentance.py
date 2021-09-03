import os
import pandas as pd
import random
# pip install git+https://github.com/alainrouillon/py-googletrans@feature/enhance-use-of-direct-api
from googletrans import Translator

root = os.getcwd().replace('\\','/')
filename = '/voca.xlsx'

df = pd.read_excel(root+filename)
voca_dict=dict(zip(df['단어'],df['뜻']))
keys = list(voca_dict.keys())
# 랜덤으로 단어와 뜻 가져오기
random.shuffle(keys)
print('단어--> ',keys[0],'| 뜻-->',voca_dict[keys[0]])
# 선택된 단어로 문장 만들기 
sentence = str(input('문장을 만들어 주세요~ : '))
# 구글 api로 번역
translator = Translator(service_urls=['translate.googleapis.com'])
my_sentence = translator.translate(sentence,src='en',dest='ko').text
print('문장--->'+sentence,'\n번역--->'+my_sentence)