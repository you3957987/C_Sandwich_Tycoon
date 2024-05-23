//makesandwich.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"

ListNode* insertlast(ListNode* head, int name, int count) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->name = name;
	temp->count = count;
	ListNode* p;
	p = head;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = temp;
	return head;
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
	Sleep(500);
	newnode->stocklist->count = (rand() % 1) + 2; // 2~3
	Sleep(500);
	newnode->stocklist->link = NULL;
	int random;
	random = (rand() % 3) + 1; // 1~3
	for (int i = 0; i < random; i++) {
		insertlast(newnode->stocklist, (rand() % 5) + 1, (rand() % 1) + 2 );
		Sleep(500);
	}
	DlistNode* p = local;
	 // ? 2 3 ? ?      ? ? 3 4 5

	if (p->localnum < which) {
		while (p->localnum < which) {
			if (p->alink->localnum > which || p->alink->localnum < p->localnum) {
				break;
			}
			else {
				p = p->alink;
			}
		}
	}
	else if (p->localnum > which) {
		while (p->localnum > which) {
			if (p->blink->localnum < which || p->blink->localnum > p->localnum) {
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
	Sleep(500);
	local->stocklist->count = (rand() % 1) + 2; // 2~3
	Sleep(500);
	local->stocklist->link = NULL;
	int random;
	random = (rand() % 3) + 1; // 1~3
	for (int i = 0; i < random; i++) {
		insertlast(local->stocklist, (rand() % 5) + 1, (rand() % 1) + 2);
		Sleep(500);
	}

}

stockminigame(OwnerStock* stock,int actiontime) {
	int time = 0;
	int which[5] = { 0,0,0,0,0 }; // 납품 위치
	DlistNode* local = (DlistNode*)malloc(sizeof(DlistNode));
	DlistNode_init(local, which);
	
	while (time < actiontime) {

	}

}
