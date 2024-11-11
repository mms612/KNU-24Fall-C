#include<stdio.h>
#include<stdlib.h>
#define NAME_MAX (50)

struct NODE {
	char name[NAME_MAX];
	int score;
	struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(char* name, int score) {
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_node->name, NAME_MAX, name);
	new_node->score = score;
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
		printf("%s : %d\n", cur->name, cur->score);
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

struct NODE* find_node_insert(int score) {
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	if (cur == NULL) return head; // 첫번째 노드
	while (cur != NULL) {
		if (cur->score >= score) {
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
	struct NODE* n = find_node_insert(new_node->score);
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
	int score;

	while (iteration) {
		printf("1.학생 성적 입력\n");
		printf("2. 학생 정보 제거\n");
		printf("3. 프로그램 종료\n");
		printf("명령 입력 : ");
		scanf_s("%d", &inst);

		switch (inst) {
		case 1:
			printf("학생 이름: ");
			scanf_s("%s", name, NAME_MAX);
			printf("점수: ");
			scanf_s("%d", &score);
			// create new node
			insert_node_priority(create_node(name, score));

			break;
		case 2:
			printf("삭제할 학생의 이름: ");
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