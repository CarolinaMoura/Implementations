#include <bits/stdc++.h>
 
#define all(x) x.begin(),x.end()
#define ll long long
#define sz(x) (int)(x.size() )
 
const int BASE = 2 ; //insert your base here
 
using namespace std ;
 
struct bignum
{
	vector<int> a ;
  
	void trim() 
	{
		while( sz(a) > 0 && a.back() == 0 ) a.pop_back() ;
	}
 
	bignum operator + (bignum other) const
	{
		bignum aux ;
 
		for(int i = 0 , carry = 0 ; i < max(sz(other.a), sz(a)) || carry ; i++ )
		{
			int addOther = (i >= sz(other.a) ) ? 0 : other.a[i] ;
			int addThis = (i >= sz(a) ) ? 0 : a[i] ;
 
			aux.a.push_back( addOther + addThis + carry ) ;
 
			carry = ( aux.a.back() >= BASE ) ;
 
			if(carry) aux.a.back() -= BASE ;
 
		}
 
		return aux ;
 
	}
 
	bool operator < ( bignum other ) const 
	{
		if( sz(a) != sz(other.a) ) return sz(a) < sz(other.a) ;
 
		for(int i = sz(a) - 1 ; i >= 0 ; i-- )
			if( a[i] != other.a[i] ) return a[i] < other.a[i] ;
 
	 	return false ;
	}
 
	bool operator == (bignum other) const  
	{
		return !(*this < other) && !(other < *this) ;
	}
 
	bool operator <= (bignum other) { return !(other < *this ) ; }
 
	bignum operator - (bignum other )const 
	{
		bignum aux ;
 
		for(int i = 0 ,carry=0 ; i < max(sz(a), sz(other.a) )  ; i++ )
		{
 
			int myNumber = ( i >= sz(a) ) ? 0 : a[i] ;
			int otherNumber = ( i >= sz(other.a) ) ? 0 : other.a[i] ;
 
			aux.a.push_back( myNumber - otherNumber - carry ) ;
 
			carry = ( aux.a.back() < 0 ) ;
 
			if(carry ) aux.a.back() += BASE ;
 
		}
 
		aux.trim() ;
		return aux ;
 
	}
 
} ;

int main()
{
}
