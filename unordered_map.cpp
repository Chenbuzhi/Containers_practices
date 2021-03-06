//函数签名
//empty(1)
//unordered_map();
//explicit unordered_map(size_type n,
//	const hasher& hf = hasher(),
//	const key_equal& eql = key_equal(),
//	const allocator_type& alloc = allocator_type());
//explicit unordered_map(const allocator_type& alloc);
//unordered_map(size_type n, const allocator_type& alloc);
//unordered_map(size_type n, const hasher& hf, const allocator_type& alloc);
//range(2)
//template <class InputIterator>
//unordered_map(InputIterator first, InputIterator last,
//	size_type n = /* see below */,
//	const hasher& hf = hasher(),
//	const key_equal& eql = key_equal(),
//	const allocator_type& alloc = allocator_type());
//template <class InputIterator>
//unordered_map(InputIterator first, InputIterator last,
//	size_type n, const allocator_type& alloc);
//template <class InputIterator>
//unordered_map(InputIterator first, InputIterator last,
//	size_type n, const hasher& hf, const allocator_type& alloc);
//copy(3)
//unordered_map(const unordered_map& ump);
//unordered_map(const unordered_map& ump, const allocator_type& alloc);
//move(4)
//unordered_map(unordered_map&& ump);
//unordered_map(unordered_map&& ump, const allocator_type& alloc);
//initializer list(5)
//unordered_map(initializer_list<value_type> il,
//	size_type n = /* see below */,
//	const hasher& hf = hasher(),
//	const key_equal& eql = key_equal(),
//	const allocator_type& alloc = allocator_type());
//unordered_map(initializer_list<value_type> il,
//	size_type n, const allocator_type& alloc);
//unordered_map(initializer_list<value_type> il,
//	size_type n, const hasher& hf, const allocator_type& alloc);
//copy(1)
//unordered_map& operator= (const unordered_map& ump);
//move(2)
//unordered_map& operator= (unordered_map&& ump);
//initializer list(3)
//unordered_map& operator= (intitializer_list<value_type> il);
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
typedef unordered_map<string, string> stringMap;
stringMap merge(stringMap a, stringMap b)
{
	stringMap tmp(a);
	tmp.insert(b.begin(), b.end());
	return tmp;
}
int main()
{
	stringMap first_sm;										//empty
	stringMap second_sm({ { "a","b" }, { "c","d" } });		//init list
	stringMap third_sm({ {"e","f"},{"g","h"} });
	stringMap fourth_map(second_sm);						//copy
	stringMap fifth_map(merge(second_sm, third_sm));		//move ,因为这里是右值
	stringMap six_map(fifth_map.begin(), fifth_map.end());	//range
	for (auto &x : six_map)
		cout << x.first << " " << x.second << endl;

	first_sm = merge(second_sm, third_sm);					//move
	second_sm = third_sm;									//copy
	return 0;
}
//输出：
//a b
//c d
//e f
//g h

//函数签名
//bool empty() const noexcept;
//size_type size() const noexcept;
//size_type max_size() const noexcept;
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	unordered_map<int, int> first_um = { {1,1},{3,3} ,{2,2} };
	if (!first_um.empty())
		cout << "first_um is not empty." << endl;
	cout << "Size of first_um : " << first_um.size() << endl;
	cout << "Maxsize of first_um : " << first_um.max_size() << endl;
	return 0;
}
//输出：
//first_um is not empty.
//Size of first_um : 3
//Maxsize of first_um : 268435455

