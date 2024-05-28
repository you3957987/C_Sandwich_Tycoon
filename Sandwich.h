//sandwich.h
#pragma once
typedef struct Sandwich {
    int* sandwich_num; // malloc으로 총 5갱 동적할당.
    int top;
}Sandwich; // 자료구조 : 스택

typedef struct customer {
    int vip; // 손님이 vip일 경우 1, 아닐경우 0
    int local; // getorder함수에서 손님의
    Sandwich* sandwich;//샌드위치 스택
} Customer; // 자료구조 : (손님)구조체

typedef struct queue {
    int front, rear;
    int vipnum;
    Customer* cus[20];// 손님수 최대 20명
}Queue;// 자료구조 : 덱( vip일 경우 add front, 일반 손님일 경우 add rear) & 큐

typedef struct local {
    int cuscount; //
    int localname; // .숫자를 문자로 변환하는 함수 만들어야함
    Queue* cusQ;
    struct LocalNode* link;
}LocalNode; // 자료구조 : 원형 연결리스트

typedef struct rider {
    int id; // 라이더 구분용. 랜덤한 3자리 수.
    int avail_time; // 배달기사 대기 시간 == 힙(우선순위 큐에서의 키값)
}Rider; //자료구조 : 구조체

typedef struct heap{
    Rider heap[31];// 배달 기사 30명. 1번째 인덱스는 무시.
    int heap_size;
}Heap; // 자료구조 : 힙, 우선순위 큐

typedef struct owner {
    int total_income; // 내돈
    int blood; // 체력
    LocalNode* cusNode; // 손님 저장 연결리스트
    LocalNode* localNode;// 지역 저장 연결리스트
}Owner;// 자료구조 : 구조체.

typedef struct ownerstock {
    int stock[5];
}OwnerStock; // 재고 관리 구조체

typedef struct listnode {
    int name;// 재료 이름
    int count; // 재료 개수
    struct ListNode* link;
}ListNode; // 자료구조 : 단순 연결 리스트

typedef struct DlistNode {
    int waittime; // 납품 대기시간
    int localnum; // 납품 장소 번호
    ListNode* stocklist; // 헤드 포인터
    struct DlistNode* blink;
    struct DlistNode* alink;
}DlistNode; // 자료구조 : 재고 미니게임용 이중 연결 리스트

//해싱

typedef struct rider_chart_list {
    Rider rider_chart; // id, 대기시간.
    struct Rider_chart_list* link;
}Rider_chart_list; // 자료구조 : 체이닝 테이블 == 해싱.
