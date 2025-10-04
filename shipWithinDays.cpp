class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int st = *max_element(weights.begin(),weights.end()),end=0;
        for(int i:weights){
            end+=i;
        }
        int ans = 0;
        while(st<=end){
            long long mid = st+(end-st)/2;
            int tot=0,day=1;
            for(int i:weights){
                if(tot+i>mid){
                    tot=0;
                    day++;
                }
                tot+=i;
            }
            if(day<=days){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }

        }
        return ans;
    }
};
