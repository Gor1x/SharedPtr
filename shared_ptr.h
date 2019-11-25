#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include "matrix.h"

class SharedPtr {
public:
    SharedPtr(Matrix* obj = 0);
    SharedPtr(const SharedPtr& other);
    SharedPtr& operator=(SharedPtr other);
    ~SharedPtr();

    Matrix* ptr() const;
    bool isNull() const;
    void reset(Matrix* obj = 0);

    Matrix* operator->() const;
    Matrix& operator*() const;

private:
    class Storage {
    public:
        Storage(Matrix* mtx);
        ~Storage();

        void incr();
        void decr();

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
