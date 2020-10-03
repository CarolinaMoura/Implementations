#include <bits/stdc++.h>

#define pb push_back
#define pii pair<int,int>
#define lp(i,a,b) for(int i = a ; i < b ; i++)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pb push_back
#define ll long long  
#define mk make_pair
#define debug printf
#define sz(x) (int)(x.size())

const int MAX =1e5 + 10 ;

using namespace std ;

struct minRmq
{
	/*
		Considerations:
		* it makes minimum range queries
		* it's indexed from 0
		* just support queries [l;r] where r < n
	*/

	int n ;
	vector<int> _log ;
	vector< vector<int> > dp ;

	void initialize(vector<int> &a)
	{
		n = (int)(a.size() ) ;
		_log.resize(n+1,0) ;

		for(int i = 2 ; i <= n ; i ++ ) _log[i] = _log[i>>1]+1 ;
		dp.resize(_log[n]+1, vector<int>(n,0) ) ;

		for(int i = 0 ; i < n ; i++) dp[0][i] = a[i] ;
		for(int i = 1 ; i <= _log[n] ; i++)
			for(int j = 0 ; j+(1<<(i-1)) < n ; j++ )
				dp[i][j] = min(dp[i-1][j], dp[i-1][j+(1<<(i-1))] ) ;
	}

	int query(int l, int r )
	{
		int t = _log[r-l+1] ;
		return min(dp[t][l], dp[t][r-(1<<t)+1] ) ;
	}

};

int main() {}

