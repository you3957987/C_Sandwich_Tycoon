//main.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#define Max_Sand_Size 5;

int guess = 0;

int main() {
    // ������ â ũ�� ����
    SMALL_RECT windowSize = { 0, 0, 1200, 900 }; // 1440x900 â ũ�⸦ ���Ѵٸ� -1�� ���� �ʴ� ���� �߿��մϴ�.
    // â �ڵ� ��������
    HWND hwnd = GetConsoleWindow();
    // â ũ�� ����
    MoveWindow(hwnd, windowSize.Left, windowSize.Top, windowSize.Right - windowSize.Left + 1, windowSize.Bottom - windowSize.Top + 1, TRUE);
    cls();
     do{
        guess = StartMenu(guess);
     } while (guess != 1);
     cls();
     start_stage();


    return 0;
}