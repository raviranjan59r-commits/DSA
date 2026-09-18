class Solution {
public:
	vector<int> st;

	void point_update(int i, int l, int r, int idx) {
		if (l == r) {
			st[i]++;
			return;
		}

		int mid = l + (r - l)/2;

		if (mid >= idx) {
			point_update(i*2 + 1, l, mid, idx);
		}
		else {
			point_update(i*2 + 2, mid + 1, r, idx);
		}

		st[i] = st[i*2 + 1]+st[i*2 + 2];
	}

	int Query(int i, int l, int r, int start, int end) {
		if (l>end || r<start)
			return 0;

		if (start <= l && r <= end) {
			return st[i];
		}

		int mid = l + (r - l)/2;

		return Query(i*2 + 1, l, mid, start, end)
		+ Query(i*2 + 2, mid + 1, r, start, end);
	}
    bool isIdealPermutation(vector<int>& arr) {
        int n=arr.size();
		vector<int> v=arr;
		sort(v.begin(),v.end());

		v.erase(unique(v.begin(),v.end()),v.end());

		int m=v.size();
		st.resize(4*m,0);

		long long  GlobaoInversions=0;

		for(int i=n-1;i>=0;i--){
		    int pos=lower_bound(v.begin(),v.end(),arr[i]) - v.begin();

		    GlobaoInversions+=Query(0,0,m-1,0,pos-1);

		    point_update(0,0,m-1,pos);

		}

	    long long LocalInversions=0;

        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]) LocalInversions++;
        }

        return LocalInversions==GlobaoInversions;
    }
};