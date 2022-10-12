
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <malloc.h> //맵크기 동적할당 
#include <time.h>

#define X 21
#define Y 11
#define COLOR_YELLOW 6
#define COLOR_BBLUE 11
#define COLOR_WHITE 15
#define COLOR_PINK 13


 
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
void draw_check01(int c, int r);
void game_control(void);

void init();
void titleDraw();
int menuDraw();
void infoDraw();
int show_count();
void random();
void clear_text();
int game_cnt(int cnt);
void get_player_name(void);
void draw_gamecnt();

char player_name[30] = { 0, };
int random1;
int random2;
int cnt;
int main(void)
{
	init();
	while(1){
	titleDraw();
	int select=menuDraw();
	if(select==0){
		get_player_name();
		show_count();		
		system("cls");
		
		game_control();
		
		
		}
	else if(select==1){
		infoDraw();
	}
	else if(select==2){
		return 0;
	}
		system("cls");
	}
	
	return 0;
} 

void init(){
	system("mode con cols=100 lines=35 |title ★PICK UP☆");
	HANDLE consoleHandle =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible =0;
	ConsoleCursor.dwSize =1;
	SetConsoleCursorInfo(consoleHandle , &ConsoleCursor);

}

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

void gotoxy(int x, int y)  
{
   COORD Pos = {x-1, y-1};    
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void clear_text(void)
{
   int i;
   for(i=1; i<X-1; i++){
      gotoxy(X+1, i);
      printf("  ");
   }
}


void draw_check01(int c, int r)
{   
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[12]; 
    for(i=1;i<12;i++)
   b[i]=0xa0+i;
    printf("%c%c",a, b[3]);
    for(i=0;i<(c-1)/2;i++){
       printf("%c%c", a, b[1]);
       printf("%c%c", a, b[8]);
    }
    printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<(r-1)/2;i++)
    {
         printf("%c%c", a, b[7]);
         for(j=0;j<(c-1)/2;j++){
               printf("%c%c", a, b[1]);
               printf("%c%c", a, b[11]);   
         }
       printf("%c%c", a, b[1]);
         printf("%c%c",a, b[9]);
         printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<(c-1)/2;i++){
       printf("%c%c", a, b[1]);
       printf("%c%c", a, b[10]);   
   }
    printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}

	 

void game_control(void)
{	
    int x=1, y=1;
    char key;
    srand(time(NULL));  
    random();
   	
    do
    {
   	draw_gamecnt();
	gotoxy(1,1);
	draw_check01(X-1, Y*2-2); //판의크기 
	gotoxy(random2,random1);
    printf("★");
    gotoxy(x, y);
	printf("○");
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
}

void random(){
 
 
     random1 =rand()%11;  //Y
     random2 =rand()%5*2+1 ; //X
    
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
    case 72:  //위쪽(상) 방향의 화살표 키 입력
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y좌표의 최소값
		break;
    case 75:  //왼쪽(좌) 방향의 화살표 키 입력
		*x1=*x1-2;          //   좌측방향으로 1씩 감소
		if (*x1<1)	*x1=1; //x좌표의 최소값
		break;
    case 77: // 오른쪽(우) 방향의 화살표 키 입력
		*x1=*x1+2;             //  우측방향으로 1씩 증가
		if (*x1>x_b)  *x1=x_b; //x좌표의 최대값(경계)
		break;
    case 80: // 아래쪽(하) 방향의 화살표 키 입력
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y좌표의 최대값(경계)
		break;
    default:
		return;
	}
}

//그리기 
void get_player_name(void) {
	//사용자의 정보 저장
	system("cls");
	gotoxy(33, 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_YELLOW);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	for (int i = 0; i < 10; i++) {
		gotoxy(33, 13 + i); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_YELLOW);
		printf("┃");
		gotoxy(84, 13 + i); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_YELLOW);
		printf("┃");
	}
	gotoxy(33, 22);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_YELLOW);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
 
	gotoxy(38, 15); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_WHITE);
	printf("▶ 게임 할 때 사용할 이름을 입력해주세요 ◀");
 
	gotoxy(53, 19);
	printf("입력 : ");
	scanf("%s", player_name);
 
}
void draw_gamecnt(){
	gotoxy(25, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_PINK);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_WHITE);
	gotoxy(30, 3);
	printf("▶ Name : %s", player_name);
	gotoxy(30, 5);
	printf("▶ Score : %d점",cnt);
	gotoxy(30, 7);
	printf("▶ ESC : 게임종료 ");
	gotoxy(30, 9);
	printf("▶ 제한시간 : %.2f");
	gotoxy(25, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_PINK);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_WHITE);
}


