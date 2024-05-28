//stage.c
#define _CRT_SECURE_NO_WARNINGS//�ҽ� �Ӽ����� ��ó���⿡�ٰ� �߰��ؾ���.
#include <stdio.h>
#include <windows.h>
#include "Stage.h"
#include "Sandwich.h"

struct Rider_chart_list* rider_table[10]; // �ؽ� ���̺� ������ ���ڸ� 0~9����

void stageinit(Owner* sand_owner, int localnum) {
	LocalNode* p;
	p = sand_owner->localNode;
	for (int i = 0; i < localnum; i++) { //������ ��ŭ ���Ḯ��Ʈ �ʱ�ȭ �Ұ� �ʱ�ȭ
		p->cuscount = 0;// �մԼ�
		p->cusQ->vipnum = 0; // vip��
		p->cusQ->front = 0; // ť �ʱ�ȭ
		p->cusQ->rear = 0;
		p = p->link;
	}
	p = sand_owner->cusNode;
	for (int i = 0; i < localnum; i++) { //������ ��ŭ ���Ḯ��Ʈ �ʱ�ȭ �Ұ� �ʱ�ȭ
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
void travel_stage(Stage_Stack* stage_stack, Stage* root,Owner *sand_owner, Heap* rider_heap,OwnerStock* stock, Rider_chart_list* rider_table[])
{
	Stage* p;
	stage_push(stage_stack, root);
	int on = 1; // vip �߸� �־��� �� üũ��
	int stagecheck; // �������� �߸� �ִ� �� ������
	while (stage_stack->top > -1)
	{
		p = stage_pop(stage_stack);

		if (strcmp(p->title, "���-1 �غ� ��������") == 0) {

			ShowBaseUi(p);
			stockminigame(stock,p->actiontime); // ���, �ൿŸ��
			ShowBaseUi(p);
			ShowStateStock(sand_owner,stock);

			for (int i = 1; i <= p->cusnum; i++) // �������� �մԼ� ��ŭ �ݺ�.
			{
				ShowBaseUi(p);
				getordersandwich(sand_owner, p->localnum, i, &stagecheck,stock); // ������ġ �ֹ� �ޱ�- �������� ������ , ���° �մ� , �������� üũ��
				ShowBaseUi(p);
				makesandwich(sand_owner, &stagecheck, stock); // ������ġ ����� ,�������� üũ�� // ���
				ShowBaseUi(p);
				checksandwich(sand_owner,(p->cusnum)-i,p->localnum, stock );
			}
			ShowBaseUi(p);
			ShowStateReady(sand_owner,stock);
		}
		if (strcmp(p->title, "���-1 �Ǹ� ��������") == 0) {

			for (int i = 1; i <= p->cusnum; i++) // �������� �մԼ� ��ŭ �ݺ�.
			{
				ShowBaseUi(p);
				checkrider(sand_owner, rider_heap, stock);
				ShowBaseUi(p);
				findrider(rider_heap,rider_table,stock, sand_owner);
				ShowBaseUi(p);
				deliversandwich(sand_owner, rider_heap,&on, stock);
				if (on == 0) {
					break;
				}
			}
			stageinit(sand_owner,p->localnum);
			ShowBaseUi(p);
			ShowStateSell(sand_owner,stock);

		}
		if (strcmp(p->title, "���-2 �غ� ��������") == 0) {

			insertnode(sand_owner->cusNode, 2);
			insertnode(sand_owner->localNode, 2);
			on = 1; // ���� �߰�(���� ���� ����Ʈ insert) + �� �������� vip �߸� ������� ��, on�� 0�� �Ǿ������״� 1�� �ʱ�ȭ.


			ShowBaseUi(p);
			stockminigame(stock, p->actiontime); // ���, �ൿŸ��
			ShowBaseUi(p);
			ShowStateStock(sand_owner, stock);

			for (int i = 1; i <= p->cusnum; i++) // �������� �մԼ� ��ŭ �ݺ�.
			{
				ShowBaseUi(p);
				getordersandwich(sand_owner, p->localnum, i, &stagecheck); // ������ġ �ֹ� �ޱ�- �������� ������ , ���° �մ� , �������� üũ��
				ShowBaseUi(p);
				makesandwich(sand_owner, &stagecheck, stock); // ������ġ ����� ,�������� üũ�� // ���
				ShowBaseUi(p);
				checksandwich(sand_owner, (p->cusnum) - i, p->localnum);
			}
			ShowBaseUi(p);
			ShowStateReady(sand_owner, stock);

		}
		if (strcmp(p->title, "���-2 �Ǹ� ��������") == 0) {

			for (int i = 1; i <= p->cusnum; i++) // �������� �մԼ� ��ŭ �ݺ�.
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
			ShowStateSell(sand_owner, stock);
			
		}
		if (strcmp(p->title, "�ϵ�-1 �غ� ��������") == 0) { // ��� ������������ ���� �߰��Ǵ°� �̿ܿ��� ����

			insertnode(sand_owner->cusNode, 3);
			insertnode(sand_owner->localNode, 3);
			on = 1; // ���� �߰�(���� ���� ����Ʈ insert) + �� �������� vip �߸� ������� ��, on�� 0�� �Ǿ������״� 1�� �ʱ�ȭ.
			ShowBaseUi(p);
			stockminigame(stock, p->actiontime); // ���, �ൿŸ��
			ShowBaseUi(p);
			ShowStateStock(sand_owner, stock);

			for (int i = 1; i <= p->cusnum; i++) // �������� �մԼ� ��ŭ �ݺ�.
			{
				ShowBaseUi(p);
				getordersandwich(sand_owner, p->localnum, i, &stagecheck); // ������ġ �ֹ� �ޱ�- �������� ������ , ���° �մ� , �������� üũ��
				ShowBaseUi(p);
				makesandwich(sand_owner, &stagecheck, stock); // ������ġ ����� ,�������� üũ�� // ���
				ShowBaseUi(p);
				checksandwich(sand_owner, (p->cusnum) - i, p->localnum);
			}
			ShowBaseUi(p);
			ShowStateReady(sand_owner, stock);

		}
		if (strcmp(p->title, "�ϵ�-1 �Ǹ� ��������") == 0) {
			for (int i = 1; i <= p->cusnum; i++) // �������� �մԼ� ��ŭ �ݺ�.
			{
				ShowBaseUi(p);
				checkrider(sand_owner, rider_heap, stock);
				ShowBaseUi(p);
				findrider(rider_heap, rider_table, stock, sand_owner);
				ShowBaseUi(p);
				deliversandwich(sand_owner, rider_heap, &on, stock);
				if (on == 0) {
					break;
				}
			}
			stageinit(sand_owner, p->localnum);
			ShowBaseUi(p);
			ShowStateSell(sand_owner, stock);
		}
		if (strcmp(p->title, "�ϵ�-2 �غ� ��������") == 0) {

			insertnode(sand_owner->cusNode, 4);
			insertnode(sand_owner->localNode, 4);
			on = 1; // ���� �߰�(���� ���� ����Ʈ insert) + �� �������� vip �߸� ������� ��, on�� 0�� �Ǿ������״� 1�� �ʱ�ȭ.
			ShowBaseUi(p);
			stockminigame(stock, p->actiontime); // ���, �ൿŸ��
			ShowBaseUi(p);
			ShowStateStock(sand_owner, stock);

			for (int i = 1; i <= p->cusnum; i++) // �������� �մԼ� ��ŭ �ݺ�.
			{
				ShowBaseUi(p);
				getordersandwich(sand_owner, p->localnum, i, &stagecheck); // ������ġ �ֹ� �ޱ�- �������� ������ , ���° �մ� , �������� üũ��
				ShowBaseUi(p);
				makesandwich(sand_owner, &stagecheck, stock); // ������ġ ����� ,�������� üũ�� // ���
				ShowBaseUi(p);
				checksandwich(sand_owner, (p->cusnum) - i, p->localnum);
			}
			ShowBaseUi(p);
			ShowStateReady(sand_owner, stock);
			
		}
		if (strcmp(p->title, "�ϵ�-2 �Ǹ� ��������") == 0) {

				for (int i = 1; i <= p->cusnum; i++) // �������� �մԼ� ��ŭ �ݺ�.
			{
				ShowBaseUi(p);
				checkrider(sand_owner, rider_heap, stock);
				ShowBaseUi(p);
				findrider(rider_heap, rider_table, stock, sand_owner);
				ShowBaseUi(p);
				deliversandwich(sand_owner, rider_heap, &on, stock);
				if (on == 0) {
					break;
				}
			}
			stageinit(sand_owner, p->localnum);
			ShowBaseUi(p);
			ShowStateSell(sand_owner, stock);
			
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

	Stage nomaloneready = { "���-1 �غ� ��������",NULL ,NULL,1,1 ,10};// �մԼ� ������ , �̴ϰ��� �ൿ��(���� ����)
	Stage nomalonego = { "���-1 �Ǹ� ��������",NULL ,NULL ,1,1,10};
	Stage nomaltwoready = { "���-2 �غ� ��������", NULL, NULL ,2,2,20};//�մԼ� ������, �̴ϰ��� �ൿ��
	Stage nomaltwogo = { "���-2 �Ǹ� ��������", NULL, NULL, 2, 2,20 };
	Stage hardoneready = { "�ϵ�-1 �غ� ��������",NULL ,NULL ,3,3,30};
	Stage hardonego = { "�ϵ�-1 �Ǹ� ��������",NULL ,NULL ,3,3,30};
	Stage hardtwoready = { "�ϵ�-2 �غ� ��������",NULL ,NULL ,4,4,40};
	Stage hardtwogo = { "�ϵ�-2 �Ǹ� ��������",NULL , NULL ,4,4,40};
	Stage hardone = { "�ϵ�-1 ��������", &hardoneready,&hardonego };
	Stage hardtwo = { "�ϵ�-2 ��������",&hardtwoready ,&hardtwogo };
	Stage nomalone = { "���-1 ��������",&nomaloneready ,&nomalonego };
	Stage nomaltwo = { "���-2 ��������",&nomaltwoready ,&nomaltwogo };
	Stage hard = { "�ϵ� ���̵�", &hardone,&hardtwo };
	Stage nomal = { "��� ���̵�",&nomalone , &nomaltwo};
	Stage root = { "Game_Start",&nomal ,&hard };

	Owner sand_owner;
	owner_init(&sand_owner);

	Heap rider_heapb;
	rider_init(&rider_heapb);
	Heap* rider_heap = &rider_heapb;

	OwnerStock stock;
	stock_init(&stock);

	init_hash_table(rider_table);

	rider_avail_time_init(rider_heap,rider_table);



	travel_stage(stage_stack, &root, &sand_owner, rider_heap, &stock,rider_table);// ����!!!!!!!!!!!!!!

}