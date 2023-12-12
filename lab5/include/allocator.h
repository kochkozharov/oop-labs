#include <deque>
#include <iostream>
#include <memory>
#include <vector>

template <class T>
class Allocator {
   private:
    std::vector<T> _used_blocks;
    std::deque<typename std::vector<T>::iterator> _free_blocks;
    uint64_t _free_count;

   public:
    static constexpr size_t max_count = 500000;
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = std::size_t;

    Allocator() : _used_blocks(max_count), _free_blocks(max_count) {
        for (uint64_t i = 0; i < max_count; i++)
            _free_blocks[i] = _used_blocks.begin() + i;
        _free_count = max_count;
    }

    ~Allocator() {}

    template <class U>
    struct rebind {
        using other = Allocator<U>;
    };

    T *allocate(size_t n) {
        typename std::vector<T>::iterator result;
        for (size_t i = 0; i < n; ++i) {
            if (_free_count > 0) {
                result = _free_blocks[--_free_count];
            } else {
                std::cout << "allocator: No memory exception" << std::endl;
            }
        }
        return &(*result);
    }

    void deallocate(T *pointer, size_t n) {
        for (size_t i = 0; i < n; ++i) {
            typename std::vector<T>::iterator iter =
                _used_blocks.begin() +
                std::distance(_used_blocks.data(), pointer);
            _free_blocks[_free_count++] = iter;
        }
    }
    template <typename U, typename... Args>
    void construct(U *p, Args &&...args) {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) { p->~T(); }
};

template <class T, class U>
constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs) {
    return true;
}

template <typename T, typename U, size_t BLOCK_COUNT>
constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs) {
    return false;
}
