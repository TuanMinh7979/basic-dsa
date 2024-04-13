
#include <vector>
#include <random>

class GenerateUtils
{
public:
    static std::vector<int> generateArrays(int max);
    static std::vector<int> randomIntVector(int num, int min, int max);
    template <typename T>
    static T randomPick( std::vector<T> &vec);
};

std::vector<int> GenerateUtils::generateArrays(int max)
{
    std::vector<int> result(max);
    for (int i = 0; i < max; i++)
    {
        result[i] = i + 1;
    }
    return result;
}

std::vector<int> GenerateUtils::randomIntVector(int num, int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);

    std::vector<int> result;
    result.reserve(num);

    for (int i = 0; i < num; ++i)
    {
        result.push_back(dis(gen));
    }

    return result;
}

template <typename T>
T GenerateUtils::randomPick( std::vector<T> &vec)
{
    // Khởi tạo một random device
    std::random_device rd;
    // Sử dụng một generator ngẫu nhiên với seed từ random device
    std::mt19937 gen(rd());

    // Chọn một chỉ số ngẫu nhiên trong phạm vi của vector
    std::uniform_int_distribution<> dis(0, vec.size() - 1);
    int index = dis(gen);

    // Trả về phần tử tại chỉ số đã chọn
    return vec[index];
}