//函数签名
//container iterator(1)
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
//bucket iterator(2)
//local_iterator begin(size_type n);
//const_local_iterator begin(size_type n) const;
//container iterator(1)
//iterator end() noexcept;
//const_iterator end() const noexcept;
//bucket iterator(2)
//local_iterator end(size_type n);
//const_local_iterator end(size_type n) const;
//container iterator(1)
//const_iterator cbegin() const noexcept;
//bucket iterator(2)
//const_local_iterator cbegin(size_type n) const;
//container iterator(1)
//const_iterator cend() const noexcept;
//bucket iterator(2)
//const_local_iterator cend(size_type n) const;
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_map<string, string> first_um = { {"a","a"},{"c","c"},{"e","e"} };
	for (auto it = first_um.begin(); it != first_um.end(); it++)
		cout << it->first << "->" << it->second << endl;
	for (int i = 0; i != first_um.bucket_count(); i++)
	{
		cout << "bucket " << i << " contains :";
		for (auto local_it = first_um.begin(i); local_it != first_um.end(i); local_it++)
			cout << local_it->first << "->" << local_it->second;
		cout << endl;
	}
	for (auto it = first_um.cbegin(); it != first_um.cend(); it++)
		cout << it->first << "->" << it->second << endl;
	return 0;
}
//输出：
//a->a
//c->c
//e->e
//bucket 0 contains :e->e
//bucket 1 contains :
//bucket 2 contains :c->c
//bucket 3 contains :
//bucket 4 contains :a->a
//bucket 5 contains :
//bucket 6 contains :
//bucket 7 contains :
//a->a
//c->c
//e->e

//函数签名
//mapped_type& operator[] (const key_type& k);
//mapped_type& operator[] (key_type&& k);
//mapped_type& at(const key_type& k);
//const mapped_type& at(const key_type& k) const;
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_map<string, string> first_um = { { "a","a" },{ "c","c" },{ "e","e" } };
	string tmp;
	first_um["a"] = "b";
	first_um["b"] = "a";
	tmp = first_um["z"];
	for (auto x : first_um)
		cout << x.first << "->" << x.second << endl;
	unordered_map<string, int>  second_um = { {"a",1},{"b",2},{"c",3} };
	second_um.at("a") = 2;
	second_um.at("b") += 2;
	second_um.at("c") = second_um.at("a") + 1;
	for (auto x : second_um)
		cout << x.first << "->" << x.second << endl;
	return 0;
}
//输出：
//a->b
//c->c
//e->e
//z->
//b->a
//a->2
//b->4
//c->3

//函数签名
//iterator find(const key_type& k);
//const_iterator find(const key_type& k) const;
//size_type count(const key_type& k) const;
//pair<iterator, iterator>
//equal_range(const key_type& k);
//pair<const_iterator, const_iterator>
//equal_range(const key_type& k) const;
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_map<string, string> first_um = { { "a","a" },{ "c","c" },{ "e","e" },{"a","b"} };
	auto it = first_um.find("a");
	cout << it->first << "->" << it->second << endl;
	cout << first_um.count("a") << endl;		//因为不允许多键，所以只能返回1或者0

	auto ItPair = first_um.equal_range("c");
	cout << ItPair.first->first << "->" << ItPair.first->second << endl;
	cout << ItPair.second->first << "->" << ItPair.second->second << endl;
	return 0;
}
//输出：
//a->a
//1
//c->c
//e->e

//函数签名
//template <class... Args>
//pair<iterator, bool> emplace(Args&&... args);
//template <class... Args>
//iterator emplace_hint(const_iterator position, Args&&... args);
//(1)
//pair<iterator, bool> insert(const value_type& val);
//(2)
//template <class P>
//pair<iterator, bool> insert(P&& val);
//(3)
//iterator insert(const_iterator hint, const value_type& val);
//(4)
//template <class P>
//iterator insert(const_iterator hint, P&& val);
//(5)
//template <class InputIterator>
//void insert(InputIterator first, InputIterator last);
//(6)
//void insert(initializer_list<value_type> il);
//by position (1)
//iterator erase(const_iterator position);
//by key(2)
//size_type erase(const key_type& k);
//range(3)
//iterator erase(const_iterator first, const_iterator last);
//void clear() noexcept;
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_map<string, string> first_um;
	first_um.emplace("a", "a");
	first_um.emplace("b", "b");
	first_um.emplace("c", "c");
	auto it = first_um.find("b");
	first_um.emplace_hint(it, "e", "e");
	for (auto x : first_um)
		cout << x.first << "->" << x.second << endl;
	pair<unordered_map<string, string>::iterator, bool> itPair = first_um.insert({ "b", "c" });
	if (!itPair.second)
		cout << "The key of \"b\" existed." << endl;
	first_um.erase("b");
	first_um.erase(first_um.begin());
	first_um.emplace("x", "x");
	first_um.emplace("o", "o");
	first_um.emplace("z","z");
	first_um.erase(first_um.find("o"), first_um.end());
	for (auto x : first_um)
		cout << x.first << "->" << x.second << endl;
	first_um.clear();
	unordered_map<string, string> second_um;
	first_um.swap(second_um);
	return 0;
}
//输出：
//a->a
//b->b
//c->c
//e->e
//The key of "b" existed.
//c->c
//e->e
//x->x

