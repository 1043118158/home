
#include<iostream>
#include<queue>
using namespace std;


int LastRemaining_Solution(int n, int m) {
    //˼·������һ������ÿ�δӶ�����ȡ�������ڵ㣬���������ڵ㶼���뵽��β��Ȼ��ɾ���������ڵ㣬���ʣ��Ԫ�ظ���Ϊһʱ����Ҫ���Ԫ�ء�


	queue<int>q;
	for (int i = 0; i < n; ++i)
	{
		q.push(i);
	}
	int i = 0;
	while (q.size() != 1)
	{
		i++;
		if (i != m) {
			q.push(q.front());
			q.pop();
		}
		else
		{
			i = 0;
			q.pop();
		}

	}
	return q.front();
}

int main()
{
    int n, m;
    while (cin >> n)
    {
        cin >> m;
        int ret = LastRemaining_Solution(n, m);
        cout << ret<<endl;
    }
    return 0;
}