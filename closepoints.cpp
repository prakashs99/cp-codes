// Finds the smallest perimeter possible by choosing 3 points from a set of points.

const double big = 1000000000000000007.0;

int n;
vector<pair<double,double> > p;
double curBest = big;

bool cmp(pair<double,double> a, pair<double,double> b) {
    return a.se < b.se;
}

double solve(int l, int r) {
    if(r-l+1<3) {
        return big;
    }
    int mid = (l+r)>>1;
    double a1 = solve(l,mid);
    double a2 = solve(mid+1,r);
    curBest = min(curBest,min(a2,a1));
    double lim = curBest;
    int i = mid;
    vector<pair<double,double> > s; s.clear();
    while(i>=l) {
        double x = p[mid].fr-p[i].fr;
        if(x > lim) break;
        s.pb(p[i]);
        i--;
    }
    i = mid+1;
    while(i<=r) {
        double x = p[i].fr-p[mid].fr;
        if(x > lim) break;
        s.pb(p[i]);
        i++;
    }
    sort(s.begin(),s.end(),cmp);
    for(int i=0;i<s.size();++i) {
        for(int j=i+1;j<s.size() && s[j].se-s[i].se<curBest;++j) {
            for(int k=j+1;k<s.size() && s[k].se-s[i].se<curBest;++k) {
                double d1 = sqrt((s[i].fr-s[j].fr)*(s[i].fr-s[j].fr)+(s[i].se-s[j].se)*(s[i].se-s[j].se));
                double d2 = sqrt((s[k].fr-s[j].fr)*(s[k].fr-s[j].fr)+(s[k].se-s[j].se)*(s[k].se-s[j].se));
                double d3 = sqrt((s[i].fr-s[k].fr)*(s[i].fr-s[k].fr)+(s[i].se-s[k].se)*(s[i].se-s[k].se));
                curBest = min(curBest,d1+d2+d3);
            }
        }
    }
    return curBest;
}
