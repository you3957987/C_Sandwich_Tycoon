//stage.c
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>
#include "Stage.h"
#include "Sandwich.h"

void stageinit(Owner* sand_owner, int localnum) {
	LocalNode* p;
	p = sand_owner->localNode;
	for (int i = 0; i < localnum; i++) { //지역수 만큼 연결리스트 초기화 할거 초기화
		p->cuscount = 0;// 손님수
		p->cusQ->vipnum = 0; // vip수
		p->cusQ->front = 0; // 큐 초기화
		p->cusQ->rear = 0;
		p = p->link;
	}
	p = sand_owner->cusNode;
	for (int i = 0; i < localnum; i++) { //지역수 만큼 연결리스트 초기화 할거 초기화
		p->cuscount = 0;
		p->cusQ->vipnum = 0;
		p->cusQ->front = 0;
		p->cusQ->rear = 0;
		p = p->link;
	}
}

void ShowBaseUi(Stage* p) {
	cls();
	showui();
	gotoxy(55, 23);
	printf("[[[ %s ]]]\n", p->title);
}

void stage_push(Stage_Stack* stage_stack, Stage* p)
{
	if (stage_stack->top < 20 - 1)
		stage_stack->stack[++(stage_stack->top)] = p;
}
Stage* stage_pop(Stage_Stack* stage_stack)
{
	Stage* p = NULL;
	if (stage_stack->top > -1)
		p = stage_stack->stack[(stage_stack->top)--];
	return p;
}
void travel_stage(Stage_Stack* stage_stack, Stage* root,Owner *sand_owner, Heap* rider_heap)// 자 드가자
{
	Stage* p;
	stage_push(stage_stack, root);
	int on = 1; // vip 잘못 넣었을 떄 체크용
	int stagecheck; // 스테이지 잘못 넣는 거 방지용
	while (stage_stack->top > -1)
	{
		p = stage_pop(stage_stack);

		if (strcmp(p->title, "노멀-1 준비 스테이지") == 0) {

			rider_avail_time_init(rider_heap);
			for (int i = 1; i <= p->cusnum; i++) // 스테이지 손님수 만큼 반복.
			{
				ShowBaseUi(p);
				getordersandwich(sand_owner, p->localnum, i, &stagecheck); // 샌드위치 주문 받기- 스테이지 지역수 , 몇번째 손님 , 스테이지 체크용
				ShowBaseUi(p);
				makesandwich(sand_owner, &stagecheck); // 샌드위치 만들기 ,스테이지 체크용
				ShowBaseUi(p);
				checksandwich(sand_owner,(p->cusnum)-i,p->localnum );
			}
			ShowBaseUi(p);
			ShowStateReady(sand_owner);
		}
		if (strcmp(p->title, "노멀-1 판매 스테이지") == 0) {

			for (int i = 1; i <= p->cusnum; i++) // 스테이지 손님수 만큼 반복.
			{
				ShowBaseUi(p);
				checkrider(sand_owner, rider_heap);
				ShowBaseUi(p);
				deliversandwich(sand_owner, rider_heap,&on);
				if (on == 0) {
					break;
				}
			}
			stageinit(sand_owner,p->localnum);
			ShowBaseUi(p);
			ShowStateSell(sand_owner);

		}
		if (strcmp(p->title, "노멀-2 준비 스테이지") == 0) {

			insertnode(sand_owner->cusNode, 2);
			insertnode(sand_owner->localNode, 2);
			on = 1;
			for (int i = 1; i <= p->cusnum; i++) // 스테이지 손님수 만큼 반복.
			{
				ShowBaseUi(p);
				getordersandwich(sand_owner, p->localnum, i, &stagecheck); // 샌드위치 주문 받기- 스테이지 지역수 , 몇번째 손님 , 스테이지 체크용
				ShowBaseUi(p);
				makesandwich(sand_owner, &stagecheck); // 샌드위치 만들기 ,스테이지 체크용
				ShowBaseUi(p);
				checksandwich(sand_owner, (p->cusnum) - i, p->localnum);

			}
			ShowBaseUi(p);
			ShowStateReady(sand_owner);

		}
		if (strcmp(p->title, "노멀-2 판매 스테이지") == 0) {

			for (int i = 1; i <= p->cusnum; i++) // 스테이지 손님수 만큼 반복.
			{
				ShowBaseUi(p);
				checkrider(sand_owner, rider_heap);
				ShowBaseUi(p);
				deliversandwich(sand_owner, rider_heap, &on);
				if (on == 0) {
					break;
				}
			}
			stageinit(sand_owner, p->localnum);
			ShowBaseUi(p);
			ShowStateSell(sand_owner);
			
		}
		if (strcmp(p->title, "하드-1 준비 스테이지") == 0) {

		}
		if (strcmp(p->title, "하드-1 판매 스테이지") == 0) {
			
		}
		if (strcmp(p->title, "하드-2 준비 스테이지") == 0) {
			
		}
		if (strcmp(p->title, "하드-2 판매 스테이지") == 0) {
			
		}
		if (p->right != NULL)
			stage_push(stage_stack, p->right);
		if (p->left != NULL)
			stage_push(stage_stack, p->left);
	}
}

void start_stage() {
	Stage_Stack* stage_stack = (Stage_Stack*)malloc(sizeof(Stage_Stack));
	memset(stage_stack, 0, sizeof(Stage_Stack));
	stage_stack->top = -1;

	Stage nomaloneready = { "노멀-1 준비 스테이지",NULL ,NULL,1,1 };// 손님수 지역수
	Stage nomalonego = { "노멀-1 판매 스테이지",NULL ,NULL ,1,1};
	Stage nomaltwoready = { "노멀-2 준비 스테이지", NULL, NULL ,2,2};//손님수 지역수
	Stage nomaltwogo = { "노멀-2 판매 스테이지", NULL, NULL, 2, 2 };
	Stage hardoneready = { "하드-1 준비 스테이지",NULL ,NULL ,3,3};
	Stage hardonego = { "하드-1 판매 스테이지",NULL ,NULL ,3,3};
	Stage hardtwoready = { "하드-2 준비 스테이지",NULL ,NULL ,4,4};
	Stage hardtwogo = { "하드-2 판매 스테이지",NULL , NULL ,4,4};
	Stage hardone = { "하드-1 스테이지", &hardoneready,&hardonego };
	Stage hardtwo = { "하드-2 스테이지",&hardtwoready ,&hardtwogo };
	Stage nomalone = { "노멀-1 스테이지",&nomaloneready ,&nomalonego };
	Stage nomaltwo = { "노멀-2 스테이지",&nomaltwoready ,&nomaltwogo };
	Stage hard = { "하드 난이도", &hardone,&hardtwo };
	Stage nomal = { "노멀 난이도",&nomalone , &nomaltwo};
	Stage root = { "Game_Start",&nomal ,&hard };

	Owner sand_owner;
	owner_init(&sand_owner);

	Heap rider_heapb;
	rider_init(&rider_heapb);
	Heap* rider_heap = &rider_heapb;


	travel_stage(stage_stack, &root, &sand_owner, rider_heap);// 시작!!!!!!!!!!!!!!


}