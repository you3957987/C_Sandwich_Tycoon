//sandwich.h
#pragma once
typedef struct Sandwich {
    int* sandwich_num; // malloc���� �� 5�� �����Ҵ�.
    int top;
}Sandwich; // �ڷᱸ�� : ����

typedef struct customer {
    int vip; // �մ��� vip�� ��� 1, �ƴҰ�� 0
    int local; // getorder�Լ����� �մ���
    Sandwich* sandwich;//������ġ ����
} Customer; // �ڷᱸ�� : (�մ�)����ü

typedef struct queue {
    int front, rear;
    int vipnum;
    Customer* cus[20];// �մԼ� �ִ� 20��
}Queue;// �ڷᱸ�� : ��( vip�� ��� add front, �Ϲ� �մ��� ��� add rear) & ť

typedef struct local {
    int cuscount; //
    int localname; // .���ڸ� ���ڷ� ��ȯ�ϴ� �Լ� ��������
    Queue* cusQ;
    struct LocalNode* link;
}LocalNode; // �ڷᱸ�� : ���� ���Ḯ��Ʈ

typedef struct rider {
    int id; // ���̴� ���п�. ������ 3�ڸ� ��.
    int avail_time; // ��ޱ�� ��� �ð� == ��(�켱���� ť������ Ű��)
}Rider; //�ڷᱸ�� : ����ü

typedef struct heap{
    Rider heap[31];// ��� ��� 30��. 1��° �ε����� ����.
    int heap_size;
}Heap; // �ڷᱸ�� : ��, �켱���� ť

typedef struct owner {
    int total_income; // ����
    int blood; // ü��
    LocalNode* cusNode; // �մ� ���� ���Ḯ��Ʈ
    LocalNode* localNode;// ���� ���� ���Ḯ��Ʈ
}Owner;// �ڷᱸ�� : ����ü.

typedef struct ownerstock {
    int stock[5];
}OwnerStock; // ��� ���� ����ü

typedef struct listnode {
    int name;// ��� �̸�
    int count; // ��� ����
    struct ListNode* link;
}ListNode; // �ڷᱸ�� : �ܼ� ���� ����Ʈ

typedef struct DlistNode {
    int waittime; // ��ǰ ���ð�
    int localnum; // ��ǰ ��� ��ȣ
    ListNode* stocklist; // ��� ������
    struct DlistNode* blink;
    struct DlistNode* alink;
}DlistNode; // �ڷᱸ�� : ��� �̴ϰ��ӿ� ���� ���� ����Ʈ

//�ؽ�

typedef struct rider_chart_list {
    Rider rider_chart; // id, ���ð�.
    struct Rider_chart_list* link;
}Rider_chart_list; // �ڷᱸ�� : ü�̴� ���̺� == �ؽ�.
