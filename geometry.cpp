#include <bits/stdc++.h>

#define sz(x) (int)(x.size())
#define debug printf
#define lp(i,a,b) for(int i = a ; i < b; i++)
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pii pair<int,int>
#define ll long long 
#define all(x) x.begin(),x.end()

using namespace std ;

template<class T>
class Point
{
	public:
		
		T x , y ;
 
		Point(){ x = y = 0 ; }
 
		Point(T a, T b)
		{
			x = a ;
			y = b ;
		}
 
		T operator % (Point other) const { return x*other.y - y*other.x ; }
		T operator * (Point other) const { return x*other.x + y*other.y ; }
		Point operator - (Point other) const { return Point(x-other.x, y-other.y) ; }
 
} ;

int main()
{
}
