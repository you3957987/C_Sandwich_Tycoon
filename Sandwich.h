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
    int localname; // .¼ıÀÚ¸¦ ¹®ÀÚ·Î º¯È¯ÇÏ´Â ÇÔ¼ö ¸¸µé¾î¾ßÇÔ
    Queue* cusQ;
    struct LocalNode* link;
}LocalNode; // ¿øÇü ¿¬°á¸®½ºÆ®

typedef struct rider {
    int id; // ¶óÀÌ´õ ±¸ºĞ¿ë!!!
    int avail_time; // °¡´É ½Ã°£. Å°¯“!!!!
}Rider;

//¿ì¼±šœÀ§ Å¥ - ¹è´Ş±â»ç´Ô ´ë±â½Ã°£. ¾ÆÁ÷ ¹Ì¿Ï¼º. ¿Ï¼ºÇØ¾ßÇÔ.

typedef struct heap{
    Rider heap[31];// ¹è´Ş ±â»ç 30¸í
    int heap_size;
}Heap; // Èü, ¿ì¼±¼øÀ§ Å¥

typedef struct owner {
    int total_income; // ³»µ·
    int blood; // Ã¼·Â
    LocalNode* cusNode; // ¼Õ´Ô ÀúÀå ¿¬°á¸®½ºÆ®
    LocalNode* localNode;// Áö¿ª ÀúÀå ¿¬°á¸®½ºÆ®
}Owner;

typedef struct ownerstock {
    int stock[5];
}OwnerStock; // Àç°í °ü¸® ±¸Á¶Ã¼

typedef struct listnode {
    int name;// Àç·á ÀÌ¸§
    int count; // Àç·á °³¼ö
    struct ListNode* link;
}ListNode; // ´Ü¼ø ¿¬°á ÀÌ½ºÆ®

typedef struct DlistNode {
    int waittime; // ³³Ç° ´ë±â½Ã°£
    int localnum; // ³³Ç° Àå¼Ò ¹øÈ£
    ListNode* stocklist; // Çìµå Æ÷ÀÎÅÍ
    struct DlistNode* blink;
    struct DlistNode* alink;
}DlistNode; // Àç°í ¹Ì´Ï°ÔÀÓ¿ë ÀÌÁß ¿¬°á ¸®½ºÆ®

//ÇØ½Ì

typedef struct rider_chart_list {
    Rider rider_chart; // id, ´ë±â½Ã°£.
    struct Rider_chart_list* link;
}Rider_chart_list;
