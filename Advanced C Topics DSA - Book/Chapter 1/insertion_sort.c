#include <stdio.h>
#include <stdlib.h>

void InsertionSortAsc(int list[], int start, int end);
void InsertionSortDes(int list[], int start, int end);

int main(void) {
  int num[] = {61, 14, 72, 54, 11, 15, 33, 78, 66, 59};
  int size = sizeof(num) / sizeof(num[0]);

  printf("Unsorted: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", num[i]);
  }

  printf("\n");

  InsertionSortAsc(num, 0, size);
  printf("Ascending: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", num[i]);
  }

  printf("\n");

  InsertionSortDes(num, 0, size);
  printf("Descending: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", num[i]);
  }

  return EXIT_SUCCESS;
}

void InsertionSortAsc(int list[], int start, int end) {
  for (int i = start + 1; i < end; i++) {

    int key = list[i];
    int prevIndex = i - 1;

    while (prevIndex >= 0 && key < list[prevIndex]) {
      list[prevIndex + 1] = list[prevIndex];
      list[prevIndex] = key;
      --prevIndex;
    }

    list[prevIndex + 1] = key;
  }
}

void InsertionSortDes(int list[], int start, int end) {
  for (int i = start + 1; i < end; i++) {

    int key = list[i];
    int prevIndex = i - 1;

    while (prevIndex >= 0 && key > list[prevIndex]) {
      list[prevIndex + 1] = list[prevIndex];
      list[prevIndex] = key;
      --prevIndex;
    }

    list[prevIndex + 1] = key;
  }
}
