pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    int n1 = a.size();
    int n2 = b.size();
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    pair<int,int> result;
    int ans = INT_MAX;
    
    int i = 0;
    int j = 0;
    
    while(i < n1 && j < n2)
    {
        int minDiff = abs(a[i] - b[j]);
        
        if(minDiff < ans)
        {
            ans = minDiff;
            result = make_pair(a[i],b[j]);
        }
        if(a[i] <= b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    
    return result;
}
