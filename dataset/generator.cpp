/*****************************************************
@author: reclone_rk & adarsh
*****************************************************/

#include<bits/stdc++.h>
#define MAX 9223372036854775807
#define endl "\n"
#define ll long long
#define int long long
#define double long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define ip pair<int, int>
#define F first
#define S second


#define loop(i,n) for(int i=0;i<n;i++)
#define loops(i,s,n) for(int i=s;i<=n;i++)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

const ll MOD = 1e9+7;
const ll SZ = 107;
const ll N = 1e5+7;
const ll M = 2e5+7;

std::string random_string(std::size_t length)
{
    const std::string CHARACTERS = "abcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

ll pwr(ll x, ll y, ll MO)
{
    ll r = 1LL;
    while(y)
    {
        if(y&1)
            r = (r * x) % MO;
        y >>= 1;
        x = (x * x) % MO;
    }
    return r;
}

int inv(int x)
{
	return pwr(x, MOD-2ll, MOD);
}

vector<char> alpha;

void solve()
{
	int N = 100;
	for(char i='a';i<='z';i++)
		alpha.pb(i);

	loop(i, N){
		int len = 1+rand()%10;

		string s;
        // s = random_string(len);
		for(int i=0;i<len;i++)
		{
			s += alpha[rand()%26];
		}
		cout<<s<<endl;
	}
}

signed main()
{
    #ifndef ONLINE_JUDGE
    	freopen("db.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