//函数签名
//size_type bucket_count() const noexcept;
//size_type max_bucket_count() const noexcept;
//size_type bucket_size(size_type n) const;
//size_type bucket(const key_type& k) const;
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_map<string, string> first_um = { { "a","a" },{ "c","c" },{ "e","e" } ,{"f","f"},{"o","k"} };
	int cnt = first_um.bucket_count();
	cout << "first_um has " << cnt << "buckets" << endl;
	for (int i = 0; i != cnt; i++)
	{
		cout << "bucket # " << i << "contains:";
		for (auto it = first_um.begin(i); it != first_um.end(i); it++)
			cout << "[" << it->first << ":" << it->second << "] ";
		cout << endl;
	}
	unordered_map<int, int> second_um;
	cout << "max_size = " << second_um.max_size() << endl;
	cout << "max_bucket_count = " << second_um.max_bucket_count() << endl;
	cout << "max_load_factor = " << second_um.max_load_factor() << endl;

	for (int i = 0; i != first_um.bucket_count(); i++)
	{
		cout << "bucket # " << i << " has " << first_um.bucket_size(i) << " element." << endl;
	}

	for (auto x : first_um)
	{
		cout << "Element [" << x.first << ":" << x.second << "]";
		cout << "is in bucket # " << first_um.bucket(x.first) << endl;
	}
	return 0;
}
//输出：
//first_um has 11buckets
//bucket # 0contains:[c:c]
//bucket # 1contains:[e:e]
//bucket # 2contains:
//bucket # 3contains:
//bucket # 4contains:
//bucket # 5contains:
//bucket # 6contains:
//bucket # 7contains:[o:k] [a:a]
//bucket # 8contains:[f:f]
//bucket # 9contains:
//bucket # 10contains:
//max_size = 1152921504606846975
//max_bucket_count = 1152921504606846975
//max_load_factor = 1
//bucket # 0 has 1 element.
//bucket # 1 has 1 element.
//bucket # 2 has 0 element.
//bucket # 3 has 0 element.
//bucket # 4 has 0 element.
//bucket # 5 has 0 element.
//bucket # 6 has 0 element.
//bucket # 7 has 2 element.
//bucket # 8 has 1 element.
//bucket # 9 has 0 element.
//bucket # 10 has 0 element.
//Element[o:k]is in bucket # 7
//Element[a:a]is in bucket # 7
//Element[c:c]is in bucket # 0
//Element[e:e]is in bucket # 1
//Element[f:f]is in bucket # 8

//函数签名
//float load_factor() const noexcept;
//get(1)
//float max_load_factor() const noexcept;
//set(2)
//void max_load_factor(float z);
//void rehash(size_type n);
//void reserve(size_type n);
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_map<string, string> first_um ;
	cout << "size = " << first_um.size() << endl;
	cout << "bucket_count = " << first_um.bucket_count() << endl;
	cout << "load_factor = " << first_um.load_factor() << endl;
	cout << "max_load_factor = " << first_um.max_load_factor() << endl;

	unordered_map<string, string> second_um = { {"a","b" },{ "c", "d"},{"e","f"} };
	cout << "current max_load_factor :" << second_um.max_load_factor() << endl;
	cout << "current size :" << second_um.size() << endl;
	cout << "current bucket_count:" << second_um.bucket_count() << endl;
	cout << "current load_factor: " << second_um.load_factor() << endl;
	float z = second_um.max_load_factor();
	second_um.max_load_factor(z / 2.0);
	cout << "new max_load_factor :" << second_um.max_load_factor() << endl;
	cout << "new size :" << second_um.size() << endl;
	cout << "new bucket_count:" << second_um.bucket_count() << endl;
	cout << "new load_factor: " << second_um.load_factor() << endl;

	unordered_map<string, string> third_um;
	third_um.rehash(30);
	third_um["a"] = "a";
	third_um["b"] = "b";
	third_um["c"] = "c";
	third_um["d"] = "d";
	third_um["e"] = "e";
	cout << "current bucket_count :" << third_um.bucket_count() << endl;
	third_um.reserve(10);
	return 0;
}
//输出：
//size = 0
//bucket_count = 8
//load_factor = 0
//max_load_factor = 1
//current max_load_factor :1
//current size :3
//current bucket_count :8
//current load_factor :0.375
//new max_load_factor :0.5
//new size :3
//new bucket_count :8
//new load_factor :0.375
//current bucket_count :32

