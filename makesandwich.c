//makesandwich.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"

void showlocal(LocalNode* p) {
	gotoxy(55, 39);
	printf("            [[%d]]", p->localname);
}

const char* numberToStringmake(int num) {
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

const char* numberToStringmakep(int num) {
	switch (num) {
	case 1:
		return "빵";
	case 2:
		return "야채";
	case 3:
		return "재료";
	case 4:
		return "소스";
	case 5:
		return "음료";
	default:
		return "Invalid number";
	}
}

void makesandwich(Owner* sand_owner, int* stagecheck, OwnerStock* stock) {

	Customer* cus = (Customer*)malloc(sizeof(Customer));
	memset(cus, 0, sizeof(Customer));
	cus->sandwich = (Sandwich*)malloc(sizeof(Sandwich));
	init_product(cus->sandwich);
	int guessnum = 0;
	int guess = 0;
	srand(time(NULL));// 필요 없는지 확인
	gotoxy(20, 28);
	printf("<<재고>>");
	for (int i = 0; i < 5; i++) {
		gotoxy(20, 28 + ((i + 1) * 3));
		printf("[%d] :: %2d", i + 1, stock->stock[i]);
	}

	for (int i = 0; i < 5; i++) {
		gotoxy(55, 31);
		printf("                                       ");
		gotoxy(55, 31);
		printf("[%s]어떤 재료를 넣을까요?", numberToStringmakep(i+1));
		gotoxy(55, 33);
		printf("                                                             ");
		gotoxy(17, 46);
		printf("총 수익 : %d  ", sand_owner->total_income);
		gotoxy(17, 48);
		printf("남은 체력 : %d  ", sand_owner->blood);
		gotoxy(55, 33);
		printf("<%s> = %d // <%s> = %d // <%s> = %d :: ", numberToStringmake(3*i+1), 3*i+1, numberToStringmake(3*i+2), 3*i+2, numberToStringmake(3*i+3), 3*i+3);
		scanf("%d", &guess);
		if (stock->stock[i] == 0) {
			gotoxy(55, 35);
			printf("재고가 없습니다!! 총 수익 50 감소!");
			sand_owner->total_income -= 50;
			Sleep(1000);
			gotoxy(55, 35);
			printf("                                                ");
		}
		else {
			stock->stock[i] -= 1;
		}
		gotoxy(20, 28);
		printf("<<재고>>");
		for (int i = 0; i < 5; i++) {
			gotoxy(20, 28 + ((i + 1) * 3));
			printf("[%d] :: %2d", i + 1, stock->stock[i]);
		}
		push_stack(guess, cus->sandwich);
	}
	
	//insertnode(sand_owner->localNode, 2);
	gotoxy(55, 31);
	printf("                                             ");
	gotoxy(55, 33);
	printf("                                                                     ");
	LocalNode *p;
	p = sand_owner->localNode;
	int local = 1; // 배달 지역은 다시 선택 가능하게!!
	while (1) {
		showlocal(p);
		gotoxy(45, 41);
		printf("배달 지역을 선택하세요( 선택 : 1 / 다른 지역으로 : 2) : ");
		scanf("%d", &guess);
		if (guess == 1) {

			if (p->localname == (*stagecheck)) {

				cus->local = p->localname;
				gotoxy(45, 43);
				printf("                                                                                     ");
				gotoxy(55, 43);
				printf("VIP 손님인가요?(O : 1 / X : 0) : ");
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
				gotoxy(45, 43);
				printf("지역을 잘 못 선택하셨어요!!! 주의하세요! (체력이 감소했습니다! <%d> -> <%d>) ", sand_owner->blood, (sand_owner->blood) - 1);
				sand_owner->blood--;
			}

		
		}
		else if (guess == 2) {
			p = p->link;
		}

	}
	
}