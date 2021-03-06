//constructor
//default (1)
//explicit list(const allocator_type& alloc = allocator_type());
//fill(2)
//explicit list(size_type n);
//list(size_type n, const value_type& val,
//	const allocator_type& alloc = allocator_type());
//range(3)
//template <class InputIterator>
//list(InputIterator first, InputIterator last,
//	const allocator_type& alloc = allocator_type());
//copy(4)
//list(const list& x);
//list(const list& x, const allocator_type& alloc);
//move(5)
//list(list&& x);
//list(list&& x, const allocator_type& alloc);
//initializer list(6)
//list(initializer_list<value_type> il,
//	const allocator_type& alloc = allocator_type());
#include<iostream>
#include<list>
#include<array>
using namespace std;
int main()
{
	list<int> first_list;
	list<int> second_list(3, 100);
	list<int> third_list = { 1,2,3 };
	list<int> fourth_list(third_list.begin(), third_list.end());
	list<int> fifth_list(fourth_list);

	int  ints[] = { 0, 8, 11 };
	list<int> sixth_list(ints, ints + sizeof(ints) / sizeof(int));
	for (const int&x : sixth_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//0 8 11

//函数签名
//copy(1)
//list& operator= (const list& x);
//move(2)
//list& operator= (list&& x);
//initializer list(3)
//list& operator= (initializer_list<value_type> il);
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list(3);
	list<int> second_list(5);
	second_list = first_list;
	first_list = list<int>();
	cout << "first_list's size is " << first_list.size() << endl;
	cout << "second_list's size is " << second_list.size() << endl;
	cout << endl;
	return 0;
}
//输出：
//first_list's size is 0
//second_list's size is 3

//函数签名
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
//iterator end() noexcept;
//const_iterator end() const noexcept;
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list = { 1,2,3,4,5 };
	for (const int &x : first_list)
		cout << x <<" ";
	cout << endl;
	return 0;
}
//输出：
//1 2 3 4 5

