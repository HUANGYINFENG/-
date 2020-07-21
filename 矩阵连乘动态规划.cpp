#include <iostream>
 
const int N=4;
 
namespace recursion
{  /*p数组存储比从start到end再多一个的数,代表着m[start][end]*/
int matrixChain(const int *p,int start,int end)
{
   if(start>=end)return 0;
   int min=65536;
   int temp=0;
   for(int i=start;i<end;i++)
   {
            temp=matrixChain(p,start,i)+matrixChain(p,i+1,end)+p[start-1]*p[i]*p[end];
    if(min>temp)min=temp;
   }
   return min;
}
 
 
};
namespace nonRecursion
{
    
   /*p代表维数数组,n代表矩阵个数 s是记录分割处的数组,m是记录最小乘次数数组,数组第0行和第0列都不用*/
void matrixChain(int *p,int n,int s[][N+1],int m[][N+1])
{
   int i,j,k;
   for(i=1;i<=n;i++)m[i][i]=0;//先是一个一个矩阵，不用乘，所以次数都为零
   for(int r=2;r<=n;r++)//以后就开始让i和j离开了，r代表他俩之间的矩阵个数包括他俩，开始是两个（就是他俩挨着）,越来越远
    for(i=1;i<=n-r+1;i++)
    {
     j=i+r-1;//j在i后面第r个 ，i 是i后面第一个
     m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];//默认从i分 就是（i）（i+1，i+2，……j）,第一次就是 （i）（j）
     s[i][j]=i;
                /*第一次不用执行这儿，因为两个两个的肯定是要在中间分就是（i）（j）如果三个三个 或更多的 那么就不一定是从第一个处（i处）分了 就要从i+1开始挨个试试了*/
     for(k=i+1;k<j;k++)
     {
      int temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
      if(temp<m[i][j])
      {
       m[i][j]=temp;
       s[i][j]=k;
      }
 
     }
 
    }
}
 
void traceBack(int i,int j,int s[][N+1])
{
   if(i==j)return ;
   traceBack(i,s[i][j],s);
   traceBack(s[i][j]+1,j,s);
   std::cout<<"(A"
        <<i
     <<"<->"
     <<"A"
     <<s[i][j]
     <<")";
   std::cout<<"*";
   std::cout<<"(A"
        <<s[i][j]+1
     <<"<->"
     <<"A"
     <<j
     <<")"
     <<std::endl;
}
 
};
 
int main()
{
 
using namespace std;
 
 
    int *p=new int[N+1];
cout<<"输入"<<N+1<<"个数:"<<endl;
for(int i=0;i<=N;i++)cin>>p[i];
 
int s[N+1][N+1],m[N+1][N+1];
nonRecursion::matrixChain(p,N,s,m);
cout<<"非递归："<<endl;
cout<<m[1][N]<<endl;
cout<<"顺序："<<endl;
nonRecursion::traceBack(1,N,s);
 
 
    cout<<"递归："<<endl;
cout<<recursion::matrixChain(p,1,N);
 
return 1;
}
