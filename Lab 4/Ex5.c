#include <stdlib.h>
#include <stdio.h>

struct Link {
  int value;
  struct Link * next;
};

typedef struct Link node;

node * push(node * head, int value) {
  node * l = malloc(sizeof(node));
  l->value = value;
  l->next = head;
  return l;
}

void print(node * head) {
  node * i = head;

  while(i != NULL) {
    if(i == head)
      printf("%d",i->value);
    else
      printf(" %d",i->value);
    i = i->next;
  }
  printf("\n");
}

node * reverse (node * head) {
  if(head->next == NULL)
    return head;
  else {
    node * newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
  }
}

int main() {

  node * head = NULL;
  head = push(head, 5);
  head = push(head, 4);
  head = push(head, 3);
  head = push(head, 2);
  head = push(head, 1);

  print(head);
  head = reverse(head);
  print(head);
}
