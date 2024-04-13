#include <iostream>
#include <chrono>

class Timer {
public:
    // Static function to check time taken by another function
    template<typename Func, typename... Args>
    static double timeTaken(Func&& func, Args&&... args) {
        auto start = std::chrono::high_resolution_clock::now(); // Get start time

        // Call the function with provided arguments
        std::forward<Func>(func)(std::forward<Args>(args)...);

        auto end = std::chrono::high_resolution_clock::now(); // Get end time

        // Calculate the duration
        std::chrono::duration<double> duration = end - start;

        // Return the time taken in seconds
        return duration.count();
    }
    template<typename Func, typename... Args>
    static double statRs(Func&& func, Args&&... args) {
        auto start = std::chrono::high_resolution_clock::now(); // Get start time

        // Call the function with provided arguments
        std::forward<Func>(func)(std::forward<Args>(args)...);

        auto end = std::chrono::high_resolution_clock::now(); // Get end time

        // Calculate the duration
        std::chrono::duration<double> duration = end - start;

        // Return the time taken in seconds
        return duration.count();
    }
};



