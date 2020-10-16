# 토익 단어와 뜻을 읽어와 랜덤으로 맞추는 프로그램
# 1. 영단어 맞추기
# 2. 뜻 맞추기
# 3. 단어랑 뜻 엑셀로 읽어오기

import pandas as pd
import os
import random
import wx

path = os.getcwd() # 경로
# 단어장 읽어오기
df = pd.read_excel(path+'/단어/토익.xlsx') # 읽어오기

# zip() dict() 단어 뜻 끼리 리스트로 변환
voca = list(zip(df.loc[0,'A':'J'],df.loc[1,'A':'J']))
voca1 = list(zip(df.loc[2,'A':'J'],df.loc[3,'A':'J']))
voca2 = list(zip(df.loc[4,'A':'J'],df.loc[5,'A':'J']))


voca.extend(voca1)
voca.extend(voca2) # 한개의 리스트로 병합
vdic = dict(voca) # 사전으로 만들기
mlist = list(vdic.values()) # 문제 출제를 위해 뜻을 리스트로 만듬
klist = list(vdic.keys()) # 문제 출제를 위해 단어를 리스트로 만듬
mdic = dict(zip(mlist,klist))# 사전으로 만들기


app = wx.App()
frame = wx.Frame(None)
# 사이즈 설정
fsize = wx.Size(300, 300)  # 사이즈 설정
frame.SetSize(fsize)
fpos = wx.Point(300, 100)  # 위치 설정
frame.SetPosition(fpos)
frame.SetTitle("주문서 처리")  # 윈도우바 타이틀 설정
frame.SetWindowStyle(wx.DEFAULT_FRAME_STYLE & ~wx.RESIZE_BORDER & ~wx.MAXIMIZE_BOX)  # 크기 변경 불가

#버튼
btn1 = wx.Button(frame, label = '단어 맞추기')
btn2 = wx.Button(frame, label = '뜻 맞추기')
btn3 = wx.Button(frame, label = '종료')

#사이저 셋팅
gbox = wx.BoxSizer(wx.VERTICAL) # 사이저 설정
frame.SetSizer(gbox) # 셋 사이저
gbox.Add(btn1, 1, wx.EXPAND)
gbox.Add(btn2, 1, wx.EXPAND)
gbox.Add(btn3, 1, wx.EXPAND)

def btn1textdialog(str1):
    dIg = wx.TextEntryDialog(message=str1+'<---의 단어는?',parent=None) # 다이얼로그 생성
    try:
        if dIg.ShowModal() == wx.ID_OK:
           vdIg = dIg.GetValue() # 값 추출
    finally:
        dIg.Destroy() # 다이얼로그 파괴
    return vdIg  # 값을 반환
def btn2textdialog(str1):
    dIg = wx.TextEntryDialog(message=str1+'<---의 뜻은?',parent=None) # 다이얼로그 생성
    try:
        if dIg.ShowModal() == wx.ID_OK:
           vdIg = dIg.GetValue() # 값 추출
    finally:
        dIg.Destroy() # 다이얼로그 파괴
    return vdIg  # 값을 반환

# event setting
def onClickbtn1(event) :
    try :
        for k in range(len(mlist)):
            i = int(random.randint(1, 30))  # 난수
            a = btn1textdialog(mlist[i]) # 뜻 --> 단어
            try:
                if mlist[i] == vdic[a]:  # 있을 때
                    wx.MessageBox("정답!", "단어 찾기", wx.OK)
            except:
                wx.MessageBox("땡!! 답-->" + klist[i], "단어 찾기", wx.OK)
    except Exception as ex:
        t1 = str(ex)
        wx.MessageBox("오류발생! " + t1, "단어찾기", wx.OK)
btn1.Bind(wx.EVT_BUTTON, onClickbtn1) # 버튼 1
def onClickbtn2(event) :
    try :
        for k in range(len(klist)):
            i = int(random.randint(1, 30))  # 난수
            a = btn1textdialog(klist[i]) # 뜻 --> 단어
            try:
                if klist[i] == mdic[a]:  # 있을 때
                    wx.MessageBox("정답!", "뜻 찾기", wx.OK)
            except:
                wx.MessageBox("땡!! 답-->" + mlist[i], "뜻 찾기", wx.OK)
    except Exception as ex:
        t1 = str(ex)
        wx.MessageBox("오류발생! " + t1, "뜻 찾기", wx.OK)
btn2.Bind(wx.EVT_BUTTON, onClickbtn2) # 버튼 2

def onClickbtn3(event) :
    try :
        wx.Exit()
    except :
        wx.MessageBox('오류!','종료',wx.OK)
btn3.Bind(wx.EVT_BUTTON,onClickbtn3) # 버튼 3



frame.Show(True)
app.MainLoop()







