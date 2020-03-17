#include <iostream>

using namespace std;

int main()
{
    {
        // 利用或操作 | 和空格将英文字符转换为小写
        char A = 'A';
        char a = A | ' ';
        cout << a << endl;
    }
    {
        // 利用与操作 & 和下划线将英文字符转换为大写
        char b = 'b';
        char B = b & '_';
        cout << B << endl;
    }
    {
        // 利用异或操作 ^ 和空格进行英文字符大小写互换
        char c = 'C' ^ ' ';
        char C = 'c' ^ ' ';
        cout << c << " " << C << endl;
    }
    {
        // 判断两个数是否异号
        int x = -1, y = 2;
        cout << boolalpha << ((x ^ y) < 0) << endl;
        //cout << noboolalpha;
    }
    {
        //消除数字 n 的二进制表示中的最后一个 1
        // n & (n - 1)
        int n = 9;
        n = n & (n - 1);
        cout << n << endl;
    }
    {
        // 计算汉明权重（Hamming Weight）
        int n = 255, cnt = 0;
        while (n != 0)
        {
            ++cnt;
            n = n & (n - 1);
        }
        cout << cnt << endl;
    }
    {
        // 判断一个数是不是 2 的指数
        int n = 64;
        bool b = (n & (n - 1)) == 0; // == 的优先级比 & 高
        cout << boolalpha << b << endl;
    }
    return 0;
}
