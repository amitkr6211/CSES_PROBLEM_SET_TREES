ll solve(vector<int> & arr1, vector<int> &arr2, int index, int prev){
        if(index==arr1.size()){
            return 0;
        }
        //index 
        // L to r : 
        if(index==0){
            ll int a=solve(arr1,arr2,index+1,arr1[index]);
            //we are trying to change 
            ll int b=INT_MAX;
            auto it=lower_bound(arr2.begin(),arr2.end(),arr1[index]);
            if(it!=arr2.begin()){
                it--;
                b=1+solve(arr1,arr2,index+1,*it);
            }
            return min(a,b);
        }
        else{
            ll int a=INT_MAX;
            ll int b=INT_MAX;
            if(arr1[index]>prev){
                a=solve(arr1,arr2,index+1,arr1[index]);
            }
            // 1 3
            //changes krne h 
            //cur el ka lower bound 
            auto it=upper_bound(arr2.begin(),arr2.end(),prev);
            if(it!=arr2.end()){
                // it--;
                if(*it<arr1[index]){
                    b=1+solve(arr1,arr2,index+1,*it);
                }
            }
            return min(a,b);
        }
    }
