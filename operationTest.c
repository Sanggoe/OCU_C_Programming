#include <stdio.h>
int main() {

    char op;
    int x, y;

    printf("수식을 입력하시오:\n");
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
        printf("등록 되지 않은 수식입니다.\n");

    return 0;

}