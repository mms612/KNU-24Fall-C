#include <stdio.h>

//구조체 정의
typedef struct {
    float x;
    float y;
    float z;
} Vector3D;

//합
Vector3D addVectors(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

//차
Vector3D subtractVectors(Vector3D v1, Vector3D v2) {
    Vector3D result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

//내적
float dotProduct(Vector3D v1, Vector3D v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

//외적
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

    printf("첫번째 벡터(x,y,z) : %.f, %.f, %.f\n", v1.x, v1.y, v1.z);
    printf("두번째 벡터(x,y,z) : %.f, %.f, %.f\n", v2.x, v2.y, v2.z);
    printf("----------------------------\n");
    printf("1.벡터의 합\n2.벡터의 차\n3.벡터의 외적\n4.벡터의 내적\n5.종료\n");
    printf("----------------------------\n");

    int input;
    printf("명령 입력 : ");
    scanf_s("%d", &input);

    if (input == 1) {
        //합
        Vector3D sum = addVectors(v1, v2);
        printf("벡터의 합: (%.f, %.f, %.f)\n", sum.x, sum.y, sum.z);
    }
    else if (input == 2) {
        //차
        Vector3D diff = subtractVectors(v1, v2);
        printf("벡터의 차: (%.f, %.f, %.f)\n", diff.x, diff.y, diff.z);
    }
    else if (input == 3) {
        //외적
        Vector3D cross = crossProduct(v1, v2);
        printf("벡터의 외적: (%.f, %.f, %.f)\n", cross.x, cross.y, cross.z);
    }
    else if (input == 4) {
        //내적
        float dot = dotProduct(v1, v2);
        printf("벡터의 내적: %.f\n", dot);
    }
    else if (input == 5) {
        printf("프로그램을 종료 합니다.\n");
    }
    else {
        printf("숫자를 잘못 입력하셨습니다. 다시 입력해 주세요.\n");
        goto re;
    }
    return 0;
}