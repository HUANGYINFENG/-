#include <iostream>    
using namespace std; //�Ե����ϣ�����ѭ�������õݹ飻   
int main()  
{  
    int n = 10;  //����ľ���ĳ�ʼ����n=10
    int price[11] = { 0, 1, 7, 8, 9, 10, 17, 17, 20, 23, 24 }; //ľ���и������Ӧ�ļ۸� 
      
    int *r = new int[n + 1];  
  
    for (int k = 0; k <= n; ++k)  
        r[k] = 0;  //��ʼ��  
  
    for (int i = 1; i <= n; ++i)//��ģ����Ϊi    
    {  
        int q = INT_MIN;  
        for (int j = 1; j <= i; ++j)//�����ģΪi���������    
        {  
            if (q < (price[j] + r[i - j]))//��Ϊi>i-j�����Ե�����r[i]ʱ��r[i-j]�Ѿ����������ֱ����    
                q = (price[j] + r[i - j]);  //����q��  
        }  
        r[i] = q;  //�ҳ�i���λ�õ����Ž⣻  
    }  
    cout << r[n];  //�����n���λ�ã�����n�׳���ľͷ������ֵ��  
    delete r;  
    return 0;  
}  