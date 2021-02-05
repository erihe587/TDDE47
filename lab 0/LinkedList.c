#include<stdio.h>
#include<stdlib.h>

struct list_item {
  int value;
  struct list_item *next;
};

void append(struct list_item *first, int x) {
  while(first->next != NULL) {
    first = first->next;
  }
  struct list_item *new_item = (struct list_item *)malloc(sizeof(struct list_item));
  new_item->value = x;
  new_item->next = NULL;
  first->next = new_item;
}

void prepend(struct list_item *first, int x) {
  struct list_item *new_item = (struct list_item *)malloc(sizeof(struct list_item));
  new_item->value = x;
  new_item->next = first->next;
  first->next = new_item;
}

void print(struct list_item *first) {
  printf("\n");
  while(first->next != NULL) {
    printf("%d ",first->value);
    first = first->next;
  }
  printf("%d ", first->value);
  printf("\n");
}

void input_sorted(struct list_item *first, int x) {
  while(first->next != NULL) {
    struct list_item *temp_item;
    temp_item = first->next;
    if(x < temp_item->value){
      struct list_item *new_item = (struct list_item *)malloc(sizeof(struct list_item));
      new_item->value = x;
      new_item->next = first->next;
      first->next = new_item;
      return;
    }
    first = first->next;
  }
  append(first, x);
}

void clear(struct list_item *first) {
  struct list_item *temp_item;
  temp_item = first->next;
  first->next = NULL;
  while(temp_item != NULL){
    first = temp_item;
    temp_item = first->next;
    free(first);
  }
}

int main(int argc, char **argv) {
  struct list_item root;
  root.value = -1;
  root.next = NULL;
  append(&root, 4);
  append(&root, -2);
  append(&root, 3);
  append(&root, 5);
  append(&root, 22);
  print(&root);
  prepend(&root, 3);
  prepend(&root,-3);
  prepend(&root,20);
  print(&root);
  input_sorted(&root, -12);
  input_sorted(&root, 2);
  input_sorted(&root, 66);
  print(&root);
  clear(&root);
  print(&root);
  input_sorted(&root,2);
  append(&root, 1);
  append(&root, 2);
  append(&root, 3);
  print(&root);
  clear(&root);
  clear(&root);
  print(&root);
}
