//init.c
#define _CRT_SECURE_NO_WARNINGS//社什 紗失拭辞 穿坦軒奄拭陥亜 蓄亜背醤敗.
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stage.h"
#include "Sandwich.h"
//謝還 泥 呼什 泥 紫戚綜 20
void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->vipnum = 0;
    for (int i = 0; i < 20; i++) {
        q->cus[i] = 0; // 段奄鉢
    }
}
int is_empty_queue(Queue* q) {
    return(q->front == q->rear);
}
int is_full_queue(Queue* q) {
    return((q->rear + 1) % 20 == q->front);
 }
void add_rear(Queue* q, Customer* cus) {
  
    q->rear = (q->rear + 1) % 20;
    q->cus[q->rear] = cus;

}
void add_front(Queue* q, Customer* cus) {
    q->cus[q->front] = cus;
    q->front = ( (q->front) - 1 + 20) % 20;
}

//爽昔舌
void owner_init(Owner* sand_owner) {
    sand_owner->total_income = 0;
    sand_owner->blood = 10;

    sand_owner->cusNode = (LocalNode*)malloc(sizeof(LocalNode));
    sand_owner->cusNode->cuscount = 0;
    sand_owner->cusNode->localname = 1;
    sand_owner->cusNode->cusQ = (Queue*)malloc(sizeof(Queue));
    memset(sand_owner->cusNode->cusQ, 0, sizeof(Queue));
    init_queue(sand_owner->cusNode->cusQ);
    sand_owner->cusNode->link = sand_owner->cusNode; // 切奄 切重聖 亜軒徹亀系 段奄鉢


    sand_owner->localNode = (LocalNode*)malloc(sizeof(LocalNode));
    sand_owner->localNode->cuscount = 0;
    sand_owner->localNode->localname = 1;
    sand_owner->localNode->cusQ = (Queue*)malloc(sizeof(Queue));
    memset(sand_owner->localNode->cusQ, 0, sizeof(Queue));
    init_queue(sand_owner->localNode->cusQ);
    sand_owner->localNode->link = sand_owner->localNode; // 謝還 葛球人 尻衣
}
void init_product(Sandwich* product) {
    product->top = -1;
    product->sandwich_num = (int*)malloc(5 * sizeof(int));//Max_Sand_Size
}
//什澱
int is_full_stack(Sandwich* product) {
    return (product->top == (5-1));//Max_Sand_Size
}
int is_empty_stack(Sandwich* product)
{
    return (product->top == -1);
}
int pop_stack(Sandwich* product)
{
    return product->sandwich_num[product->top--];
}
void push_stack(int item, Sandwich* product) {

    product->sandwich_num[++product->top] = item;

}
void insertnode(LocalNode* tail, int localname) {
    LocalNode* newnode = (LocalNode*)malloc(sizeof(LocalNode));
    newnode->cuscount = 0;
    newnode->localname = localname;
    newnode->cusQ = (Queue*)malloc(sizeof(Queue));
    memset(newnode->cusQ, 0, sizeof(Queue));
    init_queue(newnode->cusQ);

    newnode->link = tail->link;
    tail->link = newnode;
//獣降 左戚球稽 馬艦苑 背衣鞠革 せせせせせせせせせせせ
}
// 焼掘 鎧遂精 焼送 耕刃. 酔識授是 泥稽 壕含奄紫還 幻級 森舛
////////////////////////////////


// rider 什追糟元精 魚稽 幻級奄
void insert_min_heap(Heap* rider_heap, Rider rider) {
    int i;
    i = ++(rider_heap->heap_size);

    while ( (i != 1) && (rider.avail_time < rider_heap->heap[i/2].avail_time) ) 
    {
        rider_heap->heap[i] = rider_heap->heap[i / 2];
        i /= 2;
    }
    rider_heap->heap[i] = rider;
}

void rider_init(Heap* rider_heap) {

    rider_heap->heap_size = 0;// 昔畿什亜 0採斗 獣拙 姶照!!!
    Rider rider;
    int start = 0; // 壕含 企奄 獣娃 吃 森舛
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        rider.id = i+1;
        rider.avail_time = 0;
        insert_min_heap(rider_heap, rider);
    }
    rider_heap->heap[0].id = 0;
    rider_heap->heap[0].avail_time = 0;

    //return rider_heap;
}

void rider_avail_time_init(Heap* rider_heap) {

    rider_heap->heap_size = 0;// 昔畿什亜 0採斗 獣拙 姶照!!!
    Rider rider;
    int start = 0; // 壕含 企奄 獣娃 吃 森舛
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        rider.id = i + 1;
        rider.avail_time = ( rand() % 10) + 1;
        insert_min_heap(rider_heap, rider);
        Sleep(100);
    }
    rider_heap->heap[0].id = 0;
    rider_heap->heap[0].avail_time = 0;
}