//checkrider.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
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
		gotoxy(55, 33+i);
		printf("[%d] ������ ���ð� : %d", rider_heap->heap[i].id, rider_heap->heap[i].avail_time);
	}
	gotoxy(47, 45);
	int guess;
	printf("���� ���� ������ ȣ���Ͻ÷��� 1�� �Է��ϼ���!! : ");
	while (1) {
		scanf("%d", &guess);
		if (guess == 1) {
			break;
		}
	}
}


void checkrider(Owner* sand_owner,Heap* rider_heap) {
	int guess;
	gotoxy(41, 30);
	printf("��� ������ ������ Heap���� ���� �˻��Ͻ÷��� 1�� �Է��ϼ��� : ");
	while (1) {
		scanf("%d", &guess);
		if (guess == 1) {
			gotoxy(52, 31);
			printf("�˻���........(��� ��ٷ��ּ���~) ");// ������ ���� �ð�!
			break;
		}
	}
	Sleep(1000);
	showrider(rider_heap);

}