'''
awwesome fizzbuzz  
# Python code
'''

from logging import getLogger, config
import time
import json
from numpy import arange

with open('log_config.json', 'r') as f:
    log_conf = json.load(f)
config.dictConfig(log_conf)
logger = getLogger(__name__)

def do_fizzbuzz(turns: int, type: str="bizz"):
    if type == "bizz":
        first_w = "Bizz"
    else:
        first_w = "Fizz"
    
    for i in arange(1, turns+1):
        kwd = ""
        if i % 3 == 0:
            kwd = first_w
        if i % 5 == 0:
            kwd += "Buzz"
        if kwd == "":
            kwd = f'{i}'
        print(kwd)
        
def play_fizzbuzz(turns: int, type:str="fizz"):
    
    if type == "bizz":
        first_w = "Bizz"
    else:
        first_w = "Fizz"
    
    if enter_pressed():
        start = time.time()
        for i in arange(1, turns+1):
            kwd = ""
            ans = ""
            
            if i % 2 == 0:
                ans = input()
            
            if i % 3 == 0:
                kwd = first_w
                
            if i % 5 == 0:
                kwd += "Buzz"
            if kwd == "":
                kwd = f'{i}'
                
            if i % 2 != 0:
                print(kwd)
            if i % 2 ==0 and (ans != kwd and str.capitalize(ans) != kwd):
                logger.warning("You missed!")
                return 0
        end = time.time()
        logger.info("You win!")
        logger.info(f'Clear time[s]: {end - start}, turns: {turns}')
        return 0
    
'''
## これは書いちゃ駄目な方法  

- do_fizzbuzz の kwd がそのまま正解として使える。
- わざわざ回答チェック用のアルゴリズムを書く必要はない
'''
def check_ans(i, ans, first_w):
    if i % 3 == 0 and i % 5 != 0 and ans == first_w:
        logger.info('o')
    elif (i % 3 != 0 and i % 5 == 0) and (ans == "buzz" or ans == "Buzz"):
        logger.info('o')
    elif (i % 3 == 0 and i % 5 == 0) and (ans == f'{first_w} buzz' or ans == f'{first_w} Buzz'):
        logger.info('o')
    elif ans == f'{i}':
        logger.info('o')
    else:
        logger.info('x')
        
def enter_pressed():
    key_get = input("Press Enter to start!")
    
    if type(key_get) is str:
        logger.info('Enter')
        return True
    else:
        return False
    
if __name__ =="__main__":
    # do_fizzbuzz(16, type="fizz")
    play_fizzbuzz(12, type="fizz")