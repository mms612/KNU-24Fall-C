#include <stdio.h>

typedef struct {
    int productID;      
    char productName[50];  
    int price;          
} Product;


void printProduct(Product p) {
    printf("상품 ID: %d\n", p.productID);
    printf("상품명: %s\n", p.productName);
    printf("가격: %d원\n", p.price);
}

int main() {
    Product products[5];  
    int count = 0;        
    char choice;          

    while (count < 5) {
        printf("\n상품 정보를 입력하세요 (남은 개수: %d):\n", 5 - count);

        printf("상품 ID: ");
        scanf_s("%d", &products[count].productID);

        getchar();

        printf("상품명: ");
        fgets(products[count].productName, sizeof(products[count].productName), stdin);  //scanf_s로 실행이 안됨
              
        printf("가격: ");
        scanf_s("%d", &products[count].price);

        count++;

        if (count < 5) {
            printf("계속 입력하시겠습니까? (y/n): ");
            getchar();
            scanf_s("%c", &choice);
            if (choice == 'n' || choice == 'N') {
                break;
            }
        }
    }

    printf("\n입력된 상품 목록:\n");
    for (int i = 0; i < count; i++) {
        printf("\n상품 %d:\n", i + 1);
        printProduct(products[i]);
    }

    return 0;
}