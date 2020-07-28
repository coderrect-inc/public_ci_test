#include <iostream>
#include <pthread.h>


int x;
int *z;

int k;


void* worker(void* unused) {
    *z = 20;
    x = rand() + (*z);
    std::cout << x << "\n";
    return nullptr;
}


void* worker2(void* unused) {
    k = rand();
    std::cout << k << "\n";
    return nullptr;
}


int main() {
    int unused;
    pthread_t th1, th2;

    pthread_create(&th1, nullptr, worker, nullptr);
    pthread_create(&th2, nullptr, worker, nullptr);

    pthread_join(th1, nullptr);
    pthread_join(th2, nullptr);

    int i;
    int j = i + 4;
    std::cout << j << "\n";

    pthread_create(&th1, nullptr, worker2, nullptr);
    pthread_create(&th2, nullptr, worker2, nullptr);

    pthread_join(th1, nullptr);
    pthread_join(th2, nullptr);

    return 0;
}

