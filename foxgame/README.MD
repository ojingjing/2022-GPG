# 😊Smile Game😊

---

## **[Misson]**   
원본코드를 업그레이드 시키기
___
## **[원본코드 사이트]**   
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=papadaks2&logNo=220801495893 

## **[수정항목]**
-점수부분 오류 수정   
-충돌시 배경생,player 모습 변경   
-player 생명 추가    
-게임오버창 추가    
-디자인요소(벽돌 색 , 창디자인 등) 추가     
-메인화면 추가     
-정보창 추가   
-레벨 추가    
-title변경    
-화면위치 중앙정렬    

___
## **1.점수오류수정**  
draw_check01 메소드 안에 아스키코드로 만들어진 판이 있는데   
'-' 아스키코드가 하나 적은거 같아 아스키 코드를 추가해서 정사각형으로 만들어 주었다.    
추가하다 보니 판의 크기가 커져서 for문 범위를 /2로 줄여주었다.  

## **2.커서와 이동문제**  
커서제거문
```
HANDLE consoleHandle =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible =0;
	ConsoleCursor.dwSize =1;
	SetConsoleCursorInfo(consoleHandle , &ConsoleCursor);
```
판을 정사각형으로 만드니 가로로 한칸씩 가는게 아니라 0.5칸씩 가는데 그 이유가 gotoxy에서 문자의 크기는 세로'1' 가로'0.5'
라서 그렇다고한다.

결론=> 이동을 2칸씩 으로 설정해주면된다.

## **3.player잔상삭제**  

printf("  "); 를 쓰면 지워준다고 한다.    
판의 오른쪽의 잔상을 지워야하기 때문에 y축을 i로 주어서 지워주었다.
```
void clear_text(void)
{
   int i;
   for(i=1; i<X-1; i++){
      gotoxy(X+1, i);
      printf("  ");
   }
}
```
---
## **[업그레이드]**    
  
어떻게 업그레이드를 시킬까 고민하다 처음에는 '팩맨'을 하면 되겠다고 생각했지만     
적 생성,벽 생성,벽충돌, 적 충돌,..등 난이도가 너무 어려워져서 하다가 포기했다.    

그다음 게임으로 똥피하기게임을 구현하려고 했다 하지만 팩맨구현시도 하려다가 실패해서 시간이 촉박+ 배열을 써야한다 ..?라는 등    
복잡해보여서  포기하고 간단하게 구현하기로 하였다.    

### **PICK UP GAME**   
제한시간 동안 랜덤으로 생성되는 별을 많이 먹어 점수를 쌓는게임.  

---
## **1.메인 화면 구성**     


> 화살표를 제한된 범위내에서 움직이게 하여야했는데   
case로 x,y의 범위를 지정해주었다.
그리고 마지막에 return y-25를 해주었는데 return 값에 따라 창을 뜨게 하기 위해서 이다.  
예를 들어 게임시작은 y=25이고 return 시 0값을 받으므로 0값에 게임화면을 띄어주게 하면된다.  
```
int menuDraw(){ //메뉴 
	int x =47 , y =25; //시작점 
    char key;
    gotoxy(x-2,y); 
	printf("> 게임시작");
	gotoxy(x,y+1); 
	printf("게임정보"); 
	gotoxy(x,y+2); 
	printf("  종료 ");
	while(1){
		key=getch();
	switch(key)	{
		
	case 72: {
		if(y>25){   //y는 25-27까지만 이동 
			gotoxy(x-2,y); 
			printf(" ");  //원래 위치 지우고 
			gotoxy(x-2,--y);
			printf(">"); 
		} 
		break;
	}
	case 80: {
		if(y<27){  
			gotoxy(x-2,y); 
			printf(" ");  //원래 위치 지우고 
			gotoxy(x-2,++y);
			printf(">"); 
		} 
		break;
	case 32:{
		
		return y-25;
	}
}
	
	if (key==27)
		exit(0);
	else if (key>=72)
		move_arrow_key(key, &x, &y, 20, 20); 
   }
	
}
}
```

## **2.사용자 정보 받기**  

화면을 삭제 해준다  
```
system("cls");
``` 
scanf 를 이용해 사용자 정보를 받아왔다.  

사용자 정보창을 color를 넣어 꾸며주었는데 색을 넣는코드다.  
```
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),색의 값);
```

**3.게임카운트 애니메이션**  
애니메이션을 넣는 방법은 생각보다 쉬웠다.  
printf 로 표현하고 싶은것을 만들어준 다음  
```
system("cls");
Sleep(500);

```
을 이용해서 창을 띄우는 속도를 조절해 주었다.  
500 이 0.5초 1000이 1초라고 한다.  

## **4.item 랜덤생성**   

```
void random(){
 
 
     random1 =rand()%11;  //Y
     random2 =rand()%5*2+1 ; //X
    
}
```

rand() 함수를 써서 나타내었다  
rand()%n 이 1-n 까지     
rand()%n*2+1 n까지의 홀수 부분을 나타낸다고 한다.

```
	key=getch();
	if (key==27){
		gotoxy(20,20);
		exit(0);
	}
	else if (key>=72){
		move_arrow_key(key, &x, &y, X, Y);
	
		if (random2==x && random1 ==y){
			random(); 
			gotoxy(random2,random1);
			printf("★");
			cnt+=10;
		}
		clear_text(); 
			}
		
	}while(1);
```
 
중요한 부분만 가져와 보았는데 key=getch(); 가 키보드의 입력이 들어왔을때    
ESC=27 키를 누르면 종료    
방향키는 움직여준다 라는 뜻이다.    
만약 player의 좌표가 item의 좌표와 같다면 한번더 랜덤을 돌리고      
별의 위치를 gotoxy로 옮겨주고 점수를 cnt 해준다는 뜻이다.        


  
랜덤으로 생성하고 실행하다보니 문제점이 보였는데 그것이 게임을 처음 시작할때의 item위치가      
항상 동일하다는 것이였다. 이문제를 해결해주기 위하여 srand()를 써서 해결해 주었다.     
```
srand(time(NULL));
```

---
## **[개선할점]**


 ---
**[netlify]**  
https://sage-dasik-bf1c7c.netlify.app/
