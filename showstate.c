//checkrider.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"


void ShowStateReady(Owner* sand_owner, OwnerStock* stock) {

	int guess = 0;
	gotoxy(52, 23);
	printf("[[ �� ���� :: %d // ���� ü�� :: %d ]]", sand_owner->total_income, sand_owner->blood);
	gotoxy(40, 25);
	printf("��� �� : %d // ��ä : %d // ��� : %d // �ҽ� : %d // ���� : %d", stock->stock[0], stock->stock[1], stock->stock[2], stock->stock[3], stock->stock[4]);


	if (sand_owner->blood <= 0) {
		Sleep(2000);
		gotoxy(50, 27);
		printf("�̷�;; ü���� ���� �����Ͽ� ���������!!!!!!");
		Sleep(1000);
		gotoxy(50, 29);
		printf("Game over");
		Sleep(1000);
		gotoxy(50, 31);
		printf("�����Ͻ÷��� X�� ������ �����ּ���~~ : ");
		while (1) {
			scanf("%d", &guess);
			gotoxy(50, 33);
			printf("XŰ�� ������ �����ּ���! ���Ƿ��� �ɾ���ҽ��ϴ�");
		}

	}
	Sleep(1000);
	gotoxy(45, 27);
	printf("�ֹ� ���� ������ġ�� ���� ��������ϴ�.");
	while (1) {
		gotoxy(45, 29);
		printf("������ġ�� �Ǹ��Ͻ÷��� 1�� �Է��Ͽ� �Ǹ� ���������� �̵��ϼ���~ : ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}

}

void ShowStateSell(Owner* sand_owner, OwnerStock* stock) {

	int guess = 0;
	gotoxy(52, 23);
	printf("[[ �� ���� :: %d // ���� ü�� :: %d ]]", sand_owner->total_income, sand_owner->blood);
	gotoxy(40, 25);
	printf("��� �� : %d // ��ä : %d // ��� : %d // �ҽ� : %d // ���� : %d", stock->stock[0], stock->stock[1], stock->stock[2], stock->stock[3], stock->stock[4]);

	if (sand_owner->blood <= 0) {
		Sleep(1000);
		gotoxy(50, 27);
		printf("�̷�;; ü���� ���� �����Ͽ� ���������!!!!!!");
		Sleep(1000);
		gotoxy(50, 29);
		printf("Game over");
		Sleep(1000);
		gotoxy(50, 31);
		printf("�����Ͻ÷��� X�� ������ �����ּ���~~ : ");
		while (1) {
			scanf("%d", &guess);
			gotoxy(50, 33);
			printf("XŰ�� ������ �����ּ���! ���Ƿ��� �ɾ���ҽ��ϴ�");
		}

	}
	Sleep(1000);
	gotoxy(45, 27);
	printf("�ֹ� ���� ������ġ�� ���� ��޿Ϸ� �߽��ϴ�.");
	while (1) {
		gotoxy(45, 29);
		printf("������ġ ��� ä��÷��� 1�� �Է��Ͽ� ��ǰ ���������� �̵��ϼ���~ : ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}

}

void ShowStateStock(Owner* sand_owner, OwnerStock* stock) {

	int guess = 0;
	gotoxy(52, 23);
	printf("[[ �� ���� :: %d // ���� ü�� :: %d ]]", sand_owner->total_income, sand_owner->blood);
	gotoxy(40, 25);
	printf("��� �� : %d // ��ä : %d // ��� : %d // �ҽ� : %d // ���� : %d", stock->stock[0], stock->stock[1], stock->stock[2], stock->stock[3], stock->stock[4]);

	Sleep(1000);
	gotoxy(45, 27);
	printf("�ൿ���� ��� �Ҹ��Ͽ� ��ǰ�� �Ϸ��Ͽ����ϴ�..");
	while (1) {
		gotoxy(45, 29);
		printf("������ġ�� �����Ͻ÷��� 1�� �Է��Ͽ� ���� ���������� �̵��ϼ���~ : ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}


}