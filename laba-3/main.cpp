#include <iostream>
#include <random>
#include <vector>
#include <set>


struct State {
    virtual bool contains(int) const = 0;
};

class DiscreteState: public State {
protected:
    const int state;

public:
    DiscreteState(int state): state(state) { }

    bool contains(int s) const override {
        return state == s; 
    }
};

class SegmentState: public State {
protected:
    const int begin, end;

public:
    SegmentState(int begin, int end): begin(begin), end(end) { }

    bool contains(int s) const override {
        return begin <= s && s <= end; 
    }
};

class SetState: public State {
protected:
    const std::set<int> states;

public:
    SetState(const std::set<int> &states): states(states) { }

    bool contains(int s) const override {
        return states.count(s) > 0;
    }
};


template<typename T1, typename T2>
class Union: public State {
private:
    T1 a;
    T2 b;
    
public:
    Union(const T1 &a, const T2 &b): a(a), b(b) {}

    bool contains(int s) const override {
        return a.contains(s) || b.contains(s);
    }
};

template<typename T1, typename T2>
class Intersection: public State {
private:
    T1 a;
    T2 b;
    
public:
    Intersection(const T1 &a, const T2 &b): a(a), b(b) {}

    bool contains(int s) const override {
        return a.contains(s) && b.contains(s);
    }
};



class ProbabilityTest {
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;
    
public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count):
        seed(seed), test_min(test_min),test_max(test_max), test_count(test_count) { }
    
    float operator()(const State &s) const {
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min,test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng))) ++good;
        return static_cast<float>(good)/static_cast<float>(test_count);
    }
};

using namespace std;

int main() {
    DiscreteState d(1);
    SegmentState s1(0,   9);
    SegmentState s2(10, 19);
    SetState ss({1, 3, 5, 7, 23, 48, 57, 60, 90, 99});
    ProbabilityTest pt(time(0), 0, 100, 100000);
    std::cout << pt(d) << std::endl;
    
    std::cout << pt(s1) << std::endl;
    std::cout << pt(s2) << std::endl;
    std::cout << pt(Union(s1, s2)) << std::endl;
    
    std::cout << pt(ss) << std::endl;

    return 0;
}
