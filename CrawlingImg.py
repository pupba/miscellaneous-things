from typing import KeysView
from selenium.webdriver.common.keys import Keys
from selenium import webdriver
import os
import time
import urllib.request
driver_path = os.getcwd()+'/chromedriver.exe'
driver = webdriver.Chrome(driver_path) #<- driver path
driver.implicitly_wait(3)
driver.get("https://www.google.co.kr/imghp?hl=ko&ogbl") # <- start browser
elem = driver.find_element_by_name("q")
elem.send_keys("plastic trash") # <- search keyword
elem.send_keys(Keys.RETURN)
SCROLL_PAUSE_TIME = 1
# Get scroll height
last_height = driver.execute_script("return document.body.scrollHeight")
while True:
    # Scroll down to bottom
    driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
    # Wait to load page
    time.sleep(SCROLL_PAUSE_TIME)
    # Calculate new scroll height and compare with last scroll height
    new_height = driver.execute_script("return document.body.scrollHeight")
    if new_height == last_height:
        try:
            driver.find_element_by_css_selector(".mye4qd").click()
        except:
            break
    last_height = new_height
images=driver.find_elements_by_css_selector('.rg_i.Q4LuWd') # img tag class

for idx,image in enumerate(images):
    try:
        image.click()
        time.sleep(2)
        # image copy full xpath 
        imgUrl = driver.find_element_by_xpath('/html/body/div[2]/c-wiz/div[3]/div[1]/div/div/div/div[1]/div[1]/span/div[1]/div[1]/div[1]/a[1]/div[1]/img').get_attribute("src")
        opener=urllib.request.build_opener()
        opener.addheaders=[('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1941.0 Safari/537.36')]
        urllib.request.install_opener(opener)
        urllib.request.urlretrieve(imgUrl,f'./imgs/{idx}_c.jpg') # <- img path
    except :
        pass
driver.close()
