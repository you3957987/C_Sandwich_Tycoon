//sandwich.h
#pragma once
typedef struct Sandwich {
    int* sandwich_num; // 5개.
    int top;
}Sandwich; // 스택

typedef struct customer {
    int vip;
    int local;
    Sandwich* sandwich;//샌드위치 스택
} Customer;

typedef struct queue {
    int front, rear;
    int vipnum;
    Customer* cus[20];// 손님수 최대 20명
}Queue;// 큐

typedef struct local {
    int cuscount; //
    int localname; // .숫자를 문자로 변환하는 함수 만들어야함
    Queue* cusQ;
    struct LocalNode* link;
}LocalNode; // 연결리스트

typedef struct rider {
    int id; // 라이더 구분용!!!
    int avail_time; // 가능 시간. 키캆!!!!
}Rider;

//우선슌위 큐 - 배달기사님 대기시간. 아직 미완성. 완성해야함.

typedef struct heap{
    Rider heap[11];// 배달 기사 10명
    int heap_size;
}Heap; // 힙, 우선순위 큐

typedef struct owner {
    int total_income; // 내돈
    int blood; // 체력
    LocalNode* cusNode; // 손님 저장 연결리스트
    LocalNode* localNode;// 지역 저장 연결리스트
}Owner;
