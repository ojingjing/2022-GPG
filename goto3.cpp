#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void)
{
	
	 int i,j;
for(int i=1;i<=9;i++)
{
	for(int j=1;j<=9;j++){
gotoxy(10*j,10);
printf("%d*%d=%2d",j,i,j*i);
}}
printf("\n");
return 0;
}
//3�� ���
void gotoxy(int x, int y)
{
COORD Pos = {x - 1, y - 1};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
//Ŀ�� ��ġ ����
