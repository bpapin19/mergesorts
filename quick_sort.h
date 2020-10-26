//
//  quick_sort.h
//  
//
//  Created by Brandon Papin on 10/12/20.
//

#ifndef quick_sort_h
#define quick_sort_h
#include "utils.h"
#include "random.h"

#endif /* quick_sort_h */

template <typename T>
class quick_sort {
public:
    static const int CUTOFF = 7;
    static void sort(T* arr, size_t n, const comparator<T>& comp) {
        std_random<T>::shuffle(arr, n); // Eliminate dependence on input.
        sort(arr, 0, n - 1, comp); }
private:
    static void sort(T* arr, size_t low, size_t high, const comparator<T>& comp) {
        if (high <= low) return;
        insertion_sort<T> insert;
        if (high <= low * CUTOFF - 1) {
            insert.sort(arr, low, high, comp);
            return;
        }
        
        size_t lt = low, gt = high;
        T& value = arr[low];
        size_t i = low;
        
        while (i <= gt) {
            if (less(arr[i], value, comp)) {
                exchange(arr, lt++, i++);
            } else if (less(value, arr[i], comp)){
                exchange(arr, i, gt);
                if (gt != 0) {
                    --gt;
                }
            } else {
                ++i;
            }
            sort(arr, low, (lt == 0 ? 0: lt -1), comp);
            sort(arr, gt +1, high, comp);
        }
         int j = partition(arr, low, high); // Partition (see page 291). sort(a, lo, j-1); // Sort left part a[lo .. j-1]. sort(a, j+1, hi); // Sort right part a[j+1 .. hi].
    }
    
    static size_t partition(T* arr, size_t low, size_t high) {
        size_t i = low, j = high+1;
        T pitem = arr[low];
        while (true) {
            while (less(arr[++i], pitem)) {
                if (i == high) {
                    break;
                }
            }
            while (less(pitem, arr[--j])) {
                if (j == low) {
                    break;
                }
            }
            if ( i >= j) {
                break;
            }
        }
        exchange(arr, low, j);
        return j;
    }
};
