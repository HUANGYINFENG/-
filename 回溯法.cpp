#include<stdio.h>
 
#define M 20
int n;
int a[M];
int cnt = 0;// ��¼ȫ���и���
 
void swap(int *a, int *b)//����a,b
{
    char t;
    t = *a;
    *a = *b;
    *b = t;
}
 
void dfs(int cur)
{
	int i;
	if(cur == n)// �ҵ� ���ȫ����
	{
		++cnt;
		for(i=0; i<n; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	else
	{
		 // �������е�����Ԫ�طֱ����һ��������������������
		// ����ʣ��Ԫ�ص�ȫ����(���õݹ�)
		for(i=cur; i<n; i++)
		{
			swap(&a[cur], &a[i]);
			dfs(cur+1);
			swap(&a[cur], &a[i]);//����
		}
	}
}
 
 
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		for(int i=0; i<n; i++)
			a[i] = i+1;// ���輯��SΪ:1 2 3 ... n
		cnt = 0;
		dfs(0);
		printf("count:%d\n", cnt);
	}
	return 0;
}