void titleDraw(){
	
	gotoxy(3,6);
    printf("              ########      ###      #####  ### ###     ###   ###  ########     "); 
	gotoxy(3,7);
	printf("               #     ##      #     #         # #         #     #    #      ##       "); 
	gotoxy(3,8);
	printf("               #######       #     #         ##          #     #    #######     "); 	
	gotoxy(3,9);
	printf("               #             #     #         ##          #     #    #           "); 
	gotoxy(3,10);
	printf("               #             #     #         # #         #     #    #       "); 
	gotoxy(3,11);     
	printf("              ###           ###      #####  ### ###        ###     ###    ");  
 
}
void infoDraw(){
	system("cls");
	printf("\n\n");
	printf("                         [조작법]\n\n");
	printf("                     이동:→,←,↑,↓\n");
	printf("                     선택: spaceBar\n\n\n\n\n\n ");
	printf("                정보:게임프로그래밍 과제\n\n\n\n");
	printf("                 참조:codevkr.tistory.com\n\n\n\n");
	printf("          스페이스바를 누르면 메인화면으로 이동합니다.");
	
	while(1){
	
		if(getch()==32){
			break;
		}
	} 
}

int show_count()
{	system("cls");

	gotoxy(20, 13);
	printf("                         ■■■                          ");
	gotoxy(20, 14);
	printf("                      ■      ■                         ");
	gotoxy(20, 20);
	printf("                               ■                        ");
	gotoxy(20, 16);
	printf("                               ■                        ");
	gotoxy(20, 17);
	printf("                           ■■                          ");
	gotoxy(20, 18);
	printf("                               ■                        ");
	gotoxy(20, 19);
	printf("                     ■        ■                        ");
	gotoxy(20, 20);
	printf("                       ■      ■                        ");
	gotoxy(20, 21);
	printf("                         ■■■                          ");
 
	Sleep(500); //0.5초간 sleep
 
	gotoxy(20, 13);
	printf("                         ■■■                          ");
	gotoxy(20, 14);
	printf("                       ■      ■                        ");
	gotoxy(20, 15);
	printf("                               ■                        ");
	gotoxy(20, 16);
	printf("                              ■                         ");
	gotoxy(20, 17);
	printf("                            ■                           ");
	gotoxy(20, 18);
	printf("                          ■                             ");
	gotoxy(20, 19);
	printf("                        ■                               ");
	gotoxy(20, 20);
	printf("                      ■                                 ");
	gotoxy(20, 21);
	printf("                      ■■■■■■                       ");
 
	Sleep(500); //1초간 sleep
 
	gotoxy(20, 13);
	printf("                           ■                            ");
	gotoxy(20, 14);
	printf("                         ■■                            ");
	gotoxy(20, 15);
	printf("                           ■                            ");
	gotoxy(20, 16);
	printf("                           ■                            ");
	gotoxy(20, 17);
	printf("                           ■                            ");
	gotoxy(20, 18);
	printf("                           ■                            ");
	gotoxy(20, 19);
	printf("                           ■                            ");
	gotoxy(20, 20);
	printf("                           ■                            ");
	gotoxy(20, 21);
	printf("                         ■■■                          ");
 
 
	Sleep(500); //1초간 sleep
 
	gotoxy(20, 13);
	printf("                         ■■■                          ");
	gotoxy(20, 14);
	printf("                       ■      ■                        ");
	gotoxy(20, 15);
	printf("                       ■      ■                        ");
	gotoxy(20, 16);
	printf("                       ■    ■■                        ");
	gotoxy(20, 17);
	printf("                       ■  ■  ■                        ");
	gotoxy(20, 18);
	printf("                       ■■    ■                        ");
	gotoxy(20, 19);
	printf("                       ■      ■                        ");
	gotoxy(20, 20);
	printf("                       ■      ■                        ");
	gotoxy(20, 21);
	printf("                         ■■■                          ");
 
	Sleep(500); //0.5초간 sleep
}
 

