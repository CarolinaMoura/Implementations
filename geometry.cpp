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

struct Point
{

    ll x , y ;

    Point(ll x=0, ll y=0):x(x), y(y) {}
    
    Point operator - (Point other) const { return Point(x-other.x, y-other.y) ; } 
    ll operator % (Point other) const { return x*other.y - y*other.x ; }
    ll operator *(Point other) const { return x*other.x + y*other.y ; }
    void print() { printf("%lld %lld\n" , x , y) ; }
    void read() { scanf("%lld %lld", &x, &y) ; }
    int quadrant()
    {
        if(y >= 0 && x > 0) return 1 ;
        if( y > 0 && x <= 0 ) return 2 ;
        if( y <= 0 && x < 0 ) return 3 ;
        if( y < 0 && x <= 0 ) return 4 ;
        return 5 ; //origin
    }
} ;

//To use this, the origin shall never be a valid point (or it'll end up as the last element)
bool byPolar(Point a , Point b)
{
    if(a.quadrant() != b.quadrant() ) return a.quadrant() < b.quadrant() ;
    if( a%b == 0 ) return (b-a)*( Point(0,0)-a ) < 0;
    return a%b > 0 ;
}
