
    #include<bits/stdc++.h>
    #include<vector>
    #include<map>
    #define MOD 1000000007
    using namespace std;
     
    #define lli long long int


 int n;
 int queen[20];//queen[i] ->where is my queen in row i.
 bool check(int row,int col)
 {
    for(int i=0;i<row;i++)
    {
        int prow=i;
        int pcol=queen[i];
        if(pcol==col || (abs(col-pcol)==abs(row-prow)))
        {
            return 0;
        }
    }
    return 1;
 }
 int rec(int level)// rec->number of ways  to populate [level...n-1]
 {
    //level->row in which we are placing the queen

    //pruing
    //basecase
    if(level==n)
    {
        return 1;
    }
    //compute
    int ans=0;
    //loop over all choices
    for(int col=0;col<n;col++)
    {
     if(check(level,col))
     {// palce the queen
       queen[level]=col;
    // explore the options
      ans+= rec(level+1);
    // revert placing the queen
       queen[level]=-1;
     }
    }
//return
    return ans;

 }
 void solve()
 {
    cin>>n;
    memset(queen,-1,sizeof(queen));
    cout<<rec(0)<<endl;


 }

   
    int main()
    {
         ios_base::sync_with_stdio(false);
         
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
          
          
      


     



     
    

   
          
     

     
     
     
     
     
     

    return 0;
    }