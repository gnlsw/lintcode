#include <iostream>
using std::cout;
using std::endl;

class Solution
{
public:
	long long trailingZeros(long long n)
	{
		long long count_0 = 0;
		long long count_2 = 0;
		long long count_5 = 0;
		// write your code here, try to do it without arithmetic operators
		for(long long i = 1; i <= n; i++)
		{
			cout << "i = " << i << endl;
			long long tmp = i;
			while(0 == tmp % 10)
			{
				tmp = tmp / 10;
				count_0++;
			}
			while(0 == tmp % 5)
			{
				tmp = tmp / 5;
				count_5++;
			}
		}
		
		count_0 += count_5;

		return count_0;
	}
};

class Solution_B
{
public:
	/*
	 * 计算5的个数，
	 * 5 10 15 20 25 30 35 40 45 50 55 60   每个记录包含1个5
	 * 25和50，因为位25的倍数，再记录1个5
	 */
	long long trailingZeros(long long n)
	{
		long long count = 0;
		
		for(long long var = 5; var <= n; var = var * 5)
		{
			count += n / var;
		}

		return count;
	}
};

int main()
{
	Solution s;
	s.trailingZeros(101);
	Solution_B s2;
	s2.trailingZeros(5555550000000);

	return 0;
}