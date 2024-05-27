//checkrider.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
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
	printf("[[ 총 수익 :: %d // 남은 체력 :: %d ]]", sand_owner->total_income, sand_owner->blood);
	gotoxy(40, 25);
	printf("재고 빵 : %d // 야채 : %d // 재료 : %d // 소스 : %d // 음료 : %d", stock->stock[0], stock->stock[1], stock->stock[2], stock->stock[3], stock->stock[4]);


	if (sand_owner->blood <= 0) {
		Sleep(2000);
		gotoxy(50, 27);
		printf("이런;; 체력을 전부 소진하여 쓰러졌어요!!!!!!");
		Sleep(1000);
		gotoxy(50, 29);
		printf("Game over");
		Sleep(1000);
		gotoxy(50, 31);
		printf("종료하시려면 X를 눌러서 나가주세요~~ : ");
		while (1) {
			scanf("%d", &guess);
			gotoxy(50, 33);
			printf("X키를 눌러서 나가주세요! 무판루프 걸어놓았습니다");
		}

	}
	Sleep(1000);
	gotoxy(45, 27);
	printf("주문 받은 샌드위치를 전부 만들었습니다.");
	while (1) {
		gotoxy(45, 29);
		printf("샌드위치를 판매하시려면 1을 입력하여 판매 스테이지로 이동하세요~ : ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}

}

void ShowStateSell(Owner* sand_owner, OwnerStock* stock) {

	int guess = 0;
	gotoxy(52, 23);
	printf("[[ 총 수익 :: %d // 남은 체력 :: %d ]]", sand_owner->total_income, sand_owner->blood);
	gotoxy(40, 25);
	printf("재고 빵 : %d // 야채 : %d // 재료 : %d // 소스 : %d // 음료 : %d", stock->stock[0], stock->stock[1], stock->stock[2], stock->stock[3], stock->stock[4]);

	if (sand_owner->blood <= 0) {
		Sleep(1000);
		gotoxy(50, 27);
		printf("이런;; 체력을 전부 소진하여 쓰러졌어요!!!!!!");
		Sleep(1000);
		gotoxy(50, 29);
		printf("Game over");
		Sleep(1000);
		gotoxy(50, 31);
		printf("종료하시려면 X를 눌러서 나가주세요~~ : ");
		while (1) {
			scanf("%d", &guess);
			gotoxy(50, 33);
			printf("X키를 눌러서 나가주세요! 무판루프 걸어놓았습니다");
		}

	}
	Sleep(1000);
	gotoxy(45, 27);
	printf("주문 받은 샌드위치를 전부 배달완료 했습니다.");
	while (1) {
		gotoxy(45, 29);
		printf("샌드위치 재고를 채우시려면 1을 입력하여 납품 스테이지로 이동하세요~ : ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}

}

void ShowStateStock(Owner* sand_owner, OwnerStock* stock) {

	int guess = 0;
	gotoxy(52, 23);
	printf("[[ 총 수익 :: %d // 남은 체력 :: %d ]]", sand_owner->total_income, sand_owner->blood);
	gotoxy(40, 25);
	printf("재고 빵 : %d // 야채 : %d // 재료 : %d // 소스 : %d // 음료 : %d", stock->stock[0], stock->stock[1], stock->stock[2], stock->stock[3], stock->stock[4]);

	Sleep(1000);
	gotoxy(45, 27);
	printf("행동력을 모두 소모하여 납품을 완료하였습니다..");
	while (1) {
		gotoxy(45, 29);
		printf("샌드위치를 제작하시려면 1을 입력하여 제작 스테이지로 이동하세요~ : ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}


}