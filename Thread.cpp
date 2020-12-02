//
// Created by kondr on 02.12.2020.
//

#include "Thread.h"

mutex Thread::mutex_;
condition_variable Thread::cond_var_;
mutex Thread::cond_mutex_;
bool Thread::notified_;
bool Thread::job_is_done_;

atomic_int Thread::waiters_ = 0;
int Thread::threads_count_ = 0;
queue<Task*> *Thread::tasks_ = nullptr;

void Thread::Exit()
{
    thread_->join();
}

void Thread::ThreadProc()
{
    while(1) {
        lock_guard<mutex> lock(mutex_);
        if (!tasks_->empty()) {
            Task task = *tasks_->front();
            delete tasks_->front();
            tasks_->pop();
            mutex_.unlock();
            PerformTask(task);
        } else {
            if (waiters_ == threads_count_ - 1){
                job_is_done_ = true;
                cond_var_.notify_all();
                break;
            }
            ++waiters_;
            unique_lock<mutex> locker(cond_mutex_);
            mutex_.unlock();
            notified_ = false;
            while(!notified_ && !job_is_done_) // от ложных пробуждений
                cond_var_.wait(locker);
            notified_ = false;
            if (job_is_done_)
                break;
        }
    }
}

void Thread::PerformTask(Task &task)
{
    int *arr = task.data_pointer;
    unsigned int len = task.data_length;
    if (task.data_length > 20)
    {
        int l = 0, r = len - 1;
        int piv = arr[(l + r) / 2];
        while (l <= r)
        {
            while (arr[l] < piv)
                l++;
            while (arr[r] > piv)
                r--;
            if (l <= r){
                int k = arr[l];
                arr[l] = arr[r];
                arr[r] = k;
                l++;
                r--;
            }
        }
        int *arr_1 = arr + l;
        auto task1 = new Task;
        auto task2 = new Task;
        task1->data_pointer = arr;
        task1->data_length = r + 1;
        task2->data_pointer = arr_1;
        task2->data_length = len - l;
        lock_guard<mutex> lock(mutex_);
        tasks_->emplace(task1);
        notified_ = true;
        cond_var_.notify_one();
        tasks_->emplace(task2);
        notified_ = true;
        cond_var_.notify_one();
    }
    else
    {
        QSort(arr, 0, len - 1);
    }
}

void Thread::QSort(int *arr, int b, int e)
{
    int l = b, r = e;
    int piv = arr[(l + r) / 2];
    while (l <= r)
    {
        while (arr[l] < piv)
            l++;
        while (arr[r] > piv)
            r--;
        if (l <= r){
            int k = arr[l];
            arr[l] = arr[r];
            arr[r] = k;
            l++;
            r--;
        }
    }
    if (b < r)
        QSort (arr, b, r);
    if (e > l)
        QSort (arr, l, e);
}