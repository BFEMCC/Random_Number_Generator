#include "RandomNumberGenerator.h"

int main()
{
    RNG a;
    auto vec = a.NormalDist_double(1.53, 0.47, 1000);//生成1000个正态分布的浮点数，均值为1.53，标准差为0.47

    for (auto& i : (*vec))
    {
        std::cout << i << ",";
    }

    return 0;
}