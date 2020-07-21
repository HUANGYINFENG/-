#include <iostream>
 
const int N=4;
 
namespace recursion
{  /*p����洢�ȴ�start��end�ٶ�һ������,������m[start][end]*/
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
    
   /*p����ά������,n���������� s�Ǽ�¼�ָ������,m�Ǽ�¼��С�˴�������,�����0�к͵�0�ж�����*/
void matrixChain(int *p,int n,int s[][N+1],int m[][N+1])
{
   int i,j,k;
   for(i=1;i<=n;i++)m[i][i]=0;//����һ��һ�����󣬲��óˣ����Դ�����Ϊ��
   for(int r=2;r<=n;r++)//�Ժ�Ϳ�ʼ��i��j�뿪�ˣ�r��������֮��ľ������������������ʼ�������������������ţ�,Խ��ԽԶ
    for(i=1;i<=n-r+1;i++)
    {
     j=i+r-1;//j��i�����r�� ��i ��i�����һ��
     m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];//Ĭ�ϴ�i�� ���ǣ�i����i+1��i+2������j��,��һ�ξ��� ��i����j��
     s[i][j]=i;
                /*��һ�β���ִ���������Ϊ���������Ŀ϶���Ҫ���м�־��ǣ�i����j������������� ������ ��ô�Ͳ�һ���Ǵӵ�һ������i�������� ��Ҫ��i+1��ʼ����������*/
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
cout<<"����"<<N+1<<"����:"<<endl;
for(int i=0;i<=N;i++)cin>>p[i];
 
int s[N+1][N+1],m[N+1][N+1];
nonRecursion::matrixChain(p,N,s,m);
cout<<"�ǵݹ飺"<<endl;
cout<<m[1][N]<<endl;
cout<<"˳��"<<endl;
nonRecursion::traceBack(1,N,s);
 
 
    cout<<"�ݹ飺"<<endl;
cout<<recursion::matrixChain(p,1,N);
 
return 1;
}
