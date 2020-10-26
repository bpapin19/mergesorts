//
//  heap_sort.h
//  
//
//  Created by Brandon Papin on 10/18/20.
//

#ifndef heap_sort_h
#define heap_sort_h
#include "utils.h"


#endif /* heap_sort_h */

template <typename T>
class heap_sort {
private:
    static void sink(T* arr, size_t k, size_t n, const comparator<T>& comp) {
        while (2*k <= n) {
            size_t j = 2*k;
            if ((j < n) && (less(arr, j, j+1, comp))) { j++; }
            if (!less(arr, k, j, comp)) { break; }
            exchange(arr, k, j);
            k = j;
        }
    }
    
    static void swim(T* arr, size_t k, const comparator<T>& comp) {
        while ((k > 1) && (less(arr, k/2, k, comp))) {
            exchange(arr, k/2, k);
            k = k/2;
        }
    }
    
    static void exchange(T* arr, size_t i, size_t j) {
        T temp = std::move(arr[i - 1]);
        arr[i - 1] = std::move(arr[j - 1]);
        arr[j - 1] = std::move(temp);
    }
    
    static bool less(T* arr, size_t i, size_t j, const comparator<T>& comp) {
        return ::less(arr[i - 1], arr[j - 1], comp);
    }
    
public:
    static void sort(T* arr, size_t n, const comparator<T>& comp=fwd_comparator<T>()) {
        for (size_t k = n/2; k >= 1; k--) {
            sink(arr, k , n, comp);
        }
        while (n > 1) {
            exchange(arr, 1, n--);
            sink(arr, 1 , n, comp);
        }
    }
};
