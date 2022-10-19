# PICKUPGAME🎈★

**[Misson]**   
원본코드를 업그레이드 시키기
___
**[원본코드]**   
![image](https://user-images.githubusercontent.com/48702158/196640431-7f355785-ab59-4355-ada6-3ecad5dd8526.png)  

-판의 크기가 정사각형이 아니다.  
-player가 판의 범위를 벗어난다.  
-범위를 벗어난 player의 잔상이 남아있다.  
-이동할때마다 커서의 깜박임이 심하다.  

___
**1.판의 모양,크기 수정**  
draw_check01 메소드 안에 아스키코드로 만들어진 판이 있는데   
'-' 아스키코드가 하나 적은거 같아 아스키 코드를 추가해서 정사각형으로 만들어 주었다.    
추가하다 보니 판의 크기가 커져서 for문 범위를 /2로 줄여주었다.  

**2.커서와 이동문제**  
커서제거문
```
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CON
```




