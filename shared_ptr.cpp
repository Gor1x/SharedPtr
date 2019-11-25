#include "matrix.h"
#include "shared_ptr.h"


SharedPtr::SharedPtr(const SharedPtr &other)
{
    storage_ = other.storage_;
    storage_->increment();
}

SharedPtr::~SharedPtr()
{
    storage_->decrement();
    if (storage_->getCounter() == 0)
        delete storage_;
}

Matrix* SharedPtr::operator->() const
{
    return storage_->getObject();
}

bool SharedPtr::isNull() const
{
    return storage_->getObject() == nullptr;
}

SharedPtr::SharedPtr(Matrix *obj)
{
    storage_ = new Storage(obj);
}

Matrix &SharedPtr::operator*() const
{
    return *storage_->getObject();
}

SharedPtr& SharedPtr::operator=(const SharedPtr &other)
{
    if (this != &other)
    {
        SharedPtr(other).swapWith(*this);
    }
    return *this;
}

void SharedPtr::reset(Matrix *obj)
{
    *this = SharedPtr(obj);
}

Matrix *SharedPtr::ptr() const {
    return storage_->getObject();
}

void SharedPtr::Storage::decrement()
{
    ref_count_--;
}

int SharedPtr::Storage::getCounter() const
{
    return ref_count_;
}

Matrix* SharedPtr::Storage::getObject() const
{
    return data_;
}

void SharedPtr::Storage::increment()
{
    ref_count_++;
}

SharedPtr::Storage::~Storage()
{
    delete data_;
}

SharedPtr::Storage::Storage(Matrix *mtx)
{
    data_ = mtx;
    ref_count_ = 1;
}