//函数签名
//reverse_iterator rbegin() noexcept;
//const_reverse_iterator rbegin() const noexcept;
//reverse_iterator rend();
//const_reverse_iterator rend() const;
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list = { 1,2,3,4,5 };
	for (auto it = first_list.rbegin(); it != first_list.rend(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//5 4 3 2 1

//函数签名
//const_iterator cbegin() const noexcept;
//const_iterator cend() const noexcept;
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list = { 1,2,3,4,5 };
	for (auto it = first_list.cbegin(); it != first_list.cend(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//1 2 3 4 5

//函数签名
//const_reverse_iterator crbegin() const noexcept;
//const_reverse_iterator crend() const noexcept;
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list = { 1,2,3,4,5 };
	for (auto it = first_list.crbegin(); it != first_list.crend(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
//输出：
//5 4 3 2 1

//函数签名
//bool empty() const noexcept;
//size_type size() const noexcept;
//size_type max_size() const noexcept;
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list =list<int>();
	if (first_list.empty())
		cout << "first_list is empty " << endl;
	else
		cout << "first_list isn't empty " << endl;
	first_list.push_back(1);
	cout << "first_list's size is " << first_list.size() << endl;
	cout << "first_list's maxsize is " << first_list.max_size() << endl;
	

	return 0;
}
//输出：
//first_list is empty 
//first_list's size is 1
//first_list's maxsize is 768614336404564650

//函数签名
//reference front();
//const_reference front() const;
//reference back();
//const_reference back() const;
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list = { 1,2,3 };
	first_list.back() += first_list.front();
	for (const int &x : first_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出 1 2 4

//函数签名
//range(1)
//template <class InputIterator>
//void assign(InputIterator first, InputIterator last);
//fill(2)
//void assign(size_type n, const value_type& val);
//initializer list(3)
//void assign(initializer_list<value_type> il);
#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
	vector<int> vi = { 1,2,3 };
	list<int> first_list(vi.begin(), vi.end());
	list<int> second_list(3, 1);
	int  a[] = { 2,2,2 };
	list<int> third_list(a,a+3);
	for (const int& x : first_list)
		cout << x << " ";
	cout << endl;
	for (const int& x : second_list)
		cout << x << " ";
	cout << endl;
	for (const int& x : third_list)
		cout << x << " ";
	cout << endl;

	return 0;
}
//输出：
//1 2 3
//1 1 1
//2 2 2

//函数签名
//template <class... Args>
//void emplace_front(Args&&... args);
//template <class... Args>
//void emplace_back(Args&&... args);
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<pair<int, char>> first_list;
	first_list.emplace_front(1, 'a');
	first_list.emplace_front(2, 'b');
	first_list.emplace_front(3, 'c');
	first_list.emplace_back(1, 'a');
	first_list.emplace_back(2, 'b');
	first_list.emplace_back(3, 'c');
	for (auto &x : first_list)
		cout << x.first << " " << x.second << endl;
	return 0;
}
//输出：
//3 c
//2 b
//1 a
//1 a
//2 b
//3 c

//函数签名
//void push_front(const value_type& val);
//void push_front(value_type&& val);
//void push_back(const value_type& val);
//void push_back(value_type&& val);
//void pop_front();
//void pop_back();
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list;
	first_list.push_front(1);
	first_list.push_front(2);
	first_list.push_front(3);		//3 2 1

	first_list.push_back(1);
	first_list.push_back(2);
	first_list.push_back(3);		//3 2 1 1 2 3

	while (!first_list.empty())
	{
		cout << first_list.front() << endl;
		cout << first_list.back() << endl;
		first_list.pop_front();
		first_list.pop_back();
	}
	return 0;
}
//输出：
//3
//3
//2
//2
//1
//1

//函数签名
//template <class... Args>
//iterator emplace(const_iterator position, Args&&... args);
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list{ 1,2,3,4,5 };
	first_list.emplace(first_list.begin(), 0);
	for (const auto& x : first_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//0 1 2 3 4 5

//函数签名
//single element(1)
//iterator insert(const_iterator position, const value_type& val);
//fill(2)
//iterator insert(const_iterator position, size_type n, const value_type& val);
//range(3)
//template <class InputIterator>
//iterator insert(const_iterator position, InputIterator first, InputIterator last);
//move(4)
//iterator insert(const_iterator position, value_type&& val);
//initializer list(5)
//iterator insert(const_iterator position, initializer_list<value_type> il);
#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main()
{
	int a[] = { 0,0,0 };
	list<int> first_list{ 1,2,3 };
	vector<int> first_vector{ 4,5,6 };
	auto it=first_list.begin();
	it = first_list.insert(it, 0);		//现在it指向0，即第一个新插入的元素
	cout << *it << endl;
	it = first_list.insert(it, first_vector.begin(), first_vector.end());  //现在it指向4，即第一个新插入的元素
	cout << *it << endl;
	it++;
	it++;		//现在it指向6
	it = first_list.insert(it,3,9);		//现在it指向第一个9
	first_list.insert(it, a, a + 3);
	for (const auto& x : first_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//0
//4
//4 5 0 0 0 9 9 9 6 0 1 2 3

//函数签名
//iterator erase(const_iterator position);
//iterator erase(const_iterator first, const_iterator last);
//void swap(list& x);
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list{ 1,2,3,4,5 };
	list<int> second_list{ 6,7,8,9,10 };
	auto it1 = first_list.begin();
	it1++;
	it1=first_list.erase(it1);	//现在it1指向3
	cout << *it1 << endl;		
	auto it2 = second_list.begin();
	it2++;
	it2++;						//现在it2指向8
	//auto it3 = second_list.end();
	//it3--;
	it2=second_list.erase(it2, --second_list.end());		//现在it2指向10,erase删除的范围为[first,last)
	cout << *it2 << endl;
	first_list.swap(second_list);
	cout << *it1 << endl;				//执行完swap后迭代器依然指向原来的元素
	cout << *it2 << endl;
	for (const auto& x : first_list)
		cout << x << " ";
	for (const auto& x : second_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//3
//10
//3
//10
//6 7 10 1 3 4 5

//函数签名
//void resize(size_type n);
//void resize(size_type n, const value_type& val);
//void clear() noexcept;
#include<iostream>
#include<list>
using namespace std;
int main()
{
	//n小于当前list的size,则丢弃大于size部分的元素
	list<int> first_list{ 1,2,3,4,5 };
	first_list.resize(3);		//丢弃4，5
	//n大于当前list的size,如果给了第二个参数val，则用val补齐，若没给第二个参数，则用默认实例化的值填充
	first_list.resize(5,1);		//现在是1 2 3 1 1
	first_list.resize(6);		//现在是1 2 3 1 1 0
	for (const auto& x : first_list)
		cout << x << " ";
	cout << endl;
	first_list.clear();
	cout << first_list.size() << endl;
	return 0;
}
//输出：
//1 2 3 1 1 0
//0

//函数签名
//entire list(1)
//void splice(const_iterator position, list& x);
//void splice(const_iterator position, list&& x);
//single element(2)
//void splice(const_iterator position, list& x, const_iterator i);
//void splice(const_iterator position, list&& x, const_iterator i);
//element range(3)
//void splice(const_iterator position, list& x,
//	const_iterator first, const_iterator last);
//void splice(const_iterator position, list&& x,
//	const_iterator first, const_iterator last);
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list{ 1,2,3,4 };
	list<int> second_list{ 5,6,7,8 };
	auto it = first_list.begin();
	it++;		//it指向2

	first_list.splice(it, second_list);		//现在first_list为1 5 6 7 8 2 3 4，second_list为空，it依旧指向2

	second_list.splice(second_list.begin(), first_list, it);	//现在first_list为1 5 6 7 8 3 4，second_list为2，it现在无效了
	it = first_list.begin();
	advance(it, 3);							//现在it指向7了
	first_list.splice(first_list.begin(), first_list, it, first_list.end()); //现在first_list为7 8 3 4 1 5 6 
	for (const int& x : first_list)
		cout << x << " " ;
	cout << endl;
	for (const int& x : second_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//7 8 3 4 1 5 6
//2

//函数签名
//void remove(const value_type& val);
//template <class Predicate>
//void remove_if(Predicate pred);
//(1)
//void unique();
//(2)
//template <class BinaryPredicate>
//void unique(BinaryPredicate binary_pred);
#include<iostream>
#include<list>
#include<set>
#include<algorithm>
using namespace std;
bool single_digit(const int& value)
{
	return value < 10;
}
struct is_odd
{
	bool operator()(const int &value)
	{
		return (value % 2 == 1);
	}
};
int main()
{
	list<int> first_list{ 15,41,25,1,2,41,2,3,42,2,41 };	
	first_list.remove(2);				//移除所有值等于2的元素，现在first_list为{ 15，41，25，1，41，3，42，41 }
	for (const int &x : first_list)
		cout << x << " ";
	cout << endl;
	first_list.remove_if(single_digit);		//移除所有值小于10的元素，现在first_list为{ 15，41，25，41，42，41 }
	for (const int &x : first_list)
		cout << x << " ";
	cout << endl;
	first_list.remove_if(is_odd());		//移除所有值为奇数的元素，现在first_list为{ 42 }
	for (const int &x : first_list)
		cout << x << " ";
	cout << endl;

	list<int> second_list{ 1,1,2,3,3,3,5,5,4,1,1,1 };
	second_list.unique();			//unique移除连续相同元素中非第一个元素，现在second_list为{ 1，2，3，5，4，1 }
	for (const int &x : second_list)
		cout << x << " ";
	cout << endl;
	//如果要使列表按顺序排列并且无相同元素
	list<int> third_list{ 1,1,2,3,3,3,5,5,4,1,1,1 };
	list<int> forth_list(third_list.begin(),third_list.end());
	//方法一
	third_list.sort();
	third_list.unique();
	for (const int &x : third_list)
		cout << x << " ";
	cout << endl;
	//方法二
	set<int> my_set(forth_list.begin(), forth_list.end());
	forth_list.resize(0);
	for (const int& x : my_set)
		forth_list.push_back(x);
	forth_list.sort();
	for (const int &x : forth_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//15 41 25 1 41 3 42 41
//15 41 25 41 42 41
//42 
//1 2 3 5 4 1
//1 2 3 4 5
//1 2 3 4 5

//函数签名
//(1)
//void merge(list& x);
//void merge(list&& x);
//(2)
//template <class Compare>
//void merge(list& x, Compare comp);
//template <class Compare>
//void merge(list&& x, Compare comp);
#include<iostream>
#include<list> 
using namespace std;
struct Int_cmp{
	bool operator ()(double a, double b)
	{
		return (int)a < (int)b;
	}
};
int main()
{
	list<double> first_list{ 1.1,2.2,3.5,2.4 };
	list<double> second_list{ 1.3,1.6,2.4 };
	first_list.sort();
	second_list.sort();
	first_list.merge(second_list);		//现在first_list为{1.1，1.3，1.6，2.2，2.4，2.4，3.5}，second_list为{ }

	second_list.push_back(1.9);
	second_list.merge(first_list, Int_cmp());
	for (const double &x : second_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//1.9 1.1 1.3 1.6 2.2 2.4 2.4 3.5

//函数签名
//(1)
//void sort();
//(2)
//template <class Compare>
//void sort(Compare comp);
//void reverse() noexcept;
#include<iostream>
#include<list> 
#include<string>
using namespace std;
bool string_cmp(const string& first, const string& second)		//忽略大小写比较
{
	unsigned int i = 0;
	while ((i < first.length())&&(i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i]))
			return true;
		else if (tolower(first[i]) > tolower(second[i]))
			return false;
		i++;
	}
	return first.length() < second.length();
}
int main()
{
	list<string> first_list{ "one","two","Three" };
	first_list.sort();
	for (const string &x : first_list)
		cout << x << " ";
	cout << endl;
	first_list.sort(string_cmp);
	for (const string &x : first_list)
		cout << x << " ";
	cout << endl;
	first_list.reverse();
	for (const string &x : first_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//Three one two
//one Three two
//two Three onw

//函数签名
//allocator_type get_allocator() const noexcept;
#include<iostream>
#include<list> 
using namespace std;
int main()
{
	list<int> first_list;
	int *p;
	p = first_list.get_allocator().allocate(5);
	for (int i = 1; i <= 5; i++)
	{
		p[i - 1] = i;
	}
	for (int i = 0; i != 5; i++)
		cout << p[i] << " ";
	cout << endl;
	first_list.get_allocator().deallocate(p, 5);
	return 0;
}
//输出：
//1 2 3 4 5

//函数签名
//(1)
//template <class T, class Alloc>
//bool operator== (const list<T, Alloc>& lhs, const list<T, Alloc>& rhs);
//(2)
//template <class T, class Alloc>
//bool operator!= (const list<T, Alloc>& lhs, const list<T, Alloc>& rhs);
//(3)
//template <class T, class Alloc>
//bool operator<  (const list<T, Alloc>& lhs, const list<T, Alloc>& rhs);
//(4)
//template <class T, class Alloc>
//bool operator<= (const list<T, Alloc>& lhs, const list<T, Alloc>& rhs);
//(5)
//template <class T, class Alloc>
//bool operator>  (const list<T, Alloc>& lhs, const list<T, Alloc>& rhs);
//(6)
//template <class T, class Alloc>
//bool operator>= (const list<T, Alloc>& lhs, const list<T, Alloc>& rhs);
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list{ 1,2,3 };
	list<int> second_list{ 2,2,2 };
	list<int> third_list{ 3,2,1 };
	if (first_list == second_list)
		cout << "first_list == second_list" << endl;
	if (first_list != second_list)
		cout << "first_list != second_list" << endl;
	if (first_list > second_list)
		cout << "first_list > second_list" << endl;
	if (first_list < second_list)
		cout << "first_list < second_list" << endl;
	if (second_list >= third_list)
		cout << "second_list >= third_list" << endl;
	if (second_list != third_list)
		cout << "second_list <= third_list" << endl;
	return 0;
}
//输出：
//first_list != second_list
//first_list < second_list
//second_list >= third_list

//函数签名
//template <class T, class Alloc>
//void swap(list<T, Alloc>& x, list<T, Alloc>& y);
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> first_list{ 1,2,3 };
	list<int> second_list{ 3,2,1 };
	first_list.swap(second_list);
	for (const auto &x : first_list)
		cout << x << " ";
	cout << endl;
	for (const auto &x : second_list)
		cout << x << " ";
	cout << endl;
	return 0;
}
//输出：
//3 2 1
//1 2 3
