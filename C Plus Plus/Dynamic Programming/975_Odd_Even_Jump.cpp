// Explanation of the problem:
// 1. Odd and even here refer to the 1st jump (odd jump) 2nd jump (even jump) 3rd jump (odd jump again) and so on.
// 2. We only jump forward always
// 3. We need to return how many indexes can actually reach the end.
// 4. We assume that last position is reachable from an odd and even jump.

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n  = A.size(), res = 1;
        vector<int> higher(n), lower(n);
        higher[n-1] = lower[n-1] = 1;
        map<int,int> mp;
        mp[A[n-1]] = n-1;
        for(int i=n-2;i>=0;i--)
        {
            // lower bound gives no>= of A[i]
            auto next_higher = mp.lower_bound(A[i]);

            // upper bound gives no> of A[i] . so next_lower-- gives no that is less than equal to val.

            auto next_lower = mp.upper_bound(A[i]);

            if(next_higher!=mp.end())
                higher[i] = lower[next_higher->second];

            // we check for begin as we have to decrement to get no<=A[i]
            if(next_lower!=mp.begin())
                lower[i] = higher[(--next_lower)->second];

            // increment on higher as we start from an odd number
            if(higher[i])
            {
		//Increment res for higher (Odd jump).
                res++;
            }
                mp[A[i]] = i;
        }
        return res;
    }
};