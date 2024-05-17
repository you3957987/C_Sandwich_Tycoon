#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
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
	rider = rider_heap->heap[1]; // 가장 위쪽 일단 뽁기
	temp = rider_heap->heap[(rider_heap->heap_size)--]; // 말단 노드
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
	int what; // 스택 검산용
	int time; // 대기시간 저장용
	int uptime; // 증가시간 랜덤값 저장용

	rider = delete_min_heap(rider_heap); // 라이더 가챠~
	time = rider.avail_time;

	while (1) {
		gotoxy(45, 27);
		printf("[%d] 배달기사님이 오셨네요!. 배달을 보낼 지역을 선택하세요!", rider.id);
		showlocaldeliver(pLocal);
		gotoxy(50, 33);
		printf("( 1 : 선택 / 2 : 다음 지역 )  :: ");
		scanf("%d", &guess);
		if (guess == 1) {
			if (pLocal->cuscount == 0) {
				gotoxy(50, 34);
				printf("그 지역은 배달할게 없어요!!");
			}
			else {
				gotoxy(50, 35);
				printf("그럼 배달을 시작할게요! 기사님을 부를게요~");
				Sleep(1000);
				cusvipnum = pCus->cusQ->vipnum;
				localvipnum = pLocal->cusQ->vipnum;
				gotoxy(50, 36);
				printf("VIP 주문 : %d개 확인되었습니다.",localvipnum);
				if (cusvipnum != localvipnum) { // vip 잘못 된거 거르기
					gotoxy(45, 37);
					printf("실제 VIP : %d // 확인된 VIP : %d 샌드위치를 잘못 만드셨어요!!!", cusvipnum, localvipnum);
					*on = 0;
					gotoxy(45, 38);
					printf("다음 스테이지에서는 제대로 만들어 보세요!");
					Sleep(2000);
					break;
				}
				if (localvipnum > 0) {
					gotoxy(50, 37);
					printf("VIP 주문 확인! 먼저 배달할게요!");
					Customer* comparecus = delete_front(pCus->cusQ);
					Customer* comparelocal = delete_front(pLocal->cusQ);
					what = comparesandwich(comparecus, comparelocal);
					if (what == 1) {
						gotoxy(50, 38);
						printf("내가 주문한 샌드위치가 아니야!!!!!!!");
						Sleep(2000);
					}
					else if(what == 0) {
						gotoxy(50, 38);
						printf("우마이");
						Sleep(2000);
					}
				}
				else {
					gotoxy(50, 37);
					printf("VIP 주문이 없으므로 일반 배달할게요!");
					Customer* comparecus = delete_rear(pCus->cusQ);
					Customer* comparelocal = delete_rear(pLocal->cusQ);
					what = comparesandwich(comparecus, comparelocal);
					if (what == 1) {
						gotoxy(50, 38);
						printf("내가 주문한 샌드위치가 아니야!!!!!!!");
						Sleep(2000);
					}
					else if (what == 0) {
						gotoxy(50, 38);
						printf("우마이");
						Sleep(2000);
					}
				}
				uptime = (rand() % 5) + 1;
				rider.avail_time += uptime;
				gotoxy(50, 40);
				printf("[%d] 배달 기사님의 대기시간이 %d만큼 증가했어요! < %d > -> < %d >  ",rider.id ,uptime, time, rider.avail_time );
				insert_min_heap(rider_heap, rider);
				while (1) {
					gotoxy(50, 41);
					printf("확인하셨다면 1을 입력해주세요~ : ");
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