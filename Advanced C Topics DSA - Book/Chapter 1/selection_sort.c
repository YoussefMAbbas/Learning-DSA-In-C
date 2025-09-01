#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y);
void SelectionSortAsc(int list[], int size);
void SelectionSortDes(int list[], int size);

int main(void) {

  int num[] = {78, 60, 22, 19, 54, 14, 20, 24, 73, 68};

  int size = sizeof(num) / sizeof(num[0]);

  printf("Unsorted: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", num[i]);
  }

  printf("\n");

  SelectionSortAsc(num, size);

  printf("Sorted ascending: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", num[i]);
  }

  printf("\n");

  SelectionSortDes(num, size);

  printf("Sorted descending: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", num[i]);
  }

  return EXIT_SUCCESS;
}

void Swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void SelectionSortAsc(int list[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {

      if (list[i] > list[j]) {
        Swap(&list[i], &list[j]);
      }
    }
  }
}

void SelectionSortDes(int list[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {

      if (list[i] < list[j]) {
        Swap(&list[i], &list[j]);
      }
    }
  }
}
