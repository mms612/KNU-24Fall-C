#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX (50)

typedef enum {
    HIGH = 1,  
    MEDIUM,    
    LOW       
} Rank;

struct NODE {
    char customerName[NAME_MAX];
    Rank rank;
    int order_amount;
    int point;
    struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(char* name, Rank score, int order_amount, int point) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy_s(new_node->customerName, NAME_MAX, name);
    new_node->rank = score;
    new_node->order_amount = order_amount;
    new_node->point = point;
    new_node->link = NULL;

    return new_node;
}

void print_nodes() {
    struct NODE* cur = head->link;
    printf("--------------------\n");
    while (cur != NULL) {
        printf("%s : ���: %d, �ֹ���: %d, ����Ʈ: %d\n",
            cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->link;
    }
    printf("--------------------\n");
}

struct NODE* find_node_insert(Rank score, int order_amount, int point) {
    struct NODE* prev = head;
    struct NODE* cur = head->link;

    if (cur == NULL) return head;

    while (cur != NULL) {
        if (cur->rank > score) {
            break;
        }
        else if (cur->rank == score && cur->order_amount < order_amount) {
            break;
        }
        else if (cur->rank == score && cur->order_amount == order_amount && cur->point < point) {
            break;
        }
        prev = cur;
        cur = cur->link;
    }
    return prev;
}

void insert_node_priority(struct NODE* new_node) {
    struct NODE* n = find_node_insert(new_node->rank, new_node->order_amount, new_node->point);
    new_node->link = n->link;
    n->link = new_node;
}

int delete_node(char* name) {
    struct NODE* prev = head;
    struct NODE* cur = head->link;

    while (cur != NULL) {
        if (strcmp(name, cur->customerName) == 0) {
            prev->link = cur->link;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->link;
    }
    return 0;
}

int update_node(char* name, Rank new_rank, int new_order_amount, int new_point) {
    struct NODE* prev = head;
    struct NODE* cur = head->link;

    while (cur != NULL) {
        if (strcmp(name, cur->customerName) == 0) {
            prev->link = cur->link;
            free(cur);

            insert_node_priority(create_node(name, new_rank, new_order_amount, new_point));
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
        printf("4. �� ���� ����\n");
        printf("��� �Է� : ");
        scanf_s("%d", &inst);

        switch (inst) {
        case 1:
            printf("�� �̸�: ");
            scanf_s("%s", name, NAME_MAX);
            printf("��� (1: HIGH, 2: MEDIUM, 3: LOW): ");
            scanf_s("%d", &score);
            printf("��ü �ֹ���: ");
            scanf_s("%d", &order);
            printf("����Ʈ: ");
            scanf_s("%d", &point);
            insert_node_priority(create_node(name, (Rank)score, order, point));
            break;
        case 2:
            printf("������ ���� �̸�: ");
            scanf_s("%s", name, NAME_MAX);
            delete_node(name);
            break;
        case 4:
            printf("������ ���� �̸�: ");
            scanf_s("%s", name, NAME_MAX);
            printf("�� ��� (1: HIGH, 2: MEDIUM, 3: LOW): ");
            scanf_s("%d", &score);
            printf("�� ��ü �ֹ���: ");
            scanf_s("%d", &order);
            printf("�� ����Ʈ: ");
            scanf_s("%d", &point);
            if (!update_node(name, (Rank)score, order, point)) {
                printf("�ش� �̸��� ���� ã�� �� �����ϴ�.\n");
            }
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