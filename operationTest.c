#include <stdio.h>
int main() {

    char op;
    int x, y;

    printf("������ �Է��Ͻÿ�:\n");
    scanf_s("%d %c %d", &x, &op, 1, &y);
    printf("%d %c %d", x, op, y);


    if (op == '+')
        printf("%d\n", x + y);
    else if (op == '-')
        printf("%d\n", x - y);
    else if (op == '*')
        printf("%d\n", x * y);
    else if (op == '/')
        printf("%d\n", x / y);
    else
        printf("��� ���� ���� �����Դϴ�.\n");

    return 0;

}