//window.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>

void cls() {
    system("cls");
}

void gotoxy(int x, int y) {
    COORD coord; // COORD 구조체를 사용하여 좌표를 나타냅니다.
    coord.X = x; // x 좌표 설정
    coord.Y = y; // y 좌표 설정
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // 커서를 지정된 좌표로 이동시킵니다.
}