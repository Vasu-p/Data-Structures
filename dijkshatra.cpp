#include <iostream>
#include<set>
#include<climits>
#include<iterator>

using namespace std;

int main()
{
    unsigned int gr[10][10];
    unsigned int i,a,b,c,j;
    unsigned int d[10]={[0..9]=INT_MAX};
    unsigned int n,e;
    std::set<int> s;
    std::set<int>::iterator it;
    cin>>n;
    cin>>e;
   // for(i=1;i<=n;i++)
     //   d[i]=INT_MAX;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        gr[i][j]=0;
    for(i=1;i<=e;i++)
    {
        cin>>a>>b>>c;
        gr[a][b]=c;
        gr[b][a]=c;
    }
    cout<<"initial vertex\n";
    cin>>a;
    d[a]=0;
    while(s.size()!=n)
    {
        unsigned int mi=INT_MAX,u;
        for(i=1;i<=n;i++)
        {
            if(d[i]<mi&&s.find(i)==s.end())
            {mi=d[i];u=i;}
        }

        s.insert(u);

        for(i=1;i<=n;i++)
        {

            if((d[u]+gr[u][i])<d[i]&&gr[u][i])
            {
                d[i]=d[u]+gr[u][i];
            }
        }
    }
    for(i=1;i<=n;i++)
        cout<<d[i]<<endl;
    return 0;
}
