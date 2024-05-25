//getordersandwich.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"

const char* numberToStringgetorder(int num) {
	switch (num) {
	case 1:
		return "��1";
	case 2:
		return "��2";
	case 3:
		return "��3";
	case 4:
		return "��ä1";
	case 5:
		return "��ä2";
	case 6:
		return "��ä3";
	case 7:
		return "���1";
	case 8:
		return "���2";
	case 9:
		return "���3";
	case 10:
		return "�ҽ�1";
	case 11:
		return "�ҽ�2";
	case 12:
		return "�ҽ�3";
	case 13:
		return "����1";
	case 14:
		return "����2";
	case 15:
		return "����3";
	default:
		return "Invalid number";
	}
}

void getordersandwich(Owner* sand_owner,int localnum, int cusnum, int *stagecheck) {

	Customer* cus = (Customer*)malloc(sizeof(Customer));
	memset(cus, 0, sizeof(Customer));
	cus->sandwich = (Sandwich*)malloc(sizeof(Sandwich));
	init_product(cus->sandwich);
	int guessnum = 0;
	srand(time(NULL));
	gotoxy(48, 28);
	printf("[[ %d��° �մ��� �ֹ��� Ȯ���ϼ���!!!!!!! ]] ",cusnum);

	for (int i = 0; i < 5; i++) {
		int random = (rand() % 3 + (1 + (3 * i)));
		push_stack(random, cus->sandwich);
		gotoxy(55, 30 + 2*i);
		if (i == 0) printf("�� ������ : %s\n", numberToStringgetorder(random));
		else if (i == 1) printf("��ä ������ : %s\n", numberToStringgetorder(random));
		else if (i == 2) printf("��� ������ : %s\n", numberToStringgetorder(random));
		else if (i == 3) printf("�ҽ� ������ : %s\n", numberToStringgetorder(random));
		else if (i == 4) printf("���� ������ : %s\n", numberToStringgetorder(random));
		Sleep(500);
	}
	cus->vip = rand() % 2;
	if (cus->vip == 1) {
		gotoxy(55, 40);
		printf("VIP �մ�!!\n");
	}
	else if( cus->vip == 0) {
		gotoxy(55, 40);
		printf("�Ϲ� �մ�!!\n");
	}
	Sleep(500);
	cus->local = (rand() % localnum) + 1;
	gotoxy(55, 42);
	printf("��� ���� : %d\n", cus->local);
	*stagecheck = cus->local;
	LocalNode* p;
	p = sand_owner->cusNode;
	for (int i = 1; i < cus->local; i++) {
		p = p->link;
	}
	if (cus->vip == 1) {
		add_front(p->cusQ, cus);
		p->cuscount += 1;
		p->cusQ->vipnum += 1;
	}
	else{
		add_rear(p->cusQ, cus);
		p->cuscount += 1;
	}

	while (1) {
		gotoxy(46, 44);
		printf("������ġ �������� �Ѿ��÷��� 1�� �Է��ϼ���~ : ");
		scanf("%d", &guessnum);
		if (guessnum == 1) {
			break;
		}
	}

}