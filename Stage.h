//stage.h
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>

typedef struct Stage {
	char title[100];
	struct Stage* left, * right;
	int cusnum;// ���������� �մ� ��
	int localnum; // ���������� ������
	int actiontime; // ��� �̴ϰ��� �ൿ��
}Stage; // Ʈ��

typedef struct stage_stack {
	Stage* stack[20];
	int top;
}Stage_Stack; // Ʈ���� �������� ����