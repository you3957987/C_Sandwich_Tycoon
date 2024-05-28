//stage.h
#define _CRT_SECURE_NO_WARNINGS//소스 속성에서 전처리기에다가 추가해야함.
#include <stdio.h>
#include <windows.h>

typedef struct Stage {
	char title[100];
	struct Stage* left, * right;
	int cusnum;// 스테이지별 손님 수
	int localnum; // 스테이지별 지역수
	int actiontime; // 스테이지별 재고 미니게임 행동수
}Stage; // 자료구조 : 트리

typedef struct stage_stack {
	Stage* stack[20];
	int top;
}Stage_Stack; // 트리용 스테이지 스택