//checkrider.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"

void showrider(Heap* rider_heap) {
	for (int i = 1; i <= 10; i++) {
		Sleep(100);
		gotoxy(55, 31+i);
		printf("[%d] 기사님의 대기시간 : %d", rider_heap->heap[i].id, rider_heap->heap[i].avail_time);
	}
	int guess;
	while (1) {
		gotoxy(47, 44);
		printf("가장 빠른 기사님을 호출하시려면 1을 입력하세요!! : ");
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}
}


void checkrider(Owner* sand_owner,Heap* rider_heap) {
	int guess;
	while (1) {
		gotoxy(41, 25);
		printf("배달 가능힌 기사님을 Heap앱을 통해 검색하시려면 1을 입력하세요 : ");
		scanf("%d", &guess);
		if (guess == 1) {
			gotoxy(52, 27);
			printf("검색중........(잠시 기다려주세요~) ");// 랜덤값 슬립 시간!
			break;
		}
	}
	Sleep(1000);
	showrider(rider_heap);

}