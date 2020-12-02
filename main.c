#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>

pthread_t tids[100];
pthread_mutex_t mutex;
pthread_cond_t cond;
pthread_mutex_t cond_mutex;

int volatile *main_arr;
bool end;
int volatile task_count, waiters;
int T, N, debug1 = 0, debug2 = 0;

struct task {
    int volatile *a;
    int lena;
    struct task volatile *next;
};

struct task volatile *root, *last;

void add_task (int volatile *arr, int len){
    struct task *temp = (struct task *)malloc(sizeof(struct task));
    temp->a = arr;
    temp->lena = len;
    temp->next = NULL;

    pthread_mutex_lock(&mutex);
    if (root != NULL){
        last->next = temp;
        last = temp;
    }
    else{
        root = temp;
        last = temp;
    }
    task_count++;

    //printf("task %d", task_count);
    pthread_mutex_lock(&cond_mutex);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&cond_mutex);
    pthread_mutex_unlock(&mutex);

}

void qqsort (int volatile *arr, int b, int e)
{
    /*for (int i = b; i <= e; i++)
        printf("%d ", arr[i]);
    printf("END\n");*/
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
    //printf ("b = %d, e = %d, l = %d, r = %d\n", b, e, l, r);
    if (b < r)
        qqsort (arr, b, r);
    if (e > l)
        qqsort (arr, l, e);
}

void devide (int volatile *arr, int len){
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

    int volatile *arr_1 = arr + l;
    add_task(arr, r + 1);
    add_task(arr_1, len - l);
}

void* thread_proc(void* param){

    while (1){
        pthread_mutex_lock(&mutex);

        if (end){

            pthread_mutex_lock(&cond_mutex);

            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&cond_mutex);
            pthread_mutex_unlock(&mutex);
            break;
        }

        if (task_count == 0){

            waiters++;
            if (waiters == T){

                end = true;
                pthread_mutex_unlock(&mutex);
                continue;
            }
            pthread_mutex_lock(&cond_mutex);
            pthread_mutex_unlock(&mutex);
            pthread_cond_wait(&cond, &cond_mutex);
            pthread_mutex_unlock(&cond_mutex);
            waiters--;
            continue;
        }

        int length = root->lena;

        int volatile *temp = root->a;
        struct task volatile *del = root;
        root = root->next;
        task_count--;
        pthread_mutex_unlock(&mutex);
        free((void *)del);

        if (length > 1000){

            devide(temp, length);
            /*printf("devide ");
            printf("%d ", debug1++);*/
        }
        else{
            qqsort(temp, 0, length - 1);
            /*printf("sort ");
            printf("%d ", debug2++);*/
        }

    }
    return 0;
}

unsigned long to_ms(struct timespec* tm)
{
    return ((unsigned long) tm->tv_sec * 1000 +
            (unsigned long) tm->tv_nsec / 1000000);
}

int main(){

    pthread_mutex_init(&mutex, 0);
    pthread_mutex_init(&cond_mutex, 0);
    pthread_cond_init(&cond, 0);
    waiters = 0;
    end = false;
    task_count = 1;
    FILE *g;
    struct timespec tm_start, tm_end;

    g = fopen("input.txt", "r");
    char num_1[12];
    char num_2[12];
    char num[12];
    fscanf(g, "%s\n%s\n", num_1, num_2);
    T = atoi(num_1);
    N = atoi(num_2);
    printf("T = %d\nN = %d\n", T, N);

    main_arr = (int *)malloc(N * sizeof(int));

    for (int k = 0; k < N; k++) {
        fscanf(g, "%s ", num);
        int volatile *temp = main_arr + k;
        *temp = atoi(num);
    }
    fclose(g);

    root = (struct task *)malloc(sizeof(struct task));
    root->a = main_arr;
    root->lena = N;
    root->next = NULL;
    last = root;

    // Создание потоков
    printf("Creating threads... \n");
    for(int i = 0; i < T; i++)
        pthread_create(&tids[i], 0, thread_proc, 0);

    clock_gettime(CLOCK_REALTIME, &tm_start);
    // Ожидание завершения всех потокоv
    for(int i = 0; i < T; i++)
        pthread_join(tids[i], 0);

    clock_gettime(CLOCK_REALTIME, &tm_end);

    g = fopen("output.txt", "w");
    fprintf(g, "%s\n%s\n", num_1, num_2);
    for (int k = 0; k < N; k++) {
        if (k != N - 1)
            fprintf(g, "%d ", main_arr[k]);
        else fprintf(g, "%d", main_arr[k]);
    }
    fclose(g);

    g = fopen("time.txt", "w");
    fprintf(g, "%d", to_ms(&tm_end) - to_ms(&tm_start));
    fclose(g);

    // Освобождение памяти
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&cond_mutex);
    pthread_cond_destroy(&cond);
    free((void *)main_arr);
    //printf("All threads complete. \n");
    return 0;
}
