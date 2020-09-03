class Solution {
public:
    string getHint(string secret, string guess) {
	//  APPROACH
        // if guess is at same loc and val its bull 
        // if guess is at diff loc then store count and then compute the min as cow

	    
        // Two arrays approach (Two pass) .
        int bull=0,cow = 0;
        vector<int> sec_cnt(10,0);
        vector<int> guess_cnt(10,0);
        for(int i=0;i<guess.size();i++)
        {
            char g = guess[i];
            char s = secret[i];
            
            if(g==s)
            {
                bull++;
            }
            else
            {
                sec_cnt[s-'0']++;
                guess_cnt[g-'0']++;
            }
           
        }
// 	    count the matching numbers only.
        for(int i=0;i<10;i++)
            cow+=min(sec_cnt[i],guess_cnt[i]);


	/*
	
			//IDEAL SOLUTION	
	//One pass solution using 1 array.
// 	vi[secret[i]-'0'] is negative only if this character appeared in the guess more times then in the secret
// 	which means that this character in the secret can be matched with one of the previous
// 	characters in the guest.	
	
	vector<int>vi(10);
	int bull=0,cows=0;
	for(int i=0;i<sz;i++) {
	   if(secret[i]==guess[i])
		 bull++;
	   else {
		if(vi[secret[i]-'0']++<0)
			cows++;
		if(vi[guess[i]-'0']-->0)
			cows++;
	    }
	}
		
	*/
	    
        return to_string(bull) + "A" + to_string(cow) + "B";
	    
//         Space - O(N)
// 	    Time - O(N).
        
    }
};