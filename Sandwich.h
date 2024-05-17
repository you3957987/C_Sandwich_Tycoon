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
}LocalNode; // ���Ḯ��Ʈ

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
