#ifndef max_pq_heap_h
#define max_pq_heap_h
#include <vector>

#endif /* max_pq_heap_h */

template <typename T>
class max_pq_heap {
private:
    static const size_t MIN_CAPACITY;
    std::vector<T> pq;
    size_t n = 0;
    
    void exchange(size_t i, size_t j) {
        T& temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }
    
    bool less(size_t i, size_t j, const comparator<T>& comp) {
        return less(pq[i], pq[j], comp);
    }
    
public:
    max_pq_heap(size_t capacity) : pq(capacity + 1) { }
    max_pq_heap() : max_pq_heap(MIN_CAPACITY) { }
    
    bool empty() const {
        return pq.empty();
    }
    
    void insert(const T& value, const comparator<T>& comp) {
        pq.push_back(value);
        swim(pq.size(), comp);
    }
    
    T delMax() {
        T& max = pq[1];
        size_t n = pq.size();
        
        exchange(1, n--);
        pq.pop_back();
        pq[n + 1] = T();
        sink(1);
        return max;
    }
    
    void swim(size_t k, const comparator<T>& comp) {
        while (k > 1 && less(k/2, k, comp)) {
            exchange(k, k/2);
            k = k/2;
        }
    }
    
    void sink(size_t k, const comparator<T>& comp) {
        size_t n = pq.size();
        
        while (2*k <= n) {
            size_t j = 2*k;
            if (j < n && less(j, j + 1, comp)) { j++; }
            if (!less(k, j, comp)) { break; }
            
            exchange(k, j);
            k = j;
        }
    }
};
