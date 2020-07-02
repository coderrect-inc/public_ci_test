#include <iostream>
#include <pthread.h>


int x;


void* worker(void* unused) {
    x = rand() + 2;
    std::cout << x << "\n";
    return nullptr;
}


int main() {
    pthread_t th1, th2;

    pthread_create(&th1, nullptr, worker, nullptr);
    pthread_create(&th2, nullptr, worker, nullptr);

    pthread_join(th1, nullptr);
    pthread_join(th2, nullptr);

    return 0;
}

