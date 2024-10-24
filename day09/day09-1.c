#include <stdio.h>

//����ü ����
typedef struct {
    float x;
    float y;
    float z;
} Vector3D;

//��
Vector3D addVectors(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

//��
Vector3D subtractVectors(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

//����
float dotProduct(Vector3D v1, Vector3D v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

//����
Vector3D crossProduct(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

int main() {
    Vector3D v1 = { 1.0, 3.0, 4.0 };  // v1 = (1, 2, 3)
    Vector3D v2 = { 2.0, 4.0, 1.0 };  // v2 = (4, 5, 6)
    re:

    printf("ù��° ����(x,y,z) : %.f, %.f, %.f\n", v1.x, v1.y, v1.z);
    printf("�ι�° ����(x,y,z) : %.f, %.f, %.f\n", v2.x, v2.y, v2.z);
    printf("----------------------------\n");
    printf("1.������ ��\n2.������ ��\n3.������ ����\n4.������ ����\n5.����\n");
    printf("----------------------------\n");

    int input;
    printf("��� �Է� : ");
    scanf_s("%d", &input);

    if (input == 1) {
        //��
        Vector3D sum = addVectors(v1, v2);
        printf("������ ��: (%.f, %.f, %.f)\n", sum.x, sum.y, sum.z);
    }
    else if (input == 2) {
        //��
        Vector3D diff = subtractVectors(v1, v2);
        printf("������ ��: (%.f, %.f, %.f)\n", diff.x, diff.y, diff.z);
    }
    else if (input == 3) {
        //����
        Vector3D cross = crossProduct(v1, v2);
        printf("������ ����: (%.f, %.f, %.f)\n", cross.x, cross.y, cross.z);
    }
    else if (input == 4) {
        //����
        float dot = dotProduct(v1, v2);
        printf("������ ����: %.f\n", dot);
    }
    else if (input == 5) {
        printf("���α׷��� ���� �մϴ�.\n");
    }
    else {
        printf("���ڸ� �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���.\n");
        goto re;
    }
    return 0;
}