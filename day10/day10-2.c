#include<stdio.h>
#include<stdlib.h>
#define NAME_MAX (50)

struct NODE {
	char name[NAME_MAX];
	int score, order_amount, point;
	struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(char* name, int score,int order_amount, int point) {
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_node->name, NAME_MAX, name);
	new_node->score = score;
	new_node->order_amount = order_amount;
	new_node->point = point;
	new_node->link = NULL;

	return new_node;
}

struct NODE* last_node() {
	struct NODE* cur = head;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	return cur;
}

void print_nodes() {
	struct NODE* cur = head->link;
	printf("--------------------\n");
	while (cur != NULL) {
		printf("%s : ���: %d, �ֹ���: %d, ����Ʈ: %d\n", cur->name, cur->score, cur->order_amount, cur->point);
		cur = cur->link;
	}
	printf("--------------------\n");
}

struct NODE* find_node(int value) {
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (cur->score == value)
			return cur;
		cur = cur->link;
	}
	return NULL;
}


struct NODE* find_node_insert(int score,int order_amount, int point) {
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	if (cur == NULL) return head; // ù��° ���
	while (cur != NULL) {
		if (cur->score <= score) {
			if (cur->link == NULL) return cur;
			prev = cur;
			cur = cur->link;
		}
		else if (cur->score == score && cur->order_amount <= order_amount) {
			if (cur->link == NULL) return cur;
			prev = cur;
			cur = cur->link;
		}
		else if (cur->score == score && cur->order_amount == order_amount && cur->point <= point) {
			if (cur->link == NULL) return cur;
			prev = cur;
			cur = cur->link;
		}
		else {
			return prev;
		}
	}
}

void insert_node_priority(struct NODE* new_node) {
	struct NODE* n = find_node_insert(new_node->score,new_node->order_amount,new_node->point);
	new_node->link = n->link;
	n->link = new_node;
}

int delete_node(char* name) {
	struct NODE* prev = head;
	struct NODE* cur = head->link;

	while (cur != NULL) {
		if (strcmp(name, cur->name) == 0) {
			prev->link = cur->link;
			free(cur);
			return 1;
		}
		prev = cur;
		cur = cur->link;
	}
	return 0;
}




int main() {
	head = (struct NODE*)malloc(sizeof(struct NODE));
	head->link = NULL;

	int inst;
	int iteration = 1;
	char name[NAME_MAX];
	int score, order, point;

	while (iteration) {
		printf("1. �� �߰�\n");
		printf("2. �� ����\n");
		printf("3. ���α׷� ����\n");
		printf("��� �Է� : ");
		scanf_s("%d", &inst);

		switch (inst) {
		case 1:
			printf("�� �̸�: ");
			scanf_s("%s", name, NAME_MAX);
			printf("���: ");
			scanf_s("%d", &score);
			printf("��ü �ֹ���: ");
			scanf_s("%d", &order);
			printf("����Ʈ: ");
			scanf_s("%d", &point);
			// create new node
			insert_node_priority(create_node(name, score, order, point));
			break;
		case 2:
			printf("������ �л��� �̸�: ");
			scanf_s("%s", name, NAME_MAX);
			delete_node(name);
			break;
		case 3:
		default:
			iteration = 0;
			break;
		}

		print_nodes();
	}
	return 0;
}