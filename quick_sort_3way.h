//
//  quick_3way_sort.h
//  
//
//  Created by Brandon Papin on 10/12/20.
//

#ifndef quick_sort_3way_h
#define quick_sort_3way_h
#include "utils.h"
#include "random.h"

#endif /* quick_3way_sort_h */

template <typename T>
class quick_sort_3way {
public:
    static void sort(T* arr, size_t n, const comparator<T>& comp=fwd_comparator<T>() ) {
        std_random<T>::shuffle(arr, n); // Eliminate dependence on input.
        sort(arr, 0, n - 1, comp);
    }
private:
    static void sort(T* arr, size_t low, size_t high, const comparator<T>& comp) {
        if (high <= low) return;
        size_t lt = low, i = low+1, gt = high;
        T pitem = arr[low];
        while (i <= gt) {
            int cmp = compare(arr[i], pitem, comp);
            if (cmp < 0) {
                exchange(arr, lt++, i++);
            } else if (cmp > 0) {
                exchange(arr, i, gt--);
            } else {
                i++;
            }
        }
        sort(arr, low, lt - 1, comp);
        sort(arr, gt + 1, high, comp);
    }
};
