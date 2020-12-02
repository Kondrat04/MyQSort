//
// Created by kondr on 02.12.2020.
//

#ifndef QSORTMODIFIED_THREAD_H
#define QSORTMODIFIED_THREAD_H

#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;

struct Task
{
    int *data_pointer;
    unsigned int data_length;
};

class Thread{
public:
    Thread()
    {
        thread_ = new thread(ThreadProc);
    }
    ~Thread()
    {
        delete thread_;
    }
    void Exit();
    static queue<Task*> *tasks_;
    static atomic_int waiters_;
    static int threads_count_;
private:
    static void ThreadProc();
    static void PerformTask(Task &task);
    static void QSort(int *arr, int b, int e);
    static mutex mutex_;
    static condition_variable cond_var_;
    static mutex cond_mutex_;
    static bool notified_;
    static bool job_is_done_;
    thread *thread_;
};

#endif //QSORTMODIFIED_THREAD_H
