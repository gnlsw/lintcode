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

int main()
{
	Solution_A s_a;
	cout << s_a.digitCounts(0, 12) << endl;
	return 0;
}