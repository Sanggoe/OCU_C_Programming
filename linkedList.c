#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode { //�ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
   char data[4];
   struct ListNode* link;
} listNode;

typedef struct linkedList_h{ //����Ʈ ������ ��Ÿ���� head��带 ����ü�� ����
   listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) { //���鿬�� ����Ʈ�� �����ϴ� ����
   linkedList_h* L;
   L = (linkedList_h*)malloc(sizeof(linkedList_h));
   L->head = NULL; //���� ����Ʈ�̹Ƿ� NULL�� ����
   return L;
}

void freeLinkedList_h(linkedList_h* L) { //���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
   listNode* p;
   while (L->head != NULL) {
      p = L->head;
      L->head = L->head->link;
      free(p);
      p = NULL;
   }
}

void printList(linkedList_h* L) { //���� ����Ʈ�� ������� ����ϴ� ����
   listNode* p;
   printf("L=(");
   p = L->head;
   while (p != NULL) {
      printf("%s", p->data);
      p = p->link;
      if (p != NULL) printf(",");
   }
   printf(")\n");
}

void insertFirstNode(linkedList_h* L, char* x) {
   listNode* newNode;
   newNode = (listNode*)malloc(sizeof(listNode));
   strcpy_s(newNode->data, sizeof(newNode), x);
   newNode->link = L->head;
   L->head = newNode;
} //ù ��° ���� �����ϴ� ����

void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
   listNode* newNode;
   newNode = (listNode*)malloc(sizeof(listNode));
   strcpy_s(newNode->data, sizeof(newNode), x);
   if (L == NULL) { //���� ����Ʈ�� ���
      newNode->link = NULL; // �� ��带 ù ��°���� ������ ���� ����
      L->head = newNode;
   }
   else if (pre == NULL) { //���� ��ġ�� �����ϴ� ������ pre�� NULL�� ���
      L->head = newNode; //�� ��带 ù ��° ���� ����
   }
   else {
      newNode->link = pre->link; //������ pre�� ��� �ڿ� �� ��� ����
      pre->link = newNode;
   }
}//��带 pre �� �� �߰��� �����ϴ� ����
void insertLastNode(linkedList_h* L, char* x) {
   listNode* newNode;
   listNode* temp;

   newNode = (listNode*)malloc(sizeof(listNode));
   strcpy_s(newNode->data, sizeof(newNode), x);
   newNode->link = NULL;
   if (L->head == NULL) { //���� ����Ʈ�� ������ ���
      L->head = newNode; //�� ��带 ����Ʈ�� ���� ���� ����
      return;
   }

   temp = L->head; //���� ����Ʈ�� ������ �ƴѰ��
   while (temp->link != NULL)temp = temp->link; //���� ����Ʈ�� ������ ��带 ã��
   temp->link = newNode; //�� ��带 ������ ���(temp)�� ���� ���� ����
}//������ ���� �����ϴ� ����

listNode* searchNode(linkedList_h* L, char* x) {
   listNode* temp;
   temp = L->head;
   while (temp != NULL) {
      if (strcmp(temp->data,x) == 0)return temp;
      else temp = temp->link;
   }
   return temp;
}

int main() {
   linkedList_h* L;
   listNode* p;
   L = createLinkedList_h();
   printf("(1) ���� ����Ʈ �����ϱ�! \n");
   printList(L); getchar();

   printf("(2) ����Ʈ�� [��] ��� �����ϱ�! \n");
   insertFirstNode(L, "��");
   printList(L); getchar();

   printf("(3) ����Ʈ �������� [��] ��� �����ϱ�! \n");
   insertLastNode(L, "��");
   printList(L); getchar();

   printf("(4) ����Ʈ ù ��° ���� [��] �ڿ� [��] ��� �����ϱ�! \n");
   p = searchNode(L, "��");
   insertMiddleNode(L,p,"��");
   printList(L); getchar();

   printf("(5) ����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����! \n");
   freeLinkedList_h(L);
   printList(L); getchar();

   getchar();

   return 0;
}