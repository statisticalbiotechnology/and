
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>


#include <sys/resource.h>
#include <stdio.h>


using namespace std;

float get_random()
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    return dis(e);
}

vector<float> getRandomizedFloatVector(){
    const int MAX_PSM = 25000000;
    vector<float> numbers(MAX_PSM);
    for(int i = 0 ; i < MAX_PSM; i++){
        numbers[i] = get_random();
    }
    return numbers;
}


int64_t testSort(vector<float> &numbers){
    auto t1 = std::chrono::high_resolution_clock::now();
    std::sort(numbers.begin(), numbers.end());
    auto t2 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
}

float getMBMemoryUsed(){
    struct rusage r_usage;
    getrusage(RUSAGE_SELF,&r_usage);
    return r_usage.ru_maxrss / 1000.0;
}

int main(){

    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";

    srand (static_cast <unsigned> (time(0)));
    std::vector<int64_t> times;

    float preMBMemUsed = getMBMemoryUsed();
    cout << "MB USED BEFORE PSMs: " << preMBMemUsed << endl;

    for(int i = 0 ; i < 5; i++){
        vector<float> numbers = getRandomizedFloatVector();

        float mbMemUsed = getMBMemoryUsed() - preMBMemUsed;
        cout << "MB USED: " << mbMemUsed << endl;

        int64_t milliseconds = testSort(numbers);
        times.push_back(milliseconds);
    }

    int64_t averageTime = std::accumulate(times.begin(), times.end(), 0LL) / times.size();
    std::cout << " MAX: " << *std::max_element(times.begin(), times.end()) << '\n';
    std::cout << " MIN: " << *std::min_element(times.begin(), times.end()) << '\n';
    std::cout << " AVG: " << averageTime << '\n';
    cout << "Test completed.\n";

    return 0;
}
