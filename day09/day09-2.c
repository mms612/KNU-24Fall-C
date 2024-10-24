#include <stdio.h>

typedef struct {
    int productID;      
    char productName[50];  
    int price;          
} Product;


void printProduct(Product p) {
    printf("��ǰ ID: %d\n", p.productID);
    printf("��ǰ��: %s\n", p.productName);
    printf("����: %d��\n", p.price);
}

int main() {
    Product products[5];  
    int count = 0;        
    char choice;          

    while (count < 5) {
        printf("\n��ǰ ������ �Է��ϼ��� (���� ����: %d):\n", 5 - count);

        printf("��ǰ ID: ");
        scanf_s("%d", &products[count].productID);

        getchar();

        printf("��ǰ��: ");
        fgets(products[count].productName, sizeof(products[count].productName), stdin);  //scanf_s�� ������ �ȵ�
              
        printf("����: ");
        scanf_s("%d", &products[count].price);

        count++;

        if (count < 5) {
            printf("��� �Է��Ͻðڽ��ϱ�? (y/n): ");
            getchar();
            scanf_s("%c", &choice);
            if (choice == 'n' || choice == 'N') {
                break;
            }
        }
    }

    printf("\n�Էµ� ��ǰ ���:\n");
    for (int i = 0; i < count; i++) {
        printf("\n��ǰ %d:\n", i + 1);
        printProduct(products[i]);
    }

    return 0;
}