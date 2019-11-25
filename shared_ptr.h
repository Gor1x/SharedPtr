#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include "matrix.h"
#include <algorithm>

class SharedPtr {
public:
    SharedPtr(Matrix* obj = nullptr);
    SharedPtr(const SharedPtr& other);
    SharedPtr& operator=(const SharedPtr &other);
    ~SharedPtr();

    Matrix* ptr() const;
    bool isNull() const;
    void reset(Matrix* obj = nullptr);

    Matrix* operator->() const;
    Matrix& operator*() const;

private:

    void swapWith(SharedPtr &other);

    class Storage {
    public:
        Storage(Matrix* mtx);
        ~Storage();

        void increment();
        void decrement();

        int getCounter() const;
        Matrix* getObject() const;

    private:
        Matrix *data_;
        int ref_count_;
    };

private:
    Storage *storage_;
};

#endif //SHARED_PTR_H
