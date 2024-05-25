//makesandwich.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // ����Ű�� ���
#include "Stage.h"
#include "Sandwich.h"

void insertlast(ListNode* head, int name, int count) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->name = name;
	temp->count = count;
	temp->link = NULL;
	ListNode* p;
	p = head;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = temp;
}
ListNode* deletefirst(ListNode* head) {

	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

void dinsert(DlistNode* local, int waittime, int which) {
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
	newnode->localnum = which;
	newnode->waittime = waittime;
	newnode->stocklist = (ListNode*)malloc(sizeof(ListNode));
	newnode->stocklist->name = (rand() % 5) + 1;// 1~ 5
	Sleep(200);
	newnode->stocklist->count = (rand() % 3) + 3; // 3~5
	Sleep(200);
	newnode->stocklist->link = NULL;
	int random;
	random = (rand() % 3) + 1; // 1~3
	for (int i = 0; i < random; i++) {
		insertlast(newnode->stocklist, (rand() % 5) + 1, (rand() % 3) + 3 );
		Sleep(100);
	}
	DlistNode* p = local;
	 // ? 2 3 ? ?      ? ? 3 ? ?
	if (p->localnum < which) {
		while (p->localnum < which) {
			if (p->alink->localnum > which || p->alink->localnum < p->localnum || p->alink ->localnum == p->localnum) {
				break;
			}
			else {
				p = p->alink;
			}
		}
	}
	else if (p->localnum > which) {
		while (p->localnum > which) {
			if (p->blink->localnum < which || p->blink->localnum > p->localnum || p->blink->localnum == p->localnum) {
				break;
			}
			else {
				p = p->blink;
			}
		}
		p = p->blink;
	}
	newnode->blink = p;
	newnode->alink = p->alink;
	p->alink->blink = newnode;
	p->alink = newnode;
}

DlistNode* ddelete(DlistNode* local, int which) {
	DlistNode* p = local;
	if (p->localnum == which) {
		DlistNode* removed;
		removed = local;
		local = local->alink;
		removed->blink->alink = removed->alink;
		removed->alink->blink = removed->blink;
		free(removed);
	}
	else {
		while (p->localnum != which) {
			p = p->alink;
		}
		DlistNode* removed;
		removed = p;
		removed->blink->alink = removed->alink;
		removed->alink->blink = removed->blink;
		free(removed);
	}
	return local;
}

void DlistNode_init(DlistNode* local, int which[]) {

	local->localnum = (rand() % 5) + 1; // 1~5
	which[local->localnum] = 1;
	local->waittime = (rand() % 5) + 4; // 4~8
	local->stocklist = (ListNode*)malloc(sizeof(ListNode));
	local->stocklist->name = (rand() % 5) + 1;// 1~ 5
	Sleep(100);
	local->stocklist->count = (rand() % 3) + 3; // 3~5
	Sleep(100);
	local->stocklist->link = NULL;
	int random;
	random = (rand() % 3) + 1; // 1~3
	for (int i = 0; i < 3; i++) {
		insertlast(local->stocklist, (rand() % 5) + 1, (rand() % 3) + 3);
	}
	local->alink = local;
	local->blink = local;
}

stockminigame(OwnerStock* stock) {// int actiontime

	int time = 0;
	int which[6] = { 0,0,0,0,0,0 }; // ��ǰ ��ġ �����ϸ� 1 0�� �ε��� ���� 1~5�� �ε����� ���
	int whichavailtime[6] = { 0,0,0,0,0,0 }; // ��ǰ�� ��� �ð� ;;
	DlistNode* local; 
	local = (DlistNode*)malloc(sizeof(DlistNode));
	DlistNode_init(local, which);

	int whichcount = 1;
	int random;
	int actiontime = 20; // ���־ߵ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	DlistNode* p;
	DlistNode* p1;
	ListNode* pp;
	int toxy; // ��ǥ ����
	int stockcount;
	int whichtemp;
	while (whichcount != 3) {
		random = (rand() % 5) + 1; // 1~5���� ����
		while (which[random] == 1) {
			random = (rand() % 5) + 1; // 1~5���� ����
		}
		dinsert(local, (rand() % 5) + 4, random);//int waittime, int which
		which[random] = 1;
		whichcount++;
	}
	for (int i = 1; i <= 5; i++) {
		if (which[i] != 1) {
			whichavailtime[i] = (rand() % 3) + 2; // 2~4 
			Sleep(100);
		}
	}

	while (time < actiontime) { // �̴ϰ��� ����
		p = local; // �λ� ����� ����
		
		for (int i = 0; i < 23; i++) {
			gotoxy(40, 27 + i);
			printf("                                                                                                                 ");
		}

		gotoxy(20, 28);
		printf("<<���>>");
		for (int i = 0; i < 5; i++) {
			gotoxy(20, 28 + ((i+1) * 3)); 
			printf("[%d] :: %2d", i+1,stock->stock[i]);
		}
		gotoxy(16, 48);
		printf("���� �ൿ �ð� : %2d", actiontime - time);

		for (int i = 1; i <= 5; i++) {
			gotoxy(45, 22 + (i * 5)); // 27 32 37 42 47
			if (local->localnum == i) {
				printf("@");
			}
			else {
				printf(" ");
			}
		}
	
		for (int i = 1; i <= whichcount; i++) {
			if (p->localnum == 1) {
				gotoxy(65, 27);
				printf("[1]");
				gotoxy(61, 29);
				printf("���ð� : %d", p->waittime--);
				pp = p->stocklist;
				toxy = 0;
				while (pp) {
					gotoxy(75+toxy,27);
					printf("%d �: %d", pp->name, pp->count);
					toxy += 15;
					pp = pp->link;
				}
			}
			else if (p->localnum == 2) {
				gotoxy(65, 32);
				printf("[2]");
				gotoxy(61, 34);
				printf("���ð� : %d", p->waittime--);
				pp = p->stocklist;
				toxy = 0;
				while (pp) {
					gotoxy(75 + toxy, 32);
					printf("%d �: %d", pp->name, pp->count);
					toxy += 15;
					pp = pp->link;
				}
			}
			else if (p->localnum == 3) {
				gotoxy(65, 37);
				printf("[3]");
				gotoxy(61, 39);
				printf("���ð� : %d", p->waittime--);
				pp = p->stocklist;
				toxy = 0;
				while (pp) {
					gotoxy(75 + toxy, 37);
					printf("%d �: %d", pp->name, pp->count);
					toxy += 15;
					pp = pp->link;
				}
			}
			else if (p->localnum == 4) {
				gotoxy(65,42);
				printf("[4]");
				gotoxy(61, 44);
				printf("���ð� : %d", p->waittime--);
				pp = p->stocklist;
				toxy = 0;
				while (pp) {
					gotoxy(75 + toxy, 42);
					printf("%d �: %d", pp->name, pp->count);
					toxy += 15;
					pp = pp->link;
				}
			}
			else if (p->localnum == 5) {
				gotoxy(65, 47);
				printf("[5]");
				gotoxy(61, 49);
				printf("���ð� : %d", p->waittime--);
				pp = p->stocklist;
				toxy = 0;
				while (pp) {
					gotoxy(75 + toxy, 47);
					printf("%d �: %d", pp->name, pp->count);
					toxy += 15;
					pp = pp->link;
				}
			}
			p = p->blink;
		}
		for (int i = 1; i <= 5; i++) { // 61 29
			gotoxy(61, 29 + (i-1) * 5);
			if (whichavailtime[i] != 0) {
				printf("�����ð� : %d", whichavailtime[i]--);
			}
		}

		for (int i = 1; i <= 5; i++) {
			if (which[i] == 0 && whichavailtime[i] == 0) {
				dinsert(local, (rand() % 5) + 4, i);//int waittime, int which
				which[i] = 1;
				whichavailtime[i] = 0;
				whichcount++;
			}
		}
		gotoxy(30, 45);

		while (1) {
			int c = _getch();      // ����Ű �Է½� 224 00�� ������ �Ǳ⿡ �տ� �ִ� �� 224�� ����
			c = _getch();  // ���� �Է°��� �Ǻ��Ͽ� �����¿� ���
			if (c == 72) { // ��

				local = local->blink;
				break;
			}
			else if (c == 80) { // �Ʒ�

				local = local->alink;
				break;
			}
			else if (c == 77) { // ������
				stockcount = local->stocklist->count;
				stock->stock[local->stocklist->name-1] += stockcount;
				local-> stocklist = deletefirst(local->stocklist);
				if (local->stocklist == NULL) {
					which[local->localnum] = 0;
					whichavailtime[local->localnum] = (rand()%3) +2;
					Sleep(100);
					local = ddelete(local,local->localnum);
					whichcount--;
				}
				break;
			}
			else if (c == 75) { // ����
				gotoxy(80, 45);
				printf("4");
				break;
			}
			
		}
		p1 = local;
		while (local->waittime == -1) {
			local = local->blink;
		}
		for (int i = 1; i <= 5; i++) {
			
			if (p1->localnum == 1) {
				if (p1->waittime == -1) {
					which[p1->localnum] = 0;
					whichavailtime[p1->localnum] = (rand() % 3) + 2;
					p1 = ddelete(p1, p1->localnum);
					whichcount--;
				}
			}
			else if (p1->localnum == 2) {
				if (p1->waittime == -1) {
					which[p1->localnum] = 0;
					whichavailtime[p1->localnum] = (rand() % 3) + 2;
					p1 = ddelete(p1, p1->localnum);
					whichcount--;
				}
			}
			else if (p1->localnum == 3) {
				if (p1->waittime == -1) {
					which[p1->localnum] = 0;
					whichavailtime[p1->localnum] = (rand() % 3) + 2;
					p1 = ddelete(p1, p1->localnum);
					whichcount--;
				}
			}
			else if (p1->localnum == 4) {
				if (p1->waittime == -1) {
					which[p1->localnum] = 0;
					whichavailtime[p1->localnum] = (rand() % 3) + 2;
					p1 = ddelete(p1, p1->localnum);
					whichcount--;
				}
			}
			else if (p1->localnum == 5) {
				if (p1->waittime == -1) {
					which[p1->localnum] = 0;
					whichavailtime[p1->localnum] = (rand() % 3) + 2;
					p1 = ddelete(p1, p1->localnum);
					whichcount--;
				}
			}
			p1 = p1->blink;
		}
		time++;
	}

}
