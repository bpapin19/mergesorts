#include "utils.h"

template <typename T>
class merge_sort {
public:
    static void sort(T* arr, size_t n, const comparator<T>& comp=fwd_comparator<T>()){
        T* aux = new T[n];
        sort(arr, aux, 0, n-1, comp);
    }
private:
 static const int CUTOFF = 7;
    static void sort(T* arr, T* aux, size_t low, size_t high, const comparator<T>& comp) {
        if (high <= low) { return; }
        insertion_sort<T> insert;
        if (high <= low+CUTOFF-1) {
            insert.sort(arr, low, high, comp);
            return;
        }
        
        size_t mid = low + (high-low)/2;
        sort(arr, aux, low, mid, comp);
        sort(arr, aux, mid+1, high, comp);
        merge(arr, aux, low, mid, high, comp);
    }
    static void merge(T* arr, T* aux, size_t low, size_t mid, size_t high, const comparator<T>& comp){
        for (size_t k = low; k <= high; k++) {
            aux[k] = arr[k];
        }
        size_t i = low, j = mid+1;
        for (size_t k = low; k <= high; k++) {
            if (i > mid)                   { arr[k] = aux[j++]; }
            else if (j > high)             { arr[k] = aux[i++]; }
            else if (less(aux[j], aux[i])) { arr[k] = aux[j++]; }
            else                           { arr[k] = aux[i++]; }
        }
    };
};
