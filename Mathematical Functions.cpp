#include<bits/stdc++.h>
using namespace std;

#define ll long long

class MFun {
    private:
        ll N,M;
        vector<ll> fac,invfac;
    
    public:
        ll mpow(ll A,unsigned ll B){
            ll ans=1;
            A=(A%M);
            while(B){
                if(B&1){
                    ans=(ans*A)%M;
                }
                A=(A*A)%M;
                B=(B>>1LL)%M;
            }

            return ans;
        }

        ll invmod(ll A){
            return mpow(A,M-2);
        }

        MFun(ll maxn,ll mod) {
            N=maxn+69,M=mod;
            fac.assign(N,1),invfac.assign(N,{});
            for(ll i=1;i<N;i++){
                fac[i]=(fac[i-1]*i)%M;
            }

            invfac[N-1]=invmod(fac[N-1]);
            for(ll i=(N-1);i>=1;i--){
                invfac[i-1]=(invfac[i]*i)%M;
            }
        }

        ll nCr(ll N,ll R){
            if(N<0 or R<0 or N<R){
                return 0;
            }
            if(!R){
                return 1;
            }

            return (fac[N]*invfac[R]%M*invfac[N-R]%M)%M;
        }
};
