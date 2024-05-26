#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // 방향키용 헤더
#include "Stage.h"
#include "Sandwich.h"

void init_hash_table(Rider_chart_list* rider_table[]) {
	for (int i = 0; i < 50; i++) {
		rider_table[i] = NULL;
	}
}

int hash_function(int id) {
	int n = id;
	int sum_of_digits = 0;

	// 각 자리수를 더함
	while (n > 0) {
		sum_of_digits += n % 10; // 1의 자리수를 sum_of_digits에 더함
		n /= 10; // n을 10으로 나누어 다음 자리수로 이동
	}

	// 각 자리수의 합의 1의 자리수를 반환
	int result = sum_of_digits % 10;
	return result;
}

void hash_chain_add(Rider* rider, Rider_chart_list* rider_table[]) {

	int hash_value = hash_function(rider->id);
	Rider_chart_list* ptr;

	Rider_chart_list* before = NULL;
	Rider_chart_list* curr = rider_table[hash_value];
	for (; curr; before = curr, curr = curr->link) {

	}
	ptr = (Rider_chart_list*)malloc(sizeof(Rider_chart_list));
	ptr->rider_chart = *rider;
	ptr->link = NULL;
	if (before) {
		before->link = ptr;
	}
	else {
		rider_table[hash_value] = ptr;
	}

}

int hash_chain_search(int id, Rider_chart_list* rider_table[]) {
	Rider_chart_list* node;
	int hash_value = hash_function(id);
	gotoxy(55, 45);
	printf("%d 지역에 있어요!!", hash_value);

	for (node = rider_table[hash_value]; node; node = node->link) {
		if (node->rider_chart.id == id) {
			return node->rider_chart.id;
		}
	}
	return 1;
}

int isKeyPressed(int key) {
	return GetAsyncKeyState(key) & 0x8000;
}

void findrider(Heap* rider_heap, Rider_chart_list* rider_table[]) {

	int random;
	int n = 0;
	int c;
	int id = 0;
	int answer;
	int guess;
	answer = rider_heap->heap[1].id;
	gotoxy(55, 27);
	printf("가장 빠른 기사님은 [%d] 기사님이에요!", answer);
	while (1) { // 똑바로 입력할 때 까지
		for (int i = 1; i <= 3; i++) {
			while (1) {
				gotoxy(55, 28 + i * 3);
				random = (rand() % 10) + 1;
				printf("ID [%d] : %d   ", i, random); // 공백 추가하여 이전 값 지우기
				Sleep(1000);

				if (_kbhit()) {
					c = _getch();
					if (c == 80) { // 아래 방향키의 ASCII 코드
						id = id * 10 + random;
						break;
					}
				}
			}
		}
		gotoxy(55, 43);
		printf("ID : %d 로 연결할게요~", id);

		if (hash_chain_search(answer, rider_table) == answer) { // id로 바꾸기
			gotoxy(55, 47);
			printf("연결을 성공했어요 !!");
			gotoxy(55, 48);
			printf("확인하셨다면 1을 입력해주세요~ : ");
			scanf("%d", &guess);
			if (guess == 1) {
				break;
			}

		}
		else {
			gotoxy(55, 47);
			printf("연결을 실패했어요. 다시 시도해 보세요!");
			Sleep(2000);
			for (int i = 1; i <= 3; i++) {
				gotoxy(55, 28 + i * 3);
				printf("                                          ");
			}
			gotoxy(55, 43);
			printf("                           ");
			gotoxy(55, 45);
			printf("                                       ");
			gotoxy(55, 47);
			printf("                                                ");
		}
	}


}