// C++ program to find rank of an element
// and k-th smallest element.
#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1000001;

/* Updates element at index 'i' of BIT. */
void update(int i, int add, vector<int>& BIT)
{
	while (i > 0 && i < BIT.size())
	{
		BIT[i] += add;
		i = i + (i & (-i));
	}
}

/* Returns cumulative sum of all elements of
fenwick tree/BIT from start upto and
including element at index 'i'. */
int sum(int i, vector<int>& BIT)
{
	int ans = 0;
    int t = i;
	while (i > 0)
	{
		ans += BIT[i];
		i = i - (i & (-i));
	}

    cout << "sum from start to " << t << " is : " << ans << '\n';
	return ans;
}

// Returns lower bound for k in BIT.
int findKthSmallest(int k, vector<int> &BIT)
{
	// Do binary search in BIT[] for given
	// value k.
	int l = 0;
	int h = BIT.size();
	while (l < h)
	{
		int mid = (l + h) / 2;
		if (k <= sum(mid, BIT))
			h = mid;
		else
			l = mid+1;
	}

	return l;
}

// Insert x into BIT. We basically increment
// rank of all elements greater than x.
void insertElement(int x, vector<int> &BIT)
{
	update(x, 1, BIT);
}

// Delete x from BIT. We basically decreases
// rank of all elements greater than x.
void deleteElement(int x, vector<int> &BIT)
{
	update(x, -1, BIT);
}

// Returns rank of element. We basically
// return sum of elements from start to
// index x.
int findRank(int x, vector<int> &BIT)
{
	return sum(x, BIT);
}

// Driver code
int main()
{
	vector<int> BIT(MAX_VAL);
	insertElement(1, BIT);
	insertElement(7, BIT);
	insertElement(8, BIT);
	insertElement(9, BIT);
	insertElement(11, BIT);
	insertElement(12, BIT);
	insertElement(13, BIT);
	insertElement(15, BIT);
	for (int i = 0; i < 100; i++)
	    cout << BIT[i] << " ";
	cout << '\n';

	int x = findKthSmallest(2, BIT);
	cout << "2nd Smallest element is " << x <<  endl;

	int r = findRank(13, BIT) ;
	cout << "Rank of 13 is " << r << endl;

	deleteElement(8, BIT);

	int z = findRank(11, BIT);
	cout << "Rank of 11 is " << z << endl;

    int zz = findRank(15, BIT);
	cout << "Rank of 11 is " << zz << endl;

	return 0;
}
