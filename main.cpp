#include <iostream>
#include <fstream>
#include <vector>
#include "Thread.h"

int main() {
    ifstream in("input.txt");
    if (in.is_open())
    {
        int threads_count, numbers_count;
        in >> threads_count;
        in >> numbers_count;
        int *main_array = new int[numbers_count];
        for (int i = 0; i < numbers_count; ++i)
            in >> main_array[i];
        vector<Thread*> threads;
        queue<Task*> tasks;
        auto *task = new Task;
        task->data_pointer = main_array;
        task->data_length = numbers_count;
        tasks.emplace(task);
        Thread::tasks_ = &tasks;

        Thread::threads_count_ = threads_count;
        for (int i = 0; i < threads_count; ++i)
        {
            auto *thread_ = new Thread();
            threads.push_back(thread_);
        }
        for (int i = 0; i < threads_count; ++i)
        {
            threads[i]->Exit();
            delete threads[i];
        }
        ofstream out("output.txt");
        if (out.is_open())
        {
            for (int i = 0; i < numbers_count; ++i)
            {
                out << main_array[i] << ' ';
            }
        }
    }
    return 0;
}
