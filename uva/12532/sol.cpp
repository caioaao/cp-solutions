#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXN 110
#define MAXM 110000

#define INF (MAXN * 4110)

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

class RMQ {
private:
    struct Int_ {
        char val;
        Int_() {
            val = '0';
        }
        Int_(char val_) {
            val = val_;
        }
        Int_(int orig) {
            if(orig < 0) val = '-';
            if(orig > 0) val = '+';
            if(orig == 0) val = '0';
        }

        Int_ operator* (const Int_& rhs) const {
            if(val == '0' || rhs.val == '0') return Int_('0');
            else if(val == '-' && rhs.val == '-') return Int_('+');
            else if(val == '-' || rhs.val == '-') return Int_('-');
            else return Int_('+');
        }
    };

    vector<int> v_;
    vector<Int_> st_;
    int n_;
    void build_(int u, int l, int r) {
        if(l == r) st_[u] = Int_(v_[l]);
        else {
            build_(cl_(u), l, (l + r) / 2);
            build_(cr_(u), (l + r) / 2 + 1, r);
            st_[u] = st_[cl_(u)] * st_[cr_(u)];
        }
    }

    Int_ query_(int u, int l, int r, int i, int j) {
        if(l > j || r < i) return Int_('+');
        else if(l >= i && r <= j) return st_[u];
        else {
            return query_(cl_(u), l, (l + r)/2, i, j)
                * query_(cr_(u), (l + r)/2 + 1, r, i, j);
        }
    }

    void update_(int u, int l, int r, int k, Int_ v) {
        if(l > k || r < k) return ;
        else if (l == r) st_[u] = v;
        else {
            update_(cl_(u), l, (l + r)/ 2, k, v);
            update_(cr_(u), (l + r)/ 2 + 1, r, k, v);
            st_[u] = st_[cl_(u)] * st_[cr_(u)];
        }
    }

    inline int cl_(const int u) { return u * 2; }
    inline int cr_(const int u) { return u * 2 + 1; }
public:
    RMQ(){}
    RMQ(const vector<int>& v) {
        init(v);
    }

    void init(const vector<int>& v) {
        v_ = v;
        n_ = v.size();
        st_.assign(v.size() * 8, Int_());
        build_(1, 0, n_ - 1);
    }

    char query(int i, int j) {
        return query_(1, 0, n_ - 1, i, j).val;
    }

    void update(int k, int v) {
        update_(1, 0, n_ - 1, k, Int_(v));
    }
};

RMQ rmq;

vector<int> vals;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    while(cin >> n >> k) {
        vals.assign(n, 0);
        for(int i = 0; i < n; ++i) cin >> vals[i];
        rmq.init(vals);

        while(k--) {
            char cmd;
            cin >> cmd;

            if(cmd == 'C') {
                int k, v;
                cin >> k >> v;
                --k;
                rmq.update(k,v);
            }
            else {
                int a, b;
                cin >> a >> b;
                --a, --b;
                //for(int i = 0; i < n; ++i) cout << rmq.query(i,i) << ' ';
                cout << rmq.query(a, b);
            }
        }
        cout << '\n';
    }
}
