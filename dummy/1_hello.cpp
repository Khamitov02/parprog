#include <omp.h>
#include <iostream>
int main() {
    #pragma omp parallel
    {
        int thread_num = omp_get_thread_num(); // using omp funcs
        int num_threads = omp_get_num_threads(); // using omp funcs
        
        #pragma omp critical // эта штука нужна для избавления от конфликтов доступа к потоку вывода
        {
            std::cout << "I`m thread #" << thread_num << ". " << num_threads
                      << " threads in all. Hi World!" << std::endl;
        }
    }

    return 0;
}
