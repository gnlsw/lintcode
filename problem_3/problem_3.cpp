#include <iostream>

using namespace std;

class Solution_A {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) 
	{
        // write your code here
		int count;
		if(k == 0)
		{
			count = 1;
		}
		else
		{
			count = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			int tmp = i;
			while(tmp != 0)
			{
				if(k == tmp % 10)
				{
					count++;
				}
				tmp = tmp/10;
			}
		}
		return count;
    }
};

class Solution_B {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n)
	{
		int count = 0;

		/* 计算个位的数值、左侧的数值 */
		int base = 1;
		int right_num = n % base;
		int current_digital = n % (10 * base);   // 6
		int left_num = n / (10 * base);          // 345
		/*****
		 * 计算k在个位出现的次数
		 * 比如3456，
		 * 个位出现0的可能为0000, 0010, 0020 ... 3430, 3440, 3450
		 * 个位出现3的可能为0003, 0013, 0023 ... 3433, 3443, 3453
		 * 个位出现6的可能为0006, 0016, 0026 ... 3436, 3446, 3456
		 * 个位出现8的可能为0008, 0018, 0028 ... 3438, 3448, 3458(不可用)
		 ******/
		if(current_digital > k)
		{
			count = (left_num + 1) * 1;
		}
		else if(current_digital == k)
		{
			count = left_num * 1 + (right_num + 1);
		}
		else
		{
			count = left_num * 1;
		}

		/* 计算十位出现的数值、左侧的数值和右侧的数值 */
		right_num = current_digital * base + right_num;  // 6 * 1 + 0
		base = base * 10;                             // 10
		current_digital = left_num % 10;              // 5
		left_num = left_num / 10;                     // 34
		
		/*****
		 * 比如3456,
		 * 十位出现0的可能为000*, 010*, 020* ... 330*, 340*
		 * 十位出现1的可能为001*, 011*, 021* ... 331*, 341*
		 * 十位出现5的可能为005*, 015*, 025* ... 335*, 345(0-6)
		 * 十位出现8的可能为008*, 018*, 028* ... 338*
		*/
		if(current_digital > k)
		{
			count += (left_num + 1)* base;
		}
		else if(current_digital == k)
		{
			count += left_num * base + (right_num + 1);
		}
		else
		{
			count += left_num * base;
		}

		/* 计算百位出现的数值、左侧的数值和右侧的数值 */
		right_num = current_digital * base + right_num; // 56
		base = base * 10;                             // 100
		current_digital = left_num % 10;              // 4
		left_num = left_num / 10;                     // 3

		/*****
		 * 比如3456，
		 * 百位上出现0的可能为00**, 10**, 20**, 30**
		 * 百位上出现1的可能为01**, 11**, 21**, 31**
		 * 百位上出现4的可能为05**, 15**, 25**, 34(00-56)
		 * 百位上出现8的可能为08**, 18**, 28**
		 */
		if(current_digital > k)
		{
			count += (left_num + 1) * base;
		}
		else if(current_digital == k)
		{
			count += left_num * base + (right_num + 1);
		}
		else
		{
			count += left_num * base;
		}

		/* 计算千位出现的数值、左侧的数值和右侧的数值 */
		right_num = current_digital * 100 + right_num; // 456
		base = base * 10;                              // 1000
		current_digital = left_num % 10;               // 3
		left_num = left_num / 10;                      // 0

		/*****
		 * 比如3456，
		 * 千位上出现0的可能为0***
		 * 千位上出现1的可能为1***
		 * 千位上出现3的可能为3(000 - 456)
		 * 千位上出现8的可能为
		 */
		if(current_digital > k)
		{
			count += (left_num + 1) * base;
		}
		else if(current_digital == k)
		{
			count += left_num * base + (right_num + 1);
		}
		else
		{
			count += left_num * base;
		}
	}
};

class Solution_C {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n)
	{
		if((n == 0) && (k == 0))
		{
			return 1;
		}

		/* 计算个位的数值、左侧的数值 */
		int count_sum = 0;
		int base = 1;
		int right_num = n % base;
		int current_digital = n % (10 * base);   // 6
		int left_num = n / (10 * base);          // 345

		while((left_num != 0) || (current_digital != 0))
		{
			int count;
			if(current_digital > k)
			{
				count = (left_num + 1) * base;
			}
			else if(current_digital == k)
			{
				count = left_num * base + (right_num + 1);
			}
			else
			{
				count = left_num * base;
			}

			if((k == 0) && (base != 1))
			{
				count -= base;
			}

			count_sum += count;

			// cout << "left_num = " << left_num << " current_digital = " << current_digital;
			// cout << " right_num = " << right_num << endl;
			// cout << "count = " << count << endl;

			right_num = current_digital * base + right_num;
			current_digital = left_num % 10;
			left_num = left_num / 10;
			base = base * 10;
		}

		// cout << "count_sum = " << count_sum << endl;
		return count_sum;
	}
};

int main()
{
	Solution_A s_a;
	Solution_C s_c;

	for(int n = 0; n <= 1003; n++)
	{
		for(int k = 0; k <= 9; k++)
		{
			
			int a = s_a.digitCounts(k, n);
			int b = s_c.digitCounts(k, n);
			if(a != b)
			{
				cout << "k = " << k << " n = "<< n << endl;
				cout << "a = " << a << ", b = " << b << endl;
				cout << "error" << endl;
			}
		}
		cout << "n = " << n << endl;
	}
	
	return 0;
}