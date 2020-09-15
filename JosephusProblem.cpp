#include <iostream>
using namespace std;
const int m = 3;
int main()
{
    int n, f = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        f = (f + m) % i;
    //(0 , i - 1)为一个环，结果f + 1
    cout << f + 1 << endl;
    return 0;
}
//f[i] = (f[i - 1] + n)% i;
//m 为淘汰的数, n为求有n个人玩时的情况，f[i] 为i个人玩，最后留下的人.
//https://baike.baidu.com/item/约瑟夫问题/3857719?fromtitle=%E7%BA%A6%E7%91%9F%E5%A4%AB%E7%8E%AF&fromid=348830&fr=aladdin
