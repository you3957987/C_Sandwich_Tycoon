//getordersandwich.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
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
		return "빵1";
	case 2:
		return "빵2";
	case 3:
		return "빵3";
	case 4:
		return "야채1";
	case 5:
		return "야채2";
	case 6:
		return "야채3";
	case 7:
		return "재료1";
	case 8:
		return "재료2";
	case 9:
		return "재료3";
	case 10:
		return "소스1";
	case 11:
		return "소스2";
	case 12:
		return "소스3";
	case 13:
		return "음료1";
	case 14:
		return "음료2";
	case 15:
		return "음료3";
	default:
		return "Invalid number";
	}
}

void getordersandwich(Owner* sand_owner,int localnum, int cusnum, int *stagecheck, OwnerStock* stock) {

	Customer* cus = (Customer*)malloc(sizeof(Customer));
	memset(cus, 0, sizeof(Customer));
	cus->sandwich = (Sandwich*)malloc(sizeof(Sandwich));
	init_product(cus->sandwich);
	int guessnum = 0;
	srand(time(NULL));
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

	gotoxy(48, 28);
	printf("[[ %d번째 손님의 주문을 확인하세요!!!!!!! ]] ",cusnum);

	for (int i = 0; i < 5; i++) {
		int random = (rand() % 3 + (1 + (3 * i)));
		push_stack(random, cus->sandwich);
		gotoxy(55, 30 + 2*i);
		if (i == 0) printf("빵 종류는 : %s\n", numberToStringgetorder(random));
		else if (i == 1) printf("야채 종류는 : %s\n", numberToStringgetorder(random));
		else if (i == 2) printf("재료 종류는 : %s\n", numberToStringgetorder(random));
		else if (i == 3) printf("소스 종류는 : %s\n", numberToStringgetorder(random));
		else if (i == 4) printf("음료 종류는 : %s\n", numberToStringgetorder(random));
		Sleep(500);
	}
	cus->vip = rand() % 2;
	if (cus->vip == 1) {
		gotoxy(55, 40);
		printf("VIP 손님!!\n");
	}
	else if( cus->vip == 0) {
		gotoxy(55, 40);
		printf("일반 손님!!\n");
	}
	Sleep(500);
	cus->local = (rand() % localnum) + 1;
	gotoxy(55, 42);
	printf("배달 지역 : %d\n", cus->local);
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
		printf("샌드위치 제작으로 넘어기시려면 1을 입력하세요~ : ");
		scanf("%d", &guessnum);
		if (guessnum == 1) {
			break;
		}
	}

}