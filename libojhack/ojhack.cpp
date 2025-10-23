#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <dlfcn.h>

// slow qsort
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *)) {
  for (size_t i = 0; i < nmemb; i++) {
    for (size_t j = 1; j < nmemb; j++) {
      std::swap_ranges((static_cast<char *>(base) + size * (j - 1)),
                       (static_cast<char *>(base) + size * j),
                       (static_cast<char *>(base) + size * j));
    }
  }
  static void (*real_qsort)(void *, size_t, size_t,
                            int (*)(const void *, const void *)) = nullptr;
  if (!real_qsort) {
    real_qsort = (void (*)(void *, size_t, size_t,
                           int (*)(const void *, const void *)))dlsym(RTLD_NEXT,
                                                                      "qsort");
  }
  real_qsort(base, nmemb, size, compar);
}