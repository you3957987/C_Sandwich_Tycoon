#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"


void checksandwich(Owner* sand_owner, int cuscount, int localnum) {// ���� �մԼ� // ������
	LocalNode* p;
	p = sand_owner->localNode;
	int guess;
	int print;
	gotoxy(58, 27);
	printf("���� �մ� �� : %d ",cuscount );
	Sleep(1000);

	for (int i = 0; i < localnum; i++) {
		gotoxy(55, 29+(i*4));
		printf("            [[%d]]", p->localname);
		gotoxy(55, 31+(i*4));
		printf("             %d��", p->cuscount);
		Sleep(1000);
		print = 31 + (i * 4);
		p = p->link;
	}


	while (1) {
		gotoxy(50, print+2);
		printf("���� �մ��� �������� 1�� �Է��ϼ��� ~ : ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}

}