//函数签名
//hasher hash_function() const;
//key_equal key_eq() const;
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
typedef unordered_map<string, string> stringmap;
int main()
{
	stringmap first_um;
	stringmap::hasher fn = first_um.hash_function();
	cout << "this:" << fn("this") << endl;
	cout << "that:" << fn("that") << endl;

	bool case_insensitive = first_um.key_eq()("ok", "OK");
	cout << "first_um is ";
	cout << (case_insensitive ? "case insensitive" : "case sesitive") << endl;

	return 0;
}
//输出：
//this:3660305025
//that:3407360812
//first_um is case sesitive

//函数签名
//empty(1)
//explicit unordered_multimap(size_type n = /* see below */,
//const hasher& hf = hasher(),
//const key_equal& eql = key_equal(),
//const allocator_type& alloc = allocator_type());
//explicit unordered_multimap(const allocator_type& alloc);
//range(2)
//template <class InputIterator>
//unordered_multimap(InputIterator first, InputIterator last,
//	size_type n = /* see below */,
//	const hasher& hf = hasher(),
//	const key_equal& eql = key_equal(),
//	const allocator_type& alloc = allocator_type());
//copy(3)
//unordered_multimap(const unordered_multimap& umm);
//unordered_multimap(const unordered_multimap& umm, const allocator_type& alloc);
//move(4)
//unordered_multimap(unordered_multimap&& umm);
//unordered_multimap(unordered_multimap&& umm, const allocator_type& alloc);
//initializer list(5)
//unordered_multimap(initializer_list<value_type> il, size_type n = /* see below */,
//const hasher& hf = hasher(), const key_equal& eql = key_equal(),
//const allocator_type& alloc = allocator_type());
//copy (1)
//unordered_multimap& operator= ( const unordered_multimap& umm );
//move (2)
//unordered_multimap& operator= ( unordered_multimap&& umm );
//initializer list (3)
//unordered_multimap& operator= ( intitializer_list<value_type> il );
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
typedef std::unordered_multimap<string, string> stringmap;

stringmap merge(stringmap a, stringmap b)
{
	stringmap tmp(a);
	tmp.insert(b.begin(),b.end());
	return tmp;
}
int main()
{
	stringmap first;
	stringmap second{ { "aa", "bb" }, { "cc", "dd" } };
	stringmap third{ { "aa", "cc" }, { "cc", "ee" } };
	stringmap fourth(second);
	stringmap fifth(merge(third, fourth));		//move
	stringmap sixth(fifth.begin(), fifth.end());
	stringmap seventh=sixth;
	for (auto x : sixth)
		cout << x.first << "->" << x.second << endl;
	return 0;
}
//输出：
//aa->cc
//aa->bb
//cc->ee
//cc->dd

//函数签名
//bool empty() const noexcept;
//size_type size() const noexcept;
//size_type max_size() const noexcept;
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_multimap<int, int> first;
	unordered_multimap<int, int> second = { { 1, 1 }, { 2, 2 }, { 2, 3 } };
	if (first.empty())
		cout << "first is empty." << endl;
	else
		cout << "first isnot empty." << endl;
	cout << "size of second :" << second.size() << endl;
	cout << "max_size of second:" << second.max_size() << endl;
	cout << "max_bucket_count of second:" << second.max_bucket_count() << endl;
	cout << "max_load_factor of second:" << second.max_load_factor() << endl;
	return 0;
}
//输出：
//first is empty.
//size of second :3
//max_size of second :268435455
//max_bucket_count of second :8
//max_load_factor of second :1

