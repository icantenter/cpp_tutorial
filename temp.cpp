#include <iostream>
#include <cassert>
#include <queue>
#include <tuple>
using namespace std;
bool cmp(std::tuple<int, int> a, std::tuple<int, int> b) {
    return std::get<1>(a) < std::get<1>(b);
}
int main()
{
    std::priority_queue<std::tuple<int, int>> pq{}; 


}


