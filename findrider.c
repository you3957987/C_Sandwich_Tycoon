#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // ����Ű�� ���
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

	// �� �ڸ����� ����
	while (n > 0) {
		sum_of_digits += n % 10; // 1�� �ڸ����� sum_of_digits�� ����
		n /= 10; // n�� 10���� ������ ���� �ڸ����� �̵�
	}

	// �� �ڸ����� ���� 1�� �ڸ����� ��ȯ
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
	printf("%d ������ �־��!!", hash_value);

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
	printf("���� ���� ������ [%d] �����̿���!", answer);
	while (1) { // �ȹٷ� �Է��� �� ����
		for (int i = 1; i <= 3; i++) {
			while (1) {
				gotoxy(55, 28 + i * 3);
				random = (rand() % 10) + 1;
				printf("ID [%d] : %d   ", i, random); // ���� �߰��Ͽ� ���� �� �����
				Sleep(1000);

				if (_kbhit()) {
					c = _getch();
					if (c == 80) { // �Ʒ� ����Ű�� ASCII �ڵ�
						id = id * 10 + random;
						break;
					}
				}
			}
		}
		gotoxy(55, 43);
		printf("ID : %d �� �����ҰԿ�~", id);

		if (hash_chain_search(answer, rider_table) == answer) { // id�� �ٲٱ�
			gotoxy(55, 47);
			printf("������ �����߾�� !!");
			gotoxy(55, 48);
			printf("Ȯ���ϼ̴ٸ� 1�� �Է����ּ���~ : ");
			scanf("%d", &guess);
			if (guess == 1) {
				break;
			}

		}
		else {
			gotoxy(55, 47);
			printf("������ �����߾��. �ٽ� �õ��� ������!");
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