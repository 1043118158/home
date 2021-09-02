
#include<iostream>
#include<queue>
using namespace std;


int LastRemaining_Solution(int n, int m) {
    //思路：定义一个队列每次从队列中取出两个节点，将这两个节点都插入到队尾，然后删除第三个节点，最后当剩余元素个数为一时就是要求的元素。


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