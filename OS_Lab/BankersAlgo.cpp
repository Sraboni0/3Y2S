// Banker's Algorithm
#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n, m;
	n = 5; // Number of processes
	m = 3; // Number of resources
	int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
						{ 2, 0, 0 }, // P1
						{ 3, 0, 2 }, // P2
						{ 2, 1, 1 }, // P3
						{ 0, 0, 2 } }; // P4

	int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
					{ 3, 2, 2 }, // P1
					{ 9, 0, 2 }, // P2
					{ 2, 2, 2 }, // P3
					{ 4, 3, 3 } }; // P4

	int avail[3] = { 3, 3, 2 }; // Available Resources
	int f[n],ans[n],ind=0;

	for (int i = 0; i < n; ++i){
		f[i]=0;
	}
	int need[n][m],checkSafe[n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}


	for (int k = 0; k <n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			if(f[i]==0)
			{
				int flag = 0;
				for (int j = 0; j < m; ++j)
				{
					if(need[i][j]>avail[j])
					{
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					checkSafe[i]=true;
					ans[ind++]=i;   // this is on the sequence
					for (int y = 0; y < m; ++y)
					{
						avail[y] += alloc[i][y];
					}
					f[i]=1;
				}
			}
		}
	}


	int unsafe=false;
	for (int i = 0; i < n; ++i)
	{
		if(checkSafe[i]==false)
			unsafe = true;
	}
	if (unsafe)
	{
		cout<<"Following is the Unsafe Sequence\n"<<endl;
	}
	else{
		cout<<"Following is the safe Sequence\n"<<endl;
		for (int i = 0; i < (n-1); ++i){
			cout<<"P"<<ans[i]<<"-> ";
		}
		cout<<"P"<<ans[n-1]<<endl;
	}


	return 0;
}
