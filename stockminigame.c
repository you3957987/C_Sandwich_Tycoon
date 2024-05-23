//makesandwich.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
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

void dinsert(DlistNode* local, int waittime, int localnum, int which) {
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
	newnode->localnum = localnum;
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
	local->waittime = (rand() % 3) + 4; // 4~6
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
	int which[5] = { 0,0,0,0,0 }; // 납품 위치 존재하면 1
	DlistNode* local; 
	local = (DlistNode*)malloc(sizeof(DlistNode));
	DlistNode_init(local, which);
	int whichcount = 1;
	int random;
	while (whichcount != 3) {
		random = (rand() % 5) + 1; // 1~5까지 지역
		while (which[random] == 1) {
			random = (rand() % 5) + 1; // 1~5까지 지역
		}
		dinsert(local, (rand() % 3) + 4, (rand() % 5) + 1, random);//int waittime, int localnum, int which
		which[random] = 1;
		whichcount++;
		gotoxy(45, 28);
	}
	int actiontime = 10;

	while (time < actiontime) { // 미니게임 시작

		for (int i = 1; i <= 5; i++) {
			gotoxy(45, 22 + (i * 5));
			if (local->localnum == i) {
				printf("@");
			}
			else {
				printf("!");
			}
		}

		// 이제 UI 출력이랑 ddelete만 구현하면 완성임!!
		Sleep(5000);
	}

}
