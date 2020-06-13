#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <iostream>
#include <functional>
using namespace std;
/*
STL���2: �º��� -------> ʹ�÷�ʽ�����ں���
����: ���ඨ������"()"��������غ���
STL���3: ����������
����������: stack, queue, priority_queue
��������������ͨ�������������ģʽʵ��, ����ҪԪ��ʵ��, ֻ��Ҫ��������������Ϊ�˷�װ, ���ɲ����µ�����
���������ģʽ: �Խӿڽ���ת��, ʹ������һ�ֽ�ӿ�
stack: ����ͨ��vector, list, dequeʵ��
stackʵ�ֹ淶:
	ֻҪ�����ṩ�����½ӿ�, �Ϳ�����Ϊstack�ĵײ�ʵ��
	push_back   ----> push
	pop_back    -----> pop
	front     ------>   top
	empty ----->  empty
	size     -----> size
queue: ����ͨ��list, dequeʵ��
queueʵ�ֹ淶: Ĭ��ʵ��Ϊdeque
	ֻҪ�����ṩ���½ӿ�, �Ϳ�����Ϊqueue�ĵײ�ʵ��
	push_back   ---   push
	pop_front   ---   pop
	front       ---   front
	empty       ---   empty
	size        ---   size
	back        ---   back
vectorû��pop front�ӿ�, ����vector����ʵ�ֶ���queue

priority_queue: ����ͨ��vector, dequeʵ��
priority_queueʵ�ֹ淶: Ĭ��ʵ��Ϊvector
	ֻҪ�����ṩ���½ӿ�, ��֧���������, �Ϳ�����Ϊpriority_queue�ײ�ʵ��
	push_back   ----   push
	pop_back    ----   pop
	front       ----   top
	empty       ----   empty
	size        ----   size
list����ʵ��priority_queue, ����Ϊ�䲻֧���������
*/
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d) const
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month < d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day < d._day)
					return true;
			}
		}
		return false;
	}

	bool operator==(const Date& d) const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator>(const Date& d) const
	{
		return !((*this < d) || (*this == d));
	}
	//private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& cout, const Date& d)
{
	cout << d._year << "-" << d._month << "-" << d._day << endl;
	return cout;
}
//�º�����STL���
//�º�������ʹ�÷�ʽ�����ں����Ķ���
//ͨ����������"()"��������

template <class T>
struct Greater
{
	bool operator()(const T& d, const T& d2)
	{
		return d > d2;
	}
};

template <class T>
struct Less
{
	bool operator()(const T& d, const T& d2)
	{
		return d < d2;
	}
};

void t()
{
	//���ȼ����У��ײ�Ϊ�ѵĽṹ����Ĭ��Ϊ���
	//priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(10);
	pq.push(100);
	pq.push(1);
	pq.push(-1);
	pq.push(5);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}

}

void t2()
{
	//�����Ҫ����Զ������ͣ�Ĭ����Ҫ�Զ��������ṩС�ڵıȽ��߼�
	//priority_queue<Date> pq;
	//���ʵ��С�ѣ���Ҫ���ڵ��߼�
	//priority_queue<Date, vector<Date>, Greater<Date>> pq;
	priority_queue<Date, vector<Date>, Less<Date>> pq;

	pq.push(Date(2020, 5, 23));
	pq.push(Date(2020, 5, 28));
	pq.push(Date(2020, 5, 2));
	pq.push(Date(2020, 5, 5));
	pq.push(Date(2020, 5, 30));

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << endl;
}

void t3()
{
	Greater<int> g;
	int a = 1, b = 2;
	int ret = g.operator()(a, b);
	ret = g(a, b);
}

void t4()
{
	stack<int, vector<int>> st;
	st.push(1);
	stack<int, list<int>> st2;
	st2.push(2);
	stack<int, deque<int>> st3;
	st3.push(3);

	queue<int, list<int>> q;
	q.push(1);
	queue<int, deque<int>> q2;
	q2.push(1);

	priority_queue<int, vector<int>> pq;
	pq.push(1);
	priority_queue<int, deque<int>> pq2;
	pq2.push(1);

	/*queue<int, vector<int>> q3;
	q3.push(1);
	q3.pop();*/
	/*priority_queue<int, list<int>> pq3;
	pq3.push(1);*/

}

int main()
{
	//t();
	//t2();
	//t3();
	t4();
	return 0;
}