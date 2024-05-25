#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"

Rider delete_min_heap(Heap* rider_heap) {
	int parent, child;
	Rider rider, temp;
	rider = rider_heap->heap[1]; // ���� ���� �ϴ� �ȱ�
	temp = rider_heap->heap[(rider_heap->heap_size)--]; // ���� ���
	parent = 1;
	child = 2;

	while (child <= rider_heap->heap_size) {
		if ((child < rider_heap->heap_size) && (rider_heap->heap[child].avail_time > rider_heap->heap[child + 1].avail_time)) {
			child++;
		}
		if (temp.avail_time < rider_heap->heap[child].avail_time) {
			break;
		}
		rider_heap->heap[parent] = rider_heap->heap[child];
		parent = child;
		child *= 2;
	}
	rider_heap->heap[parent] = temp;
	return rider;
}


Customer* delete_front(Queue* q) {
	q->front = (q->front + 1) % 20;	
	return q->cus[q->front];
}
Customer* delete_rear(Queue* q) {
	int index = q->rear;
	q->rear = (q->rear - 1 + 20) % 20;
	return (q->cus[index]);
}

void showlocaldeliver(LocalNode* p) {
	gotoxy(55, 31);
	printf("            [[%d]]", p->localname);
}

int comparesandwich(Customer* comparecus, Customer* comparelocal) {

	for (int i = 0; i < 5; i++) {
		int local, cus;
		local = pop_stack(comparelocal->sandwich);
		cus = pop_stack(comparecus->sandwich);
		if ( local != cus ) {
			return 1;
		}
	}
	return 0;
}

void deliversandwich(Owner* sand_owner, Heap* rider_heap, int *on) {

	LocalNode* pLocal;
	LocalNode* pCus;
	Rider rider = { 0,0 };
	pLocal = sand_owner->localNode;
	pCus = sand_owner->cusNode;
	int guess;
	int cusvipnum;
	int localvipnum;
	int what; // ���� �˻��
	int time; // ���ð� �����
	int uptime; // �����ð� ������ �����

	// ���̴� �̱� ������ �̴ϰ���

	rider = delete_min_heap(rider_heap); // ���̴� ��í~
	time = rider.avail_time;

	while (1) {
		gotoxy(45, 27);
		printf("[%d] ��ޱ����� ���̳׿�!. ����� ���� ������ �����ϼ���!", rider.id);
		showlocaldeliver(pLocal);
		gotoxy(50, 33);
		printf("( 1 : ���� / 2 : ���� ���� )  :: ");
		scanf("%d", &guess);
		if (guess == 1) {
			if (pLocal->cuscount == 0) {
				gotoxy(50, 34);
				printf("�� ������ ����Ұ� �����!!");
			}
			else {
				gotoxy(50, 35);
				printf("�׷� ����� �����ҰԿ�! ������ �θ��Կ�~");
				Sleep(1000);
				cusvipnum = pCus->cusQ->vipnum;
				localvipnum = pLocal->cusQ->vipnum;
				gotoxy(50, 36);
				printf("VIP �ֹ� : %d�� Ȯ�εǾ����ϴ�.",localvipnum);
				if (cusvipnum != localvipnum) { // vip �߸� �Ȱ� �Ÿ���
					Sleep(1000);
					gotoxy(45, 37);
					printf("���� VIP : %d // Ȯ�ε� VIP : %d ������ġ�� �߸� ����̾��!!!", cusvipnum, localvipnum);
					*on = 0;
					Sleep(1000);
					gotoxy(45, 38);
					printf("ü���� �����߾��!! <%d> -> <%d> ", sand_owner->blood, sand_owner->blood-2);
					sand_owner->blood -= 2;
					Sleep(1000);
					gotoxy(42, 39);
					printf("���� �������������� ����� ����� ������!(3���� ���� ���������� �ڵ����� �̵��ǿ�~)");
					Sleep(3000);
					break;
				}
				if (localvipnum > 0) {
					Sleep(1000);
					gotoxy(50, 37);
					printf("VIP �ֹ� Ȯ��! ���� ����ҰԿ�!");
					Customer* comparecus = delete_front(pCus->cusQ);
					Customer* comparelocal = delete_front(pLocal->cusQ);
					what = comparesandwich(comparecus, comparelocal);
					if (what == 1) {
						Sleep(1000);
						gotoxy(50, 38);
						printf("���� �ֹ��� ������ġ�� �ƴϾ�!!!!!!!");
					}
					else if(what == 0) {
						Sleep(1000);
						gotoxy(50, 38);
						printf("�츶��!!");
						Sleep(1000);
						gotoxy(50, 39);
						printf("�� ������ �����߾��!! <%d> -> <%d>", sand_owner->total_income, sand_owner->total_income + 100);
						sand_owner->total_income += 150; // vip�� 50�� ��
					}
					pCus->cuscount -= 1;
					pLocal->cuscount -= 1; // �մԼ� ����
					pCus->cusQ->vipnum -= 1;
					pLocal->cusQ->vipnum -= 1; //vip�� ����
				}
				else {
					Sleep(1000);
					gotoxy(50, 37);
					printf("VIP �ֹ��� �����Ƿ� �Ϲ� ����ҰԿ�!");
					Customer* comparecus = delete_rear(pCus->cusQ);
					Customer* comparelocal = delete_rear(pLocal->cusQ);
					what = comparesandwich(comparecus, comparelocal);
					if (what == 1) {
						Sleep(1000);
						gotoxy(50, 38);
						printf("���� �ֹ��� ������ġ�� �ƴϾ�!!!!!!!");
			
					}
					else if (what == 0) {
						Sleep(1000);
						gotoxy(50, 38);
						printf("�츶��");
						Sleep(1000);
						gotoxy(50, 39);
						printf("�� ������ �����߾��!! <%d> -> <%d>", sand_owner->total_income, sand_owner->total_income + 100);
						sand_owner->total_income += 100;
		
					}
					pCus->cuscount -= 1;
					pLocal->cuscount -= 1;//�մԼ� ����
				}
				uptime = (rand() % 5) + 1;
				rider.avail_time += uptime;
				Sleep(1000);
				gotoxy(45, 41);
				printf("[%d] ��� ������ ���ð��� %d��ŭ �����߾��! < %d > -> < %d >  ",rider.id ,uptime, time, rider.avail_time-1 );
				insert_min_heap(rider_heap, rider);

				for (int i = 1; i <= 10; i++) {
					rider_heap->heap[i].avail_time -=1;
					if (rider_heap->heap[i].avail_time == 0) {
						rider_heap->heap[i].avail_time = 1;
					}
				}
				while (1) {
					Sleep(1000);
					gotoxy(51, 43);
					printf("Ȯ���ϼ̴ٸ� 1�� �Է����ּ���~ : ");
					scanf("%d", &guess);
					if (guess == 1) {
						break;
					}
				}
				break;
			}
		}
		else if (guess == 2) {
			pLocal = pLocal->link;
			pCus = pCus->link;
		}
	}

}