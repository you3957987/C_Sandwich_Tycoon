//makesandwich.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"

void showlocal(LocalNode* p) {
	gotoxy(55, 36);
	printf("            [[%d]]", p->localname);
}


void makesandwich(Owner* sand_owner, int* stagecheck) {

	Customer* cus = (Customer*)malloc(sizeof(Customer));
	memset(cus, 0, sizeof(Customer));
	cus->sandwich = (Sandwich*)malloc(sizeof(Sandwich));
	init_product(cus->sandwich);
	int guessnum = 0;
	int guess = 0;
	srand(time(NULL));// �ʿ� ������ Ȯ��

	for (int i = 0; i < 5; i++) {
		gotoxy(55, 30+i);
		printf("[%d��]� ��Ḧ �������? :",i+1);
		scanf("%d", &guess);
		push_stack(guess, cus->sandwich);
	}
	
	//insertnode(sand_owner->localNode, 2);

	LocalNode *p;
	p = sand_owner->localNode;
	int local = 1; // ��� ������ �ٽ� ���� �����ϰ�!!
	while (1) {
		showlocal(p);
		gotoxy(45, 38);
		printf("��� ������ �����ϼ���( ���� : 1 / �ٸ� �������� : 2) : ");
		scanf("%d", &guess);
		if (guess == 1) {

			if (p->localname == (*stagecheck)) {

				cus->local = p->localname;
				gotoxy(55, 40);
				printf("                                                                       ");
				gotoxy(55, 40);
				printf("VIP �մ��ΰ���?(O : 1 / X : 0) : ");
				scanf("%d", &guess);
				cus->vip = guess;
				if (cus->vip == 1) {
					p->cuscount += 1;
					p->cusQ->vipnum += 1;
					add_front(p->cusQ, cus);
					//gotoxy(55, 41);
					//printf("%d", sand_owner->cusNode->cusQ->cus[0]->sandwich->sandwich_num[0]);
					break;
				}
				else {
					p->cuscount += 1;
					add_rear(p->cusQ, cus);
					//gotoxy(55, 41);
					//printf("%d", sand_owner->cusNode->cusQ->cus[1]->sandwich->sandwich_num[0]);
					break;
				}
			}
			else {
				gotoxy(45, 40);
				printf("������ �� �� �����ϼ̾��!!! �����ϼ���! (ü���� �����߽��ϴ�! <%d> -> <%d>) ", sand_owner->blood, (sand_owner->blood) - 1);
				sand_owner->blood--;
			}

		
		}
		else if (guess == 2) {
			p = p->link;
		}

	}
	
}