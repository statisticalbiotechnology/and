
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>
#include <utility>

#include <sys/resource.h>
#include <stdio.h>

using namespace std;

class PSMDescription {;};

class ScoreHolder {
 public:
  double score, q, pep, p;
  PSMDescription* pPSM;
  int label;
  //std::vector<std::string> psms_list;

  ScoreHolder() : score(0.0), q(0.0), pep(0.0), p(0.0), label(0), pPSM(NULL) {}
  ScoreHolder(const double s, const int l, PSMDescription* psm = NULL) :
    score(s), q(0.0), pep(0.0), p(0.0), label(l), pPSM(psm) {}
  virtual ~ScoreHolder() {}

  std::pair<double, bool> toPair() const {
    return pair<double, bool> (score, label > 0);
  }

  inline bool isTarget() const { return label != -1; }
  inline bool isDecoy() const { return label == -1; }
};

inline bool operator>(const ScoreHolder& one, const ScoreHolder& other) {
  return (one.score > other.score)
;
}

inline bool operator<(const ScoreHolder& one, const ScoreHolder& other) {
  return (one.score < other.score)
;
}


float get_random()
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    return dis(e);
}

vector<ScoreHolder> getRandomizedFloatVector(){
    const int MAX_PSM = 25000000;
    vector<ScoreHolder> numbers(MAX_PSM);
    for(int i = 0 ; i < MAX_PSM; i++){
        numbers[i] = ScoreHolder(get_random(), 1);
    }
    return numbers;
}


int64_t testSort(vector<ScoreHolder> &numbers){
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

    srand (static_cast <unsigned> (time(0)));
    std::vector<int64_t> times;

    float preMBMemUsed = getMBMemoryUsed();
    cout << "MB USED BEFORE PSMs: " << preMBMemUsed << endl;

    for(int i = 0 ; i < 5; i++){
        vector<ScoreHolder> numbers = getRandomizedFloatVector();

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
