
#include <cassert>
#include "utils.h"

template <typename T>
class merge_bu_sort {
public:
    static void sort(T* arr, size_t n, const comparator<T>& comp=fwd_comparator<T>()){
        T* aux = new T[n];
        for (size_t sz = 1; sz < n; sz+=sz) {
            for (size_t low = 0; low < n - sz; low += sz + sz) {
                merge(arr, aux, low, low + sz - 1, std::min(low + sz + sz - 1, n - 1), comp);
            }
        }
    }
private:
    static void merge(T* arr, T* aux, size_t low, size_t mid, size_t high, const comparator<T>& comp){
        
        for (size_t k = low; k <= high; k++) {
            aux[k] = arr[k];
        }
        
        size_t i = low, j = mid+1;
        for (size_t k = low; k <= high; k++) {
            if (i > mid)                   { arr[k] = aux[j++]; }
            else if (j > high)             { arr[k] = aux[i++]; }
            else if (less(aux[j], aux[i], comp)) { arr[k] = aux[j++]; }
            else                           { arr[k] = aux[i++]; }
        }
    };
};
