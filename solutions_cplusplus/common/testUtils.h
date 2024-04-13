#include <iostream>
#include <vector>
#include <functional>

class TestUtils
{

public:
    template <typename T>
    static void totalVector(std::vector<int> &totalResult,  std::vector<T> (*func)())
    {
        std::vector<T> result = func();                                        
        totalResult.insert(totalResult.end(), result.begin(), result.end()); 
    }
};
