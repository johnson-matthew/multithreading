#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* function1(void *arg)
{
    for (int i = 0; i < 10; i++) {
        cout << "first thread processing " << i << endl;
        sleep(1);
    }
    return nullptr;
}

void* function2(void *arg)
{
    for (int i = 0; i < 10; i++) {
        cout << "second thread processing " << i << endl;
        sleep(1);
    }
    return nullptr;
}

int main()
{

    pthread_t mythread1;
    int retval = pthread_create(&mythread1, NULL, &function1, NULL);

    if(retval != 0) {
        cerr << "pthread_create() error: function1." << endl;
        return EXIT_FAILURE;
    }

    pthread_t mythread2;
    retval = pthread_create(&mythread2, NULL, &function2, NULL);

    if(retval != 0) {
        cerr << "pthread_create() error: function2." << endl;
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 10; i++) {
        cout << "main thread processing " << i << endl;
        sleep(1);
    }

    return 0;
}