////函数签名
//container iterator(1)
//iterator begin() noexcept;
//const_iterator begin() const noexcept;
//bucket iterator(2)
//local_iterator begin(size_type n);
//const_local_iterator begin(size_type n) const;
//container iterator(1)
//iterator end() noexcept;
//const_iterator end() const noexcept;
//bucket iterator(2)
//local_iterator end(size_type n);
//const_local_iterator end(size_type n) const;
//container iterator(1)
//const_iterator cbegin() const noexcept;
//bucket iterator(2)
//const_local_iterator cbegin(size_type n) const;
//container iterator(1)
//const_iterator cend() const noexcept;
//bucket iterator(2)
//const_local_iterator cend(size_type n) const;
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_multimap<string, string> umss = {
		{ "aaa", "bbb" },
		{ "aaa", "ccc" },
		{ "bbb", "ccc" },
		{ "bbb", "ddd" } };

	for (auto it = umss.begin(); it != umss.end(); it++)
	{
		cout << it->first << "->" << it->second << endl;
	}
	cout << endl;
	for (auto it = umss.cbegin(); it != umss.cend(); it++)
	{
		cout << it->first << "->" << it->second << endl;
	}
	return 0;
}
//输出：
//aaa->bbb
//aaa->ccc
//bbb->ccc
//bbb->ddd
//
//aaa->bbb
//aaa->ccc
//bbb->ccc
//bbb->ddd

////函数签名
//iterator find(const key_type& k);
//const_iterator find(const key_type& k) const;
//size_type count(const key_type& k) const;
//pair<iterator, iterator>
//equal_range(const key_type& k);
//pair<const_iterator, const_iterator>
//equal_range(const key_type& k) const;
#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

typedef unordered_map<string, string> stringMap;
int main()
{
	unordered_multimap<string, string> umss = {
		{ "aaa", "bbb" },
		{ "aaa", "ccc" },
		{ "bbb", "ccc" },
		{ "bbb", "ddd" } };
	auto it = umss.find("aaa");
	if (it != umss.end())
		cout << it->first << "->" << it->second << endl;
	cout << umss.find("bbb")->first << "->" << umss.find("bbb")->second << endl;

	cout << "count: " << umss.count("aaa") << endl;

	auto range = umss.equal_range("bbb");

	for_each(range.first, range.second, [](stringMap::value_type& x){cout << x.second << " "; });

	return 0;
}
//输出：
//aaa->bbb
//bbb->ccc
//count: 2
//ccc ddd

////函数签名
//template <class... Args> iterator emplace(Args&&... args);
//template <class... Args>
//iterator emplace_hint(const_iterator position, Args&&... args);
//(1)
//iterator insert(const value_type& val);
//(2)
//template <class P>
//iterator insert(P&& val);
//(3)
//iterator insert(const_iterator hint, const value_type& val);
//(4)
//template <class P>
//iterator insert(const_iterator hint, P&& val);
//(5)
//template <class InputIterator>
//void insert(InputIterator first, InputIterator last);
//(6)
//void insert(initializer_list<value_type> il);
//by position(1)
//iterator erase(const_iterator position);
//by key(2)
//size_type erase(const key_type& k);
//range(3)
//iterator erase(const_iterator first, const_iterator last);
//void clear() noexcept;
//void swap(unordered_multimap& umm);
#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	unordered_multimap<string, string> umss = {
		{ "aaa", "bbb" },
		{ "bbb", "ccc" }, };

	umss.emplace("ccc", "ddd");

	for (auto x : umss)
		cout << x.first << "->" << x.second << endl;

	auto x = umss.find("bbb");
	umss.emplace_hint(x, "xxx", "xxx");

	cout << endl;
	for (auto x : umss)
		cout << x.first << "->" << x.second << endl;

	unordered_multimap<string, string> ano;
	pair<string, string> myPair("x","y");

	ano.insert(myPair);
	ano.insert(make_pair("y", "y"));
	ano.insert(umss.begin(), ++umss.begin());
	ano.insert({ { "q", "q" }, { "b", "b" }, {"c","c"} });

	for (auto x : ano)
		cout << x.first << "->" << x.second << endl;

	umss.erase(umss.begin());
	umss.erase("ccc");
	umss.erase(umss.begin(),++umss.begin());

	cout << endl;
	for (auto x : umss)
		cout << x.first << "->" << x.second << endl;

	umss.clear();

	umss.swap(ano);

	cout << endl;
	for (auto x : umss)
		cout << x.first << "->" << x.second << endl;

	return 0;
}
//输出：
//aaa->bbb
//bbb->ccc
//ccc->ddd

