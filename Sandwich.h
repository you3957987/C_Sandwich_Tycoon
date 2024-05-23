//sandwich.h
#pragma once
typedef struct Sandwich {
    int* sandwich_num; // 5��.
    int top;
}Sandwich; // ����

typedef struct customer {
    int vip;
    int local;
    Sandwich* sandwich;//������ġ ����
} Customer;

typedef struct queue {
    int front, rear;
    int vipnum;
    Customer* cus[20];// �մԼ� �ִ� 20��
}Queue;// ť

typedef struct local {
    int cuscount; //
    int localname; // .���ڸ� ���ڷ� ��ȯ�ϴ� �Լ� ��������
    Queue* cusQ;
    struct LocalNode* link;
}LocalNode; // ���� ���Ḯ��Ʈ

typedef struct rider {
    int id; // ���̴� ���п�!!!
    int avail_time; // ���� �ð�. Ű��!!!!
}Rider;

//�켱���� ť - ��ޱ��� ���ð�. ���� �̿ϼ�. �ϼ��ؾ���.

typedef struct heap{
    Rider heap[11];// ��� ��� 10��
    int heap_size;
}Heap; // ��, �켱���� ť

typedef struct owner {
    int total_income; // ����
    int blood; // ü��
    LocalNode* cusNode; // �մ� ���� ���Ḯ��Ʈ
    LocalNode* localNode;// ���� ���� ���Ḯ��Ʈ
}Owner;

typedef struct ownerstock {
    int bread; // 1
    int vege; // 2
    int meat; // 3
    int souce; // 4
    int drink; // 5
}OwnerStock; // ��� ���� ����ü

typedef struct listnode {
    int name;// ��� �̸�
    int count; // ��� ����
    struct ListNode* link;
}ListNode; // �ܼ� ���� �̽�Ʈ

typedef struct DlistNode {
    int waittime; // ��ǰ ���ð�
    int localnum; // ��ǰ ��� ��ȣ
    ListNode* stocklist; // ��� ������
    struct DlistNode* blink;
    struct DlistNode* alink;
}DlistNode; // ��� �̴ϰ��ӿ� ���� ���� ����Ʈ
