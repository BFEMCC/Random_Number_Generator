#define IF_IGNORE 0
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <exception>
#if IF_IGNORE
#include <time.h>
#include <cmath>
#endif
#
using u_vector_ptr_int = std::unique_ptr<std::vector<int>>;
using u_vector_ptr_double = std::unique_ptr<std::vector<double>>;
using UNINT = unsigned int;


//using std::vector;
//using std::unique_ptr;                  //独占智能指针
//using std::random_device;               //随机种子生成器
//using std::uniform_int_distribution;    //均匀分布随机数生成器（整型）
//using std::mt19937;                     //随机数引擎之一
//using std::uniform_real_distribution;   //均匀分布随机数生成器（浮点）
//using std::normal_distribution;         //正态分布随机数生成器（浮点）
//using std::exponential_distribution;    //指数分布随机数生成器（浮点）
//using std::poisson_distribution;        //泊松分布随机数生成器（浮点）
//using std::gamma_distribution;          //伽马分布随机数生成器（浮点）


class RandomNumberGenerator : protected std::random_device, protected std::mt19937
{
public:
    RandomNumberGenerator() = default;
    RandomNumberGenerator(const RandomNumberGenerator&) = default;               //默认拷贝构造
    RandomNumberGenerator& operator=(const RandomNumberGenerator&) = default;    //默认拷贝赋值运算符
    RandomNumberGenerator(RandomNumberGenerator&& other) = default;              //默认移动构造
    RandomNumberGenerator& operator=(RandomNumberGenerator&& other) = default;   //默认移动赋值运算符
    ~RandomNumberGenerator() = default;

protected:
    UNINT CRand();

public:
    /*
        * @brief    均匀分布_整型
        * @param    最小值
        * @param    最大值
        * @param    数量
        * @return   智能指针管理的vector<int>
        */
    u_vector_ptr_int UniformDist_int(const int minRange, const int maxRange, const int quantity = 1);

    /*
        * @brief    均匀分布_浮点型
        * @param    最小值
        * @param    最大值
        * @param    数量
        * @return   智能指针管理的vector<double>
        */
    u_vector_ptr_double UniformDist_double(const double minRange, const double maxRange, const int quantity = 1);

    /*
        * @brief    正态分布_整型
        * @param    均值
        * @param    标准差
        * @param    数量
        * @return   智能指针管理的vector<int>
        */
    u_vector_ptr_int NormalDist_int(const double u, const double o, const int quantity = 1);

    /*
        * @brief    正态分布_浮点型
        * @param    均值
        * @param    标准差
        * @param    数量
        * @return   智能指针管理的vector<double>
        */
    u_vector_ptr_double NormalDist_double(const double u, const double o, const int quantity = 1);

    /*
        * @brief    指数分布_整型
        * @param    λ参数（正实数）
        * @param    数量
        * @return   智能指针管理的vector<int>
        */
    u_vector_ptr_int ExponentialDist_int(const double lambda, const int quantity = 1);

    /*
        * @brief    指数分布_浮点型
        * @param    λ参数（正实数）
        * @param    数量
        * @return   智能指针管理的vector<double>
        */
    u_vector_ptr_double ExponentialDist_double(const double lambda, const int quantity = 1);

    /*
        * @brief    泊松分布_整型
        * @param    λ参数（正实数）
        * @param    数量
        * @return   智能指针管理的vector<int>
        */
    u_vector_ptr_int PoissonDist_int(const double lambda, const int quantity = 1);

#if IF_IGNORE /*浮点泊松分布无意义*/
    /*
        * @brief    泊松分布_浮点型
        * @param    λ参数（正实数）
        * @param    数量
        * @return   智能指针管理的vector<double>
        */
    u_vector_ptr_double PoissonDist_double(const double lambda, const int quantity = 1);
#endif

    /*
        * @brief    伽马分布_整型
        * @param    形状参数
        * @param    尺度参数
        * @param    数量
        * @return   智能指针管理的vector<int>
        */
    u_vector_ptr_int GammaDist_int(const double shape, const double scale, const int quantity = 1);

    /*
        * @brief    伽马分布_浮点型
        * @param    形状参数
        * @param    尺度参数
        * @param    数量
        * @return   智能指针管理的vector<double>
        */
    u_vector_ptr_double GammaDist_double(const double shape, const double scale, const int quantity = 1);
};

using RNG = RandomNumberGenerator;