//window.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>

void cls() {
    system("cls");
}

void gotoxy(int x, int y) {
    COORD coord; // COORD ����ü�� ����Ͽ� ��ǥ�� ��Ÿ���ϴ�.
    coord.X = x; // x ��ǥ ����
    coord.Y = y; // y ��ǥ ����
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Ŀ���� ������ ��ǥ�� �̵���ŵ�ϴ�.
}