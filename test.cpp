#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <iostream>
#include <functional>
using namespace std;
/*
STL组件2: 仿函数 -------> 使用方式类似于函数
本质: 给类定义括号"()"运算符重载函数
STL组件3: 容器适配器
容器适配器: stack, queue, priority_queue
容器适配器都是通过适配器的设计模式实现, 不需要元素实现, 只需要对其他容器进行为此封装, 即可产生新的容器
适配器设计模式: 对接口进行转换, 使其变成另一种解接口
stack: 可以通过vector, list, deque实现
stack实现规范:
	只要容器提供了以下接口, 就可以作为stack的底层实现
	push_back   ----> push
	pop_back    -----> pop
	front     ------>   top
	empty ----->  empty
	size     -----> size
queue: 可以通过list, deque实现
queue实现规范: 默认实现为deque
	只要容器提供以下接口, 就可以作为queue的底层实现
	push_back   ---   push
	pop_front   ---   pop
	front       ---   front
	empty       ---   empty
	size        ---   size
	back        ---   back
vector没有pop front接口, 所以vector不能实现队列queue

priority_queue: 可以通过vector, deque实现
priority_queue实现规范: 默认实现为vector
	只要容器提供以下接口, 且支持随机访问, 就可以作为priority_queue底层实现
	push_back   ----   push
	pop_back    ----   pop
	front       ----   top
	empty       ----   empty
	size        ----   size
list不能实现priority_queue, 是因为其不支持随机访问
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
//仿函数：STL组件
//仿函数对象：使用方式类似于函数的对象
//通过重载括号"()"运算符完成

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
	//优先级队列，底层为堆的结构，且默认为大堆
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
	//如果需要存放自定义类型，默认需要自定义类型提供小于的比较逻辑
	//priority_queue<Date> pq;
	//如果实现小堆，需要大于的逻辑
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