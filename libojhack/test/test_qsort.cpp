#include <cstdio>
#include <cstdlib>

// comparator for ints
static int cmp_int(const void *a, const void *b) {
  int ia = *(const int *)a;
  int ib = *(const int *)b;
  return (ia > ib) - (ia < ib);
}

int main() {
  int arr[] = {5, 3, 1, 4, 2};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  // call qsort implemented in ojhack.cpp (when included)
  qsort(arr, n, sizeof(int), cmp_int);

  // print sorted array
  for (size_t i = 0; i < n; ++i) {
    std::printf("%d ", arr[i]);
  }
  std::printf("\n");
  return 0;
}
