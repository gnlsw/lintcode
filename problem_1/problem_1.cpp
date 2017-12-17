#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b)
	{
        // write your code here
        int sum = 0;
        int count = 0;
		int bit_carry = 0;
        /* process each bit */
        do{
			int bit_a = a & (1 << count);
			int bit_b = b & (1 << count);
			a = a & (~(1 << count));
			b = b & (~(1 << count));
            int bit_sum = bit_a ^ bit_b ^ bit_carry;   
			sum |= bit_sum;

			if (0 == ((bit_a & bit_b) | (bit_a & bit_carry) | (bit_b & bit_carry)))
			{
				bit_carry = 0;
			}
			else
			{
				if(count >= 31)
				{
					bit_carry = 0;
				}
				else
				{
					bit_carry = (1 << (count + 1));
				}
			}
			count++;
        }while(a != 0 || b != 0 || bit_carry != 0);

		return sum;
    }
};

class Solution_B
{
public:
	int aplusb(int a, int b)
	{
		int left = a;
		int right = b;
		int sum = 0;
		int carry = 0;
		do{
			sum = left ^ right;
			carry = (left & right) << 1;
			left = sum;
			right = carry;
		} while(carry != 0);

		return sum;
	}
};

int main()
{
	Solution s;
	s.aplusb(100 , -100);
    Solution_B s2;
	s2.aplusb(100, -100);
    
    return 0;
}
