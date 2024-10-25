class SegTree{
public:
    vector<int> seg;
    
    SegTree(int n){
        seg.resize(4*n);
    }

    void buildSegTree(int idx, int lo, int hi, vector<int> &a)
    {
        if (lo == hi)
        {
            seg[idx] = a[lo];
            return;
        }

        int mid = (lo + hi) >> 1;

        buildSegTree(2 * idx + 1, lo, mid, a);
        buildSegTree(2 * idx + 2, mid + 1, hi, a);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void pointUpdate(int ind, int lo, int hi, int index, int val){
        if(lo == hi){
            seg[ind] = val;
            return;
        }

        int mid = (lo+hi)>>1;
        if(index <= mid){
            pointUpdate(2*ind+1,lo,mid,index,val);
        }else{
            pointUpdate(2*ind+2,mid+1,hi,index,val);
        }

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    int rangeQuery(int ind, int lo, int hi, int L, int R){
        //no overlap
        // lo hi L R or L R lo hi
        if(hi<L || R<lo) return 0;

        //complete overlap
        // L lo hi R
        if(lo>=L && hi<=R){
            return seg[ind];
        }

        //partial overlap
        int mid = (lo+hi)>>1;
        int left = rangeQuery(2*ind+1,lo,mid,L,R);
        int right = rangeQuery(2*ind+2,mid+1,hi,L,R);

        return left+right;
    }
};

class NumArray {
public:
    int n;
    SegTree st;
    NumArray(vector<int>& nums): st(0) {
        n = nums.size();
        st = SegTree(n);
        st.buildSegTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        st.pointUpdate(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return st.rangeQuery(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */