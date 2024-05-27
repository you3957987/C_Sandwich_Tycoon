#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"


void checksandwich(Owner* sand_owner, int cuscount, int localnum,OwnerStock* stock) {// 남은 손님수 // 지역수
	LocalNode* p;
	p = sand_owner->localNode;
	int guess;
	int print;
	gotoxy(58, 27);
	printf("남은 손님 수 : %d ",cuscount );
	Sleep(1000);

	for (int i = 0; i < localnum; i++) {
		gotoxy(55, 29+(i*4));
		printf("            [[%d]]", p->localname);
		gotoxy(55, 31+(i*4));
		printf("             %d명", p->cuscount);
		Sleep(1000);
		print = 31 + (i * 4);
		p = p->link;
	}
	gotoxy(17, 46);
	printf("총 수익 : %d  ", sand_owner->total_income);
	gotoxy(17, 48);
	printf("남은 체력 : %d  ", sand_owner->blood);
	gotoxy(20, 28);
	printf("<<재고>>");
	for (int i = 0; i < 5; i++) {
		gotoxy(20, 28 + ((i + 1) * 3));
		printf("[%d] :: %2d", i + 1, stock->stock[i]);
	}


	while (1) {
		gotoxy(50, print+2);
		printf("다음 손님을 맞으려면 1을 입력하세요 ~ : ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}

}