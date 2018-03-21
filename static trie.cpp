struct node {
    int idx[26];
    int val;
    node(int v) {
	val = v;
	for(int i=0;i<26;++i) {
	    idx[i] = -1;
	}
    }
};

vector<node> trie;

void insert(string s, int h) {
    int cur = 0;
    for(int i=0;i<s.length();++i) {
	if(trie[cur].idx[s[i]-'a']==-1) {
	    trie.pb(node(h));
	    trie[cur].idx[s[i]-'a'] = trie.size()-1;
	    cur = trie[cur].idx[s[i]-'a'];
	}
	else {
	    cur = trie[cur].idx[s[i]-'a'];
	    trie[cur].val = max(trie[cur].val,h);
	}
    }
}

int search(string s) {
    int cur = 0;
    int mx = 0;
    for(int i=0;i<s.length();++i) {
	if(trie[cur].idx[s[i]-'a']==-1) {
	    return -1;
	}
	else {
	    cur = trie[cur].idx[s[i]-'a'];
	    mx = trie[cur].val;
	}
    }
    return mx;
}
