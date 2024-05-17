//sandwich.h
#pragma once
typedef struct Sandwich {
    int* sandwich_num; // 5°³.
    int top;
}Sandwich; // ½ºÅÃ

typedef struct customer {
    int vip;
    int local;
    Sandwich* sandwich;//»÷µåÀ§Ä¡ ½ºÅÃ
} Customer;

typedef struct queue {
    int front, rear;
    int vipnum;
    Customer* cus[20];// ¼Õ´Ô¼ö ÃÖ´ë 20¸í
}Queue;// Å¥

typedef struct local {
    int cuscount; //
    int localname; // .¼ýÀÚ¸¦ ¹®ÀÚ·Î º¯È¯ÇÏ´Â ÇÔ¼ö ¸¸µé¾î¾ßÇÔ
    Queue* cusQ;
    struct LocalNode* link;
}LocalNode; // ¿¬°á¸®½ºÆ®

typedef struct rider {
    int id; // ¶óÀÌ´õ ±¸ºÐ¿ë!!!
    int avail_time; // °¡´É ½Ã°£. Å°¯“!!!!
}Rider;

//¿ì¼±šœÀ§ Å¥ - ¹è´Þ±â»ç´Ô ´ë±â½Ã°£. ¾ÆÁ÷ ¹Ì¿Ï¼º. ¿Ï¼ºÇØ¾ßÇÔ.

typedef struct heap{
    Rider heap[11];// ¹è´Þ ±â»ç 10¸í
    int heap_size;
}Heap; // Èü, ¿ì¼±¼øÀ§ Å¥

typedef struct owner {
    int total_income; // ³»µ·
    int blood; // Ã¼·Â
    LocalNode* cusNode; // ¼Õ´Ô ÀúÀå ¿¬°á¸®½ºÆ®
    LocalNode* localNode;// Áö¿ª ÀúÀå ¿¬°á¸®½ºÆ®
}Owner;
