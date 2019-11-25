#include "matrix.h"
#include "shared_ptr.h"


SharedPtr::SharedPtr(const SharedPtr &other) {

}

SharedPtr::~SharedPtr() {
    storage_->decr();
}

Matrix* SharedPtr::operator->() const {
    return storage_->getObject();
}

void SharedPtr::Storage::decr() {
    ref_count_--;
}

int SharedPtr::Storage::getCounter() const {
    return ref_count_;
}

Matrix* SharedPtr::Storage::getObject() const {
    return data_;
}

void SharedPtr::Storage::incr() {
    ref_count_++;
}

SharedPtr::Storage::~Storage() {
    delete data_;
}

SharedPtr::Storage::Storage(Matrix *mtx) {
    data_ = mtx;
    ref_count_ = 0;
}

