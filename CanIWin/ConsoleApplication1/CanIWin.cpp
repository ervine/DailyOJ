// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<int> *winSet;
	bool canIWinAux(int numSet, int total) {
		int maxnum = maxNum(numSet);
		if (maxnum >= total) return true;
		if (winSet->at(numSet) != -1) return winSet->at(numSet);
		for (int num = 1; num <= maxnum; num++) {
			int mask = 1 << (num-1);
			//	skip used number
			if (!(numSet&mask)) continue;
			//	skip if take num as first choice
			if (canIWinAux((int)(numSet&(~mask)), total - num)) continue;
			//	otherwise this num is the smart choice
			winSet->at(numSet) = true;
			return true;
		}
		//	have tried every number in numSet and fail to win
		winSet->at(numSet) = false;
		return false;
	}

	//	return the maximum number avaliable in the numSet
	int maxNum(int numSet) {
		int firstBit = 0;
		while (numSet) {
			firstBit++;
			numSet >>= 1;
		}
		return firstBit;
	}


public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (desiredTotal>maxChoosableInteger*(maxChoosableInteger + 1) / 2) return false;
		if (desiredTotal <= maxChoosableInteger) return true;
		if (desiredTotal % (1 + maxChoosableInteger) == 0 && maxChoosableInteger%2==0) return false;

		//	numSet: the k-nd bit stands for number k; 1 is usable, 0 is used, -1 is unknown.
		int numSet = (1 << (maxChoosableInteger))-1;
		winSet = new vector<int>(1 << maxChoosableInteger, -1);
		return canIWinAux(numSet, desiredTotal);
	}
};

int main()
{
	Solution a;
	if (a.canIWin(20, 173))
		cout << "Yes" << endl;
	else
		cout << "NO" << endl;
	
    return 0;
}