//aaa->bbb
//bbb->ccc
//ccc->ddd
//xxx->xxx
//x->y
//q->q
//y->y
//c->c
//aaa->bbb
//b->b

//xxx->xxx

//x->y
//q->q
//y->y
//c->c
//aaa->bbb
//b->b

//函数签名
//size_type bucket_count() const noexcept;
//size_type max_bucket_count() const noexcept;
//size_type bucket_size(size_type n) const;
//size_type bucket(const key_type& k) const;
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_multimap<string, string> umss = {
		{ "w", "w" },
		{ "i", "i" },
		{ "l", "l" },
		{ "l", "l" },
		{ "i", "i" },
		{ "a", "a" },
		{ "m", "m" } };

	unsigned n = umss.bucket_count();
	cout << "umss has " << n << " buckets. " << endl;

	for (unsigned i = 0; i != n; i++)
	{
		cout << "bucket " << i;
		for (auto it = umss.begin(i); it != umss.end(i); it++)
			cout << " [ " << it->first << " , " << it->second << " ] " ;
		cout << endl;
	}

	cout << "max_size : " << umss.max_size() << endl;
	cout << "max_bucket_count : " << umss.max_bucket_count()<< endl;
	cout << "max_load_factor : " << umss.max_load_factor() << endl;

	return 0;
}
//umss has 8 buckets
//bucket 0 [ m , m ]
//bucket 1
//bucket 2
//bucket 3 [ l , l ] [ l , l ]
//bucket 4 [ a , a ] [ i , i ] [ i , i ]
//bucket 5
//bucket 6 [ w , w ]
//bucket 7
//max_size : 67108863
//max_bucket_count : 8
//max_load_factor : 1

//函数签名
//float load_factor() const noexcept;
//get(1)
//float max_load_factor() const noexcept;
//set(2)
//void max_load_factor(float z);
//void rehash(size_type n);
//void reserve(size_type n);
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
	unordered_multimap<int, int> first_ummap;
	cout << "load_factor " << first_ummap.load_factor() << endl;

	unordered_multimap<string, string> second_ummap = {
		{ "a", "b" },
		{ "b", "c" },
		{ "c", "d" }
	};
	cout << "max_load_factor  " << second_ummap.max_load_factor() << endl;
	cout << "size  " << second_ummap.size() << endl;
	cout << "bucket_count  " << second_ummap.bucket_count() << endl;
	cout << "load_factor  " << second_ummap.load_factor() << endl;

	double z = second_ummap.max_load_factor();
	second_ummap.max_load_factor(z / 2.0);

	cout << "max_load_factor  " << second_ummap.max_load_factor() << endl;
	cout << "size  " << second_ummap.size() << endl;
	cout << "bucket_count  " << second_ummap.bucket_count() << endl;
	cout << "load_factor  " << second_ummap.load_factor() << endl;

	second_ummap.rehash(2);
	cout << second_ummap.bucket_count() << endl;

	second_ummap.rehash(20);
	second_ummap.insert({ "x", "y" });
	second_ummap.insert({ "q", "w" });
	cout << second_ummap.bucket_count() << endl;

	for (auto x : second_ummap)
		cout << x.first << "->" << x.second << endl;
	second_ummap.reserve(10);

	for (auto x : second_ummap)
		cout << x.first << "->" << x.second << endl;

	return 0;
}
//load_factor 0
//max_load_factor  1
//size  3
//bucket_count  8
//load_factor   0.375
//max_load_factor  0.5
//size  3
//bucket_count  8
//load_factor   0.375
//8
//32
//a->b
//b->c
//c->d
//x->y
//q->w
//a->b
//b->c
//c->d
//x->y
//q->w
