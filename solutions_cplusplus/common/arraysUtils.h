#include <iostream>
#include <vector>
#include <algorithm>

class ArraysUtils
{
public:
    template <typename... Args>
    static std::vector<double> sort_indices(Args... args)
    {
        std::vector<double> values = {args...}; // Convert variadic arguments to a vector

        // Create a vector of pairs (value, index)
        std::vector<std::pair<double, int>> indexed_values;
        int index = 0;
        for (auto value : values)
        {

            indexed_values.push_back(std::make_pair(value + 1, index++));
        }

        // Sort the vector of pairs based on the values
        std::sort(indexed_values.begin(), indexed_values.end());

        // Extract the sorted indices
        std::vector<double> sorted_indices;
        for (const auto &pair : indexed_values)
        {
            std::cout << "INDEX " << pair.second << "--- TIME " << pair.first << std::endl;
            sorted_indices.push_back(pair.second);
        }

        return sorted_indices;
    }

    template <typename T>
    static void info(const std::vector<T> &vec)
    {
        std::cout << "ARRAY: [ ";
        for (const auto &element : vec)
        {
            std::cout << element << ",  ";
        }
        std::cout << "]" << std::endl;
    }
    template <typename T>
    static void info(const std::vector<std::vector<T>> &vec)
    {
        std::cout << "ARRAY: [ ";
        for (std::vector<T> item : vec)
        {
            for (const T element : item)
            {
                std::cout << element << ",  ";
            }
            std::cout << std::endl;
        }
        std::cout << "]" << std::endl;
    }
};
