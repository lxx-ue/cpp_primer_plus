﻿// a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <stdio.h>

#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <cstring> 
#include <new>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <queue>
#include <list>
#include <memory>
#include <sstream>
#include <numeric>
#include <utility>

#include "chapter9/ch9_1.h"
#include "chapter9/ch9_4.h"
#include "chapter11/ch11_1.h"
#include "chapter11/ch11_4.h"
#include "chapter11/ch11_5.h"
#include "chapter11/ch11_6.h"
#include "chapter12/ch12_1.h"
#include "chapter12/ch12_2.h"
#include "chapter12/ch12_3.h"
//#include "chapter12/ch12_4.h"
#include "chapter12/ch12_5.h"
#include "chapter13/ch13_1.h"
#include "chapter13/ch13_3.h"
#include "chapter13/ch13_4.h"
#include "chapter14/virtual_base_inherit.h"
#include "chapter14/stack_template.h"
#include "chapter14/dynamic_stack_template.h"
#include "chapter14/member_template.h"
#include "chapter14/ch14_1.h"
#include "chapter14/ch14_2.h"
#include "chapter14/ch14_3.h"
#include "chapter14/ch14_4.h"
#include "chapter14/ch14_5.h"
#include "chapter15/listing15_5.h"
#include "chapter15/exc_mean.h"
#include "chapter15/sales.h"
#include "chapter15/rtti.h"
#include "chapter15/ch15_1.h"
#include "chapter15/ch15_2.h"

using namespace std;

#pragma region prototype_ch6
struct bop {
	char fullname[10];
	char title[10];
	char bopname[10];
	int preference;
};
struct metsenat {
	char name[10];
	double donate;
};
struct metsenates {
	std::string name;
	double donate;
};
#pragma endregion

#pragma region prototype_ch7
// #1
double garmon(double, double);
const int Len = 130;
const int Divs = 7;

// #2
void fill_games(int arr[], int size);
void show_games(int arr[], int size);
double avg_games(int arr[], int size);

// #3
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void show_box(box b);
void volume_box(box* b);

// #4
long double probaЬility(unsigned numbers, unsigned picks, unsigned diap);

// #5
int fact(int n);

// #6
int fill_array(double arr[], int size);
void show_array(double arr[], int size);
void reverse_array(double arr[], int size);

// #7
double* fill_array2(double* begin, double* end);
void show_array2(const double* begin, const double* end);
void revalue(double* begin, double* end, double r);

// #8
const int Seasons = 4;
const char* ses[Seasons] = { "Spring",  "Summer", "Autumn" , "Winter" };
struct ses_array {
	double aue[4];
};
void fill_seasons(double pa[]);
void show_seasons(const double da[]);
void fill_seasons(ses_array* pa);
void show_seasons(const ses_array* pa);

// #9
const int SLEN = 30;
struct student {
	char fullname[SLEN] = { "" };
	char hobby[SLEN];
	int ooplevel;
};
int getinfo(student ра[], int n);
void display1(student st);
void display2(const student* ps);
void displayЗ(const student ра[], int n);

// #10
double calculate(double (*pf)(double, double), double, double);
double summation(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
#pragma endregion

#pragma region prototype_ch8
// #1
int call_count = 0;
void print_str(const char*);
void print_str(const char*, int);
// #2
struct CandyBar
{
	const char* name;
	double weight;
	int cal;
};
void fill_candybar(CandyBar&, const char* n = "Millennium Munch", double  w = 2.85, int c = 350);
void show_candybar(const CandyBar&);
// #3
void upper_string(string&);
// #4
struct _string
{
	char* str;
	int ct;
};
void _string_set(_string&, char* chr);
void _string_show(const _string&, int count = 1);
void _string_show(const char* chr, int count = 1);
// #5
template <class T>
T max5(T[5]);
// #6
template <class T>
T maxn(T[], int);
template <> char* maxn<char*>(char* [], int);
// #7
struct debts
{
	char name[50];
	double amount;
};
template <typename T>
T SumArray(T arr[], int n);
template <typename T>
T* SumArray(T* arr[], int n);
#pragma endregion

#pragma region prototype_ch9
// #2
void strcount(string str);
// #3
const int STRUCTSIZE = 2;       // размер массива структур
const int BUFFSIZE = 50;        // размер массива buffer
char buffer[BUFFSIZE];          // блок памяти под буфер
struct chaff {                   // определение структуры
	char dross[20];
	int slag;
};
#pragma endregion

#pragma region prototype_ch10
// #1
class BankAccount
{
public:
	BankAccount();
	BankAccount(string name, string num, long double balance);
	~BankAccount();
	void show();
	void plus_sum(double sum);
	void minus_sum(double sum);
private:
	string name;
	string num;
	long double balance;
};
BankAccount::BankAccount()
{
	name = "None";
	num = "None";
	balance = 0.0;
}
BankAccount::BankAccount(string name, string num, long double balance)
{
	this->name = name;
	this->num = num;
	this->balance = balance;
}
void BankAccount::show()
{
	cout << "Account keeper: " << name << "; Account num " << num << "; Balance $" << balance << endl;
}
void BankAccount::plus_sum(double sum)
{
	balance += sum;
}
void BankAccount::minus_sum(double sum)
{
	balance -= sum;
}
BankAccount::~BankAccount()
{
	cout << "Bye!";
}

// #2
class Person
{
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person()
	{
		lname = "";
		fname[0] = '\0';
	}
	Person(const string& ln, const char* fn = "Heyyou")
	{
		lname = ln;
		strcpy(fname, fn);
	}
	void Show() const
	{
		cout << fname << " " << lname << endl;
	}
	void FormalShow() const
	{
		cout << lname << " " << fname << endl;
	}
};

// #3
class Golf {
private:
	static const int gLen = 40;
	char fullname[gLen];
	int handicap;
public:
	Golf(const char* name, int hc)
	{
		strcpy_s(fullname, name);
		handicap = hc;
	}
	Golf(Golf& g)
	{
		strcpy_s(fullname, g.fullname);
		handicap = g.handicap;
	}
	void changeHandicap(int hc)
	{
		this->handicap = hc;
	}
	void showGolf()
	{
		std::cout << "Name: " << fullname << "\t handicap: " << handicap << std::endl;
	}
};

// #4
namespace SALES {
	class _Sales
	{
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average;
		double max;
		double min;
		void detect_variables()
		{
			double min = sales[0], max = sales[0], avg = 0;
			for (int i = 0; i < QUARTERS; i++)
			{
				avg += sales[i];
				if (min > sales[i]) min = sales[i];
				if (max < sales[i]) max = sales[i];
			}
			avg /= 4;
			this->average = avg;
			this->max = max;
			this->min = min;
		}
	public:
		_Sales(const double ar[])
		{
			for (int i = 0; i < QUARTERS; i++)
			{
				sales[i] = ar[i];
			}
			detect_variables();
		}
		_Sales(Sales& s)
		{
			for (int i = 0; i < QUARTERS; i++)
			{
				this->sales[i] = s.sales[i];
			}
			detect_variables();
		}
		void showSales()
		{
			cout << sales[0] << " " << sales[1];
			cout << " " << sales[2] << " " << sales[3];
			cout << "\taverage=" << average << "\tmax=";
			cout << max << "\tmin=" << min << endl;
		}
	};
}

// #5
/*
struct Customer
{
	char fullname[35];
	double payment;
};
typedef Customer Item;
class Stack
{
private:
	static const int MAX = 10;
	Item items[MAX];
	int top;
	double sum;
public:
	Stack()
	{
		top = 0;
		sum = 0.0;
	}
	bool is_empty() const
	{
		return top == 0;
	}
	bool is_full() const
	{
		return top == MAX;
	}
	bool push(const Item& item)
	{
		if (top < MAX)
		{
			items[top++] = item;
			return true;
		}
		else return false;
	}
	bool pop(Item& item)
	{
		if (top > 0)
		{
			item = items[--top];
			sum += item.payment;
			return true;
		}
		else return false;
	}
	void show_sum() const
	{
		cout << "All sum is: " << sum;
	}
};
*/
// #6
class Move
{
private:
	double x, y;
public:
	Move(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}
	void showMove() const
	{
		cout << "x = " << x << "; y = " << y << endl;
	}
	Move add(const Move& m) const
	{
		Move tmp{ this->x + m.x, this->y + m.y };
		return tmp;
	}
	void reset(double a = 0, double b = 0)
	{
		x = a;
		y = b;
	}
};

// #7
class Plorg
{
private:
	char name[20];
	int CI;
public:
	Plorg(const char* name = "Plorga", int CI = 50)
	{
		strcpy_s(this->name, name);
		this->CI = CI;
	}
	void changeCI(int CI)
	{
		this->CI = CI;
	}
	void showPlorg()
	{
		cout << "Name: " << name << "; CI = " << CI << endl;
	}
};
#pragma endregion

#pragma region prototype_ch11
// #5
void display(const Stonewt& st, int n);
#pragma endregion

#pragma region prototype_ch12
// #5
bool newcustomer(double x);
#pragma endregion

#pragma region prototype_ch13
// #1
void Bravo(const Cd& disk);
#pragma endregion

#pragma region prototype_ch15
double hmean(double a, double b);
double gmean(double a, double b);
Grand* GetOne();
#pragma endregion

#pragma region prototype_ch16
const int NUM = 26;
const string wordlist[NUM] = { "apiary", "beetle", "cereal",
	"danger", "ensign", "florid", "garage", "healt", "insult",
	"jackal", "keeper", "loaner", "manage", "nonce", "onset",
	"plaid", "quilt", "remote", "stolid", "train", "useful",
	"valid", "whence", "xenon", "yearn", "zippy" };

// #1
bool check_palindrome(const string&);
void clean_string(string&);

char toLower(char ch) { return tolower(ch); }
string& ToLower(string& st);
void al_display(const string& s);
// #4
int reduce(long ar[], int n);
// #5-6
template <class T>
int t_reduce(T ar[], int n)
{
	vector<T> v(ar, ar + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v.size();
}
// #7
vector<int> Lotto(int range, int count);

// #8
void add_list(vector<string>& friend_list, int c);
void show_list(const vector<string>& friend_list);

// #10
struct Review {
	string title;
	int rating;
	double price;
};
bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool sortTitle(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool sortRating(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool sortPrice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool FillReview(Review& rr);
void ShowReview(const shared_ptr<Review>& rr);
void show_menu();
#pragma endregion

#pragma region prototype_ch17
void get_from_file(vector<string>& v, ifstream& f);
void sort_n_show(vector<string>& v, string name);

void ShowStr(const string&);
class Store
{
	ofstream* fil;
public:
	Store(ofstream &f)
	{
		fil = &f;
	}
	Store& operator() (const string& s)
	{
		int len = s.length();
		fil->write((char*)&len, sizeof(std::size_t));
		fil->write(s.data(), len);
		return *this;
	}
};
void GetStrs(ifstream&, vector<string>);
#pragma endregion

#pragma region prototype_ch18
void show_list() {} // 0 params

template<typename Т> // 1 param
void show_list(const Т& value)
{
	cout << value << '\n';
}

template<typename Т, typename ... Args> // >1 params
void show_list(const Т& value, const Args & ... args)
{
	cout << value << ", ";
	show_list(args ...);
}

// 1
template<typename T>
T average_list(initializer_list<T> li)
{
	return accumulate(li.begin(), li.end(), 0);
}

// 2
class Cpmv
{
public:
	struct Info
	{
		string qcode;
		string zcode;
	};
private:
	Info* pi;
public:
	Cpmv(string s1 = "none", string s2 = "none")
	{
		pi = new Info();
		pi->qcode = s1;
		pi->zcode = s2;
		cout << "Create cpmv with info: " << s1 << ' ' << s2 << endl;
	}
	Cpmv(const Cpmv& cp)
	{
		pi = new Info();
		pi->qcode = cp.pi->qcode;
		pi->zcode = cp.pi->zcode;
		cout << "Copy cpmv with info: " << pi->qcode << ' ' << pi->zcode << endl;
	}
	Cpmv(Cpmv&& mv)
	{
		pi = mv.pi;
		mv.pi = nullptr;
		cout << "Move cpmv with info: " << pi->qcode << ' ' << pi->zcode << endl;
	}

	Cpmv& operator=(const Cpmv& cp)
	{
		if (&cp == this) return *this;
		delete pi;
		pi = new Info();
		pi->qcode = cp.pi->qcode;
		pi->zcode = cp.pi->zcode;
		cout << "Copy cpmv with info: " << pi->qcode << ' ' << pi->zcode << endl;
		return *this;
	}
	Cpmv& operator=(Cpmv&& mv)
	{
		if (&mv == this) return *this;
		delete pi;
		pi = mv.pi;
		mv.pi = nullptr;
		cout << "Move cpmv with info: " << pi->qcode << ' ' << pi->zcode << endl;
		return *this;
	}
	Cpmv operator+(const Cpmv& obj)  const
	{
		Cpmv tmp;
		tmp.pi->qcode = pi->qcode + obj.pi->qcode;
		tmp.pi->zcode = pi->zcode + obj.pi->zcode;
		return tmp;
	}
	~Cpmv()
	{
		if (pi)
			cout << "deleted: " << pi->qcode << ' ' << pi->zcode << endl;
		delete pi;
	}
	void Display() const { cout << pi->qcode << ' ' << pi->zcode << endl; }
};

// 3
double sum_values() { return 0; }
template <typename T, typename... Argc>
long double sum_values(const T& value, const Argc& ... args)
{
	return value + sum_values(args...);
}
#pragma endregion

int main(int argc, char* argv[])
{
	setlocale(0, "");

#pragma region chapter6
	// #1
	//char ch;
	//cout << "enter: \n";
	//cin.get(ch);
	//while (ch != '@')
	//{
	//    if (islower(ch))
	//    {
	//        ch = toupper(ch);
	//    }
	//    else
	//    {
	//        ch = tolower(ch);
	//    }
	//    if(!isdigit(ch))
	//    cout << ch;
	//    cin.get(ch);
	//}

	// #2
	//const int don_size = 10;
	//int donates[don_size] = {};               //массив цен предметов торговли
	//int i = 0, vushe_srednego_count = 0;                          //счётчик цикла
	//cout << "donate N_" << i + 1 << ": ";          //диалог на экран
	//while (i<don_size && cin >> donates[i]) {
	//    i++;                                         //не забываем, что у while надо изменять счётчик
	//    if (i < don_size) {                                  //чтобы не выводило лишнюю строчку
	//        cout << "Product N_" << i + 1 << ": ";
	//    }
	//}
	//float total = 0;        //Оценка средней стоимости
	///*считаем всю сумму на товары*/
	//for (int j = 0; j < i; j++) {
	//    total = total + donates[j];
	//}
	///*считаем среднюю стоимость*/
	//total = total / i;
	//for (int j = 0; j < i; j++) {
	//    if (donates[j] > total) vushe_srednego_count++;
	//}
	//cout << "\nwill pay summ: " << total << '\n';     //Вывод оплачиваемой суммы
	//cout << "vushe_srednego_count:" << vushe_srednego_count<<endl;

	// #3
	//char choice;
	//cout << "Please enter one of the following choices: \nc) carnivore\t p) pianist\nt) tree\t\t g) game\n";
	//cin >> choice;
	//while (true)
	//{
	//    if (choice != 'c' && choice != 'p' && choice != 't' && choice != 'g')
	//    {
	//        cout << "Please enter a c, p, t, or g: ";
	//        cin >> choice;
	//    }
	//    else {
	//        break;
	//    }
	//}
	//switch (choice)
	//{
	//case 'c':
	//    cout << "\nARRRRHHH";
	//    break;
	//case 'p':
	//    cout << "\ntu tutu ttuuu tu";
	//    break;
	//case 't':
	//    cout << "\nu can just chill here";
	//    break;
	//case 'g':
	//    cout << "\ngonna start a game...wait...";
	//    break;
	//}

	// #4
	//array<bop, 4> bops;
	//bops[0] = { "name0", "title0", "bop0", 0 };
	//bops[1] = { "name1", "title1", "bop1", 1 };
	//bops[2] = { "name2", "title2", "bop2", 2 };
	//bops[3] = { "name3", "title3", "bop3", 0 };
	//char choice;
	//cout << "Choose display order: \na) display by name\t b) display by title\nc) display by bopname\t d) display by preference\nq) quit\n";
	//cin >> choice;
	//while (true)
	//{
	//    if (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'q')
	//    {
	//        cout << "Please enter a a, b, c, d or q: ";
	//        cin >> choice;
	//    }
	//    else {
	//        break;
	//    }
	//}
	//switch (choice)
	//{
	//case 'q':
	//    cout << "Bye!";
	//    return 0;
	//case 'a':
	//    for (int i = 0; i < bops.size(); i++)
	//    {
	//        cout << bops[i].fullname << endl;
	//    }
	//    break;
	//case 'b':
	//    for (int i = 0; i < bops.size(); i++)
	//    {
	//        cout << bops[i].title << endl;
	//    }
	//    break;
	//case 'c':
	//    for (int i = 0; i < bops.size(); i++)
	//    {
	//        cout << bops[i].bopname << endl;
	//    }
	//    break;
	//case 'd':
	//    for (int i = 0; i < bops.size(); i++)
	//    {
	//        switch (bops[i].preference)
	//        {
	//        case 0:
	//            cout << bops[i].fullname << endl;
	//            break;
	//        case 1:
	//            cout << bops[i].title << endl;
	//            break;
	//        case 2:
	//            cout << bops[i].bopname << endl;
	//            break;
	//        }
	//    }
	//    break;
	//}

	// #5
	//int sum;
	//double nalog = 0.0f;
	//cin >> sum;
	//if (sum <= 5000) {
	//    nalog = 0.0f;
	//}
	//else
	//{
	//    sum -= 5000;
	//    if (sum <= 10000)
	//    {
	//        nalog += sum * 0.1;
	//    }
	//    else
	//    {
	//        nalog += 10000 * 0.1;
	//        sum -= 10000;
	//        if (sum <= 20000)
	//        {
	//            nalog += sum * 0.15;
	//        }
	//        else
	//        {
	//            nalog += 20000 * 0.15;
	//            sum -= 20000;
	//            nalog += sum * 0.2;
	//        }
	//    }
	//}
	//cout << nalog;

	// #6
	//cout << "enter count: ";
	//int count;
	//cin >> count;
	//metsenat *metsenats = new metsenat[count];
	//for (int i = 0; i < count; i++)
	//{
	//    cout << "metsenat #" << i + 1 << endl;
	//    cout << "name: ";
	//    cin >> metsenats[i].name;
	//    cout << "donate: ";
	//    cin >> metsenats[i].donate;
	//}
	//int pat = 0, grpat = 0;
	//for (int i = 0; i < count; i++) {
	//    if (metsenats[i].donate >= 10000) grpat++;
	//    else pat++;
	//}
	//if (!grpat || !pat) cout << "none";
	//else {
	//    cout << "grand patrons: \n";
	//    for (int i = 0; i < count; i++)
	//    {
	//        if (metsenats[i].donate >= 10000) cout << metsenats[i].name << "\t" << metsenats[i].donate << endl;
	//    }
	//    cout << "patrons: \n";
	//    for (int i = 0; i < count; i++)
	//    {
	//        if (metsenats[i].donate < 10000) cout << metsenats[i].name << "\t" << metsenats[i].donate << endl;
	//    }
	//}

	//#7
	//char ch;
	//bool is_new = true;
	//int words = 0, other = 0, sogl = 0, gl = 0;
	//cout << "enter: \n";
	//cin.get(ch);
	//while (ch != '@')
	//{
	//    if (is_new)
	//    {
	//        words++;
	//        is_new = !is_new;
	//        if (isdigit(ch))
	//        {
	//            other++;
	//        }
	//        else 
	//        {
	//            if ((ch + 0) == 97 || (ch + 0) == 101 || (ch + 0) == 105 || (ch + 0) == 111 || (ch + 0) == 117)
	//            {
	//                gl++;
	//            }
	//            else
	//            {
	//                sogl++;
	//            }
	//        }
	//    }
	//    if (ch == ' ') is_new = true;
	//    else is_new = false;
	//    cout << ch;
	//    cin.get(ch);
	//}
	//if (is_new) words--;
	//cout << endl << other;
	//cout << endl << gl;
	//cout << endl << sogl;

	// #8
	//int count=0;
	//char ch;
	//ifstream fin;
	//fin.open("C:\\Users\\lx\\Desktop\\a.txt");
	//if (fin.is_open())
	//{
	//    fin >> ch;
	//    while (fin.good())
	//    {
	//        count++;
	//        fin >> ch;
	//    }
	//}
	//cout << count;
	//fin.close();

	// #9
	//string path("a.txt");
	//ifstream fin;
	//fin.open(path);
	//metsenates* metsenats;
	//string str;
	//int count, num = 0, aaa = 0;
	//if (!fin.is_open())
	//{
	//    cout << "ошибка" << endl;
	//}
	//else
	//{
	//    cout << "открыт" << endl;
	//   
	//    getline(fin, str);
	//    count = stoi(str);
	//    metsenats = new metsenates[count];
	//    bool isnum = false;
	//    while (!fin.eof())
	//    {
	//        str = "";
	//        getline(fin, str);
	//        if (!isnum)
	//        {
	//            metsenats[num].name = str;
	//        }
	//        else
	//        {
	//            aaa = stoi(str);
	//            metsenats[num].donate = aaa;
	//            num++;
	//        }
	//        isnum = !isnum;
	//    }
	//    int pat = 0, grpat = 0;
	//    for (int i = 0; i < count; i++) {
	//        if (metsenats[i].donate >= 10000) grpat++;
	//        else pat++;
	//    }
	//    if (!grpat || !pat) cout << "none";
	//    else {
	//        cout << "grand patrons: \n";
	//        for (int i = 0; i < count; i++)
	//        {
	//            if (metsenats[i].donate >= 10000) cout << metsenats[i].name << "\t" << metsenats[i].donate << endl;
	//        }
	//        cout << "patrons: \n";
	//        for (int i = 0; i < count; i++)
	//        {
	//            if (metsenats[i].donate < 10000) cout << metsenats[i].name << "\t" << metsenats[i].donate << endl;
	//        }
	//    }
	//}
	//fin.close();
#pragma endregion

#pragma region chapter7
	// #1
	//double x, y;
	//cout<<"Введите 2 числа: ";
	//cin>>x>>y;
	//while (!(x == 0 || y == 0))
	//{
	//    cout<<garmon(x, y)<<"\nВведите 2 числа: ";
	//    cin>>x>>y;
	//}

	// #2
	//const int golf_size = 10;
	//int games[golf_size] = {};              
	//int i = 0;                          
	//fill_games(games, golf_size);
	//show_games(games, golf_size);
	//cout<<"average is: "<< avg_games(games, golf_size)<< endl;

	// #3
	//box boxy = { "name\0", 1, 2 , 3, 4 };
	//show_box(boxy);
	//volume_box(&boxy);
	//show_box(boxy);

	// #4
	//double total, choices, second;
	//cout << "Enter the total numЬer of choices on the game card and\ n"
	//" the number of picks allowed:\n";
	//while ((cin >> total >> choices>> second) && choices <= total && second <= total)
	//{
	//    cout << " You have one chance in ";
	//    cout << probaЬility(total, choices, second);
	//    cout << " of winning . \n";
	//    cout << "Next two numbers (q to qu it) : ";
	//}
	//cout << "bye\n";

	// #5
	//int num;
	//cout << "Enter num to factorial: ";
	//while (cin >> num)
	//{
	//    if (num < 0) num *= -1;
	//    cout <<num<< " factorial = " << fact(num) << endl;
	//    cout << "Next number : ";
	//}
	//cout << "bye\n";

	// #6
	//const int size = 6;
	//int real;
	//double arr[size];
	//real = fill_array(arr, size);
	//show_array(arr, real);
	//reverse_array(arr, real);
	//show_array(arr, real);

	// #7
	//const int Мах = 5;
	//double properties[Мах];
	//double * end = fill_array2(properties, properties+Мах);
	//show_array2(properties, end);
	//if (end > properties)
	//{
	//    cout << " Enter revaluation factor: ";
	//    double factor;
	//    while (!(cin >> factor))
	//    {
	//        cin.clear();
	//        while (cin.get() != '\n')
	//            continue;
	//        cout << "Bad input; Please enter а number: ";
	//    }
	//    revalue(properties, end, factor);
	//    show_array2(properties, end);
	//}
	//cout << " Done.\n ";
	//cin.get();

	// #8
	//double aue[4];
	//fill_seasons(aue);
	//show_seasons(aue);
	//ses_array st_ses;
	//fill_seasons(&st_ses);
	//show_seasons(&st_ses);

	// #9
	//cout << "Enter class size: ";
	//int class_size;
	//cin >> class_size;
	//while (cin.get() != '\n')
	//    continue;
	//student* ptr_stu = new student[class_size];
	//cout << endl;
	//int entered = getinfo(ptr_stu, class_size);
	//cout << "You entered "<<entered<<" students\n";
	//for (int i = 0; i < entered; i++)
	//{
	//    display1(ptr_stu[i]);
	//    display2(&ptr_stu[i]);
	//}
	//displayЗ(ptr_stu, entered);
	//delete[] ptr_stu;
	//cout << "Done\n";

	// #10
	//double a, b;
	//cout << "Enter two numbers: ";
	//while (cin >> a >> b)
	//{
	//    cout << "summation is = " << calculate(summation, a, b) << endl;
	//    cout << "subtraction is = " << calculate(subtraction, a, b) << endl;
	//    cout << "multiplication is = " << calculate(multiplication, a, b) << endl;
	//    cout << "division is = " << calculate(division, a, b) << endl;
	//    cout << "Enter two numbers again: ";
	//}
#pragma endregion

#pragma region chapter8
	// #1
	//print_str("shesh");
	//print_str("shesh",5);
	//print_str("shesh",5);
	//print_str("shesh",5);
	//print_str("shesh");

	// #2
	//CandyBar cb;
	//fill_candybar(cb);
	//show_candybar(cb);
	//fill_candybar(cb, "alpen gold", 100);
	//show_candybar(cb);

	// #3
	//string s;
	//cout << "Enter a string: ";
	//while (getline(cin, s) && s != "q")
	//{
	//	upper_string(s);
	//	cout << s <<endl;
	//	cout << "Enter a string: ";
	//}
	//cout << "Bye";

	// #4
	//_string beany;
	//char testing[] = "Reality isn't what it used to bе.";
	//_string_set(beany, testing); // первым аргументом является ссылка,
	//// Выделяет пространство для хранения копии testing,
	//// использует элемент типа str структуры beany как указатель
	//// на новый блок, копирует testing в новый блок и
	//// создает элемент ct структуры beany
	//_string_show(beany); // выводит строковый член структуры один раз
	//_string_show(beany, 2); // выводит строковый член структуры два раза
	//testing[0] = 'D';
	//testing[1] = 'u';
	//_string_show(testing);
	//_string_show(testing, 3);
	//_string_show("Done!");
	//delete beany.str;

	// #5
	//int arr[5] = { 1, 5, 6, 7, 9};
	//cout << max5(arr) << endl;
	//double arr2[5] = { 1.4, 5.6, 2.6, 5.7, 0.9 };
	//cout << max5(arr2) << endl;

	// #6
	//int arr[6] = { 1, 15, 32, 2, 6, 7};
	//cout << maxn(arr, 6) << endl;
	//double arr2[4] = { 1.4, 5.6, 5.7, 7.9 };
	//cout << maxn(arr2, 4) << endl;
	//char* B[3];
	//for (int i = 0; i < 3; i++) {
	//	B[i] = new char[6];
	//}
	//strcpy(B[0], "Wake");
	//strcpy(B[1], "upppp");
	//strcpy(B[2], "Neo");
	//cout << maxn(B,3) << endl;

	// #7
	//int things[6] = { 13, 31, 103, 301, 310, 130 };
	//struct debts mr_E[3] =
	//{
	//{ "Ima Wolfe", 2400.0 },
	//{ "Ura Foxe" , 1300.0 },
	//{ "Iby Stout" , 1800.0 }
	//};
	//double* pd[3];
	//for (int i = 0; i < 3; i++)
	//	pd[i] = &mr_E[i].amount;
	//cout << "Listing Mr.Е's counts of things: \n";
	//cout << SumArray(things, 6) << endl;
	//cout << "Listing Mr.Е's debts: \n";
	//cout << *(SumArray(pd, 3)) << endl;
#pragma endregion

#pragma region chapter9
	// #1
	//golf g1;
	//setGolf(g1);
	//showGolf(g1);
	//handicap(g1, 5);
	//showGolf(g1);

	// #2
	//string s;
	//char next;
	//cout << "Enter a line: \n";
	//getline(cin, s);
	//while (s != "")
	//{
	//	strcount(s);
	//	cout << "Enter next line (empty line to quit):\n";
	//	getline(cin, s);
	//}
	//cout << "Bye\n";

	// #3
	//chaff* pchaff = new (buffer) chaff[STRUCTSIZE];    // выделение памяти с размещением
	//													// в массиве buffer
	//strcpy(pchaff[0].dross, "one");   // инициализация массива структур
	//strcpy(pchaff[1].dross, "two");
	//pchaff[0].slag = 1;
	//pchaff[1].slag = 2;
	//std::cout << "Address of buffer: " << &buffer
	//	<< "\nSize of buffer: " << sizeof buffer << "\n";
	//std::cout << "Address of &pchaff[0]: " << &pchaff[0]
	//	<< "\nSize of pchaff: " << sizeof pchaff << "\n";
	//std::cout << "Size of pchaff[0]: " << sizeof pchaff[0] << "\n";
	//std::cout << "Address of &pchaff[1]: " << &pchaff[1] << "\n";
	//for (int i = 0; i < STRUCTSIZE; i++) {           // отображение массива структур
	//	std::cout << pchaff[i].dross << "\n"
	//		<< pchaff[i].slag << "\n";
	//}

	// #4
	//double arr[SALES::QUARTERS] = { 2.2, 3.3, 4.4, 5.5 };
	//SALES::Sales s1, s2;
	//SALES::setSales(s1,arr);
	//for (int i = 0; i < SALES::QUARTERS; i++)
	//{
	//	s2.sales[i] = arr[i] * 2;
	//}
	//SALES::setSales(s2);

#pragma endregion

#pragma region chapter10
	// #1
	//BankAccount ba, ba2 {"Julia", "#00001", 99999};
	//ba.show();
	//ba2.show();
	//ba2.minus_sum(400);
	//ba2.show();
	//ba2.plus_sum(5);
	//ba2.show();

	// #2
	//Person one, two{ "Smythecraft" }, three{ "Dimwiddy", "Sam" };
	//one.Show();
	//one.FormalShow();
	//two.Show();
	//two.FormalShow();
	//three.Show();
	//three.FormalShow();

	// #3
	//Golf gg("Name", 15);
	//gg.showGolf();
	//gg.changeHandicap(14);
	//Golf golf(gg);
	//golf.showGolf();

	// #4
	//double arr[SALES::QUARTERS] = { 2.2, 3.3, 4.4, 5.5 };
	//SALES::_Sales s1(arr);
	//s1.showSales();
	//SALES::_Sales s2(s1);
	//s2.showSales();

	// #5
	//Stack st;
	//Customer ct[3] = { Customer{ "name", 12 }, Customer{ "name", 13 }, Customer{ "name", 14 } };
	//st.push(ct[0]);
	//st.push(ct[1]);
	//st.push(ct[2]);
	//st.pop(ct[0]); // lifo
	//st.show_sum();

	// #6
	//Move mv;
	//Move mv2(3, 5);
	//mv.showMove();
	//mv2.showMove();
	//mv.reset(10, 10);
	//Move mv3 = mv.add(mv2);
	//mv3.showMove();
	//mv2.reset();
	//mv2.showMove();

	// #7
	//Plorg prg("New", 34);
	//prg.showPlorg();
	//prg.changeCI(90);
	//prg.showPlorg();
#pragma endregion

#pragma region chapter11
	// #1-2
	/*using VECTOR::Vector;
	srand(time(0));
	double direction, target, dstep;
	Vector step, result(0.0, 0.0);
	unsigned long steps = 0;
	ofstream fout;
	fout.open("random_walk.txt");
	cout << "See random_walk.txt for details\nEnter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		fout <<"0: "<< result << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::Mode::POL);
			result = result + step;
			steps++;
			fout << steps<<": "<<result << endl;
		}
		cout << "After " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		fout << "Total steps: " << steps << ", Location: " << result <<
			"\nAverage distance per step: " << result.magval() / steps << "\n\n";
		result.polar_mode();
		cout << "or\n" << result;
		cout << "\nAverage outward distance per steps = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;*/

		// #3
		//using VECTOR::Vector;
		//srand(time(0));
		//double direction, target, dstep;
		//Vector step, result(0.0, 0.0);
		//unsigned long steps = 0, tries = 0;

		//cout << "Enter target distance (q to quit): ";
		//cin >> target;
		//cout << "Enter step length: ";
		//cin >> dstep;
		//cout << "Enter tries: ";
		//cin >> tries;
		//int* arr = new int[tries];
		//for (int i = 0; i < tries; i++)
		//{
		//	while (result.magval() < target)
		//	{
		//		direction = rand() % 360;
		//		step.reset(dstep, direction, Vector::Mode::POL);
		//		result = result + step;
		//		steps++;
		//	}
		//	arr[i] = steps;
		//	steps = 0;
		//	result.reset(0.0, 0.0);
		//}
		//int min = arr[0], max = arr[0], avg = 0;
		//for (int i = 0; i < tries; i++)
		//{	
		//	avg += arr[i];
		//	if (min > arr[i]) min = arr[i];
		//	if (max < arr[i]) max = arr[i];
		//}
		//avg /= tries;
		//cout << "max = "<<max<<endl;
		//cout << "min = " << min << endl;
		//cout << "avg = " << avg << endl;
		//delete[] arr;

		// #4
		//Time aida(3, 35);
		//Time tosca(2, 48);
		//Time temp;
		//cout << "Aida and Tosca:\n";
		//cout << aida << "; " << tosca << endl;
		//temp = aida + tosca;
		//cout << "Aida + Tosca: " << temp << endl;
		//temp = aida * 1.17;
		//cout << "Aida * 1.17: " << temp << endl;
		//cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

		// #5
		//Stonewt incognito = 275;
		//Stonewt wolfe(285.7);
		//Stonewt taft(21, 8);
		//cout << "The celebrity weighed ";
		//cout << incognito;
		//cout << "The detective weighed ";
		//cout << wolfe;
		//cout << "The president weighed ";
		//cout << taft;
		//incognito = 276.8;
		//cout << taft;
		//cout << "After dinner, the celebrity weighed ";
		//cout << incognito;
		//cout << "After dinner, the president weighed ";
		//cout << taft;
		//taft.set_mode(Stonewt::Mode::lbs);
		//cout << "or\n" << taft;
		//display(taft, 2);
		//cout << "The wrestler weighed even more.\n";
		//display(422, 2);
		//cout << "No more left unerned\n";

		// #6
		//Stonewt incognito = 275; //not explicit!
		//Stonewt taft = incognito;
		//incognito = 14;
		//if (!(incognito == taft)) cout << "They r equal!\n";
		//else cout << "They r not!\n";
		//if (incognito > taft) cout << "incognito bigger than taft!\n";
		//else cout << "taft bigger than incognito!\n";

		//Stonewt arr[6]{ 144, 12 , 15 };
		//Stonewt empty{ 0 };

		//for (int i = 0; i < 6; i++)
		//{
		//	if (arr[i] == empty)
		//	{
		//		cout << "Enter " << i+1 << "th element : ";
		//		double temp = 0.0;
		//		while (cin>>temp)
		//		{
		//			if (temp != 0.0) break;
		//		}
		//		arr[i] = temp;
		//	}
		//}
		//Stonewt min = arr[0], max = arr[0];
		//empty = 11;
		//int count = 0;
		//for (int i = 0; i < 6; i++)
		//{
		//	if (min > arr[i]) min = arr[i];
		//	if (max < arr[i]) max = arr[i];
		//	if (arr[i] >= empty) count++;
		//}
		//cout << "Smallest: " << min << "Largest: " << max <<
		//	"Bigger than 11: " << count;

		// #7
		//Complex0 a(3.0, 4.0);
		//Complex0 c;
		//cout << "Enter a complex number (q to quit):\n";
		//while (cin >> c)
		//{
		//	cout << "c is " << c << endl;
		//	cout << "complex conjugate is " << -c << endl;
		//	cout << "a is " << a << endl;
		//	cout << "a + c is " << a + c << endl;
		//	cout << "a - c is " << a - c << endl;
		//	cout << "a * c is " << a * c << endl;
		//	cout << "2 * c is " << 2 * c << endl;
		//	cout << "Enter a complex number (q to quit):\n";
		//}
		//cout << "Done!\n";

#pragma endregion

#pragma region chapter12
	// #1
	//Cow bella;
	//bella.ShowCow();

	//Cow stella("stella", "reading", 600 );
	//stella.ShowCow();
	//bella = stella;
	//cout << endl;
	//bella.ShowCow();

	// #2
	//String s1(" and I am a C++ student.");
	//String s2 = "Please enter your name: ";
	//String s3;
	//cout << s2;
	//cin >> s3;
	//s2 = "My name is " + s3;
	//cout << s2 << ".\n";
	//s2 += s1;
	//s2.string_up();
	//cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
	//	<< " 'A' characters in it.\n";
	//s1 = "red";
	//String rgb[3]{ String{s1}, String("green"), String{"blue"} };
	//cout << "Enter the name of a primary color for mixing light: ";
	//String ans;
	//bool succes = false;
	//while (cin >> ans)
	//{
	//	ans.string_low();
	//	for (int i = 0; i < 3; i++)
	//	{
	//		if (ans == rgb[i])
	//		{
	//			cout << "That's right!\n";
	//			succes = true;
	//			break;
	//		}
	//	}
	//	if (succes) break;
	//	else cout << "Try again!\n";
	//}
	//cout << "Bye.\n";

	// #3
	//Stock stocks[4] = { 
	//	Stock("NanoSmart", 12, 20.0),
	//	Stock("Boffo Objects", 200, 2.0),
	//	Stock("Monolithic Obelisks", 130, 3.25),
	//	Stock("Fleep Enterprises", 60, 6.5)
	//};
	//cout << "Stock holdings:\n";
	//int st;
	//for (st = 0; st < 4; st++)
	//	cout << stocks[st];
	//const Stock* top = &stocks[0];
	//for (st = 1; st < 4; st++)
	//	top = &top->topval(stocks[st]);
	//cout << "\nMost valuable holding:\n";
	//cout << *top;

	// #4
	//Stack1 st;
	//char ch;
	//unsigned long po;
	//cout << "Please enter A to add a purchase,\n"
	//	<< "P to process a PO, or Q to quit.\n";
	//while (cin >> ch && toupper(ch) != 'Q')
	//{
	//	while (cin.get() != '\n')
	//		continue;
	//	if (!isalpha(ch))
	//	{
	//		cout << '\a';
	//		continue;
	//	}
	//	switch (toupper(ch))
	//	{
	//	case 'A':cout << "Enter a PO number to add: ";
	//		cin >> po;
	//		if (st.is_full())
	//			cout << "stack already full\n";
	//		else st.push(po);
	//		break;
	//	case 'P':
	//		if (st.is_empty())
	//			cout << "stack already empty\n";
	//		else {
	//			st.pop(po);
	//			cout << "PO #" << po << " popped\n";
	//		}
	//		break;
	//	}
	//	cout << "Please enter A to add a purchase order,\n"
	//		<< "P to process a PO, or Q to quit.\n";
	//}
	//cout << "Bуе\n";

	// #5
	//std::srand(std::time(0));
	//int qs = 10, hours = 100;
	//long cyclelimit = 60 * hours;
	//double perhour = 18;
	//Queue line(qs);
	//cout << "Enter a range of people per hour: ";
	//int min_ph, max_ph;
	//while (cin >> min_ph >> max_ph)
	//{
	//	if (min_ph < max_ph && min_ph>0) break;
	//	else cout << "Enter correct range of people per hour: ";
	//}
	//int array_size = max_ph - min_ph + 1;
	//double* results = new double[array_size];
	//for (int ph = min_ph, i = 0; ph <= max_ph; ph++, i++)
	//{
	//	double min_per_cust;
	//	min_per_cust = 60 / ph;
	//	Item temp;
	//	long turnaways = 0;
	//	long customers = 0;
	//	long served = 0;
	//	long sum_line = 0;
	//	int wait_time = 0;
	//	long line_wait = 0;
	//	for (int cycle = 0; cycle < cyclelimit; cycle++)
	//	{
	//		if (newcustomer(min_per_cust))
	//		{
	//			if (line.isfull())
	//				turnaways++;
	//			else {
	//				customers++;
	//				temp.set(cycle);
	//				line.enqueue(temp);
	//			}
	//		}
	//		if (wait_time <= 0 && !line.isempty())
	//		{
	//			line.dequeue(temp);
	//			wait_time = temp.ptime();
	//			line_wait += cycle - temp.when();
	//			served++;
	//		}
	//		if (wait_time > 0)
	//			wait_time--;
	//		sum_line += line.queuecount();
	//	}
	//	results[i] = abs(1 - ((double)line_wait / served));
	//}
	//double min = results[0];
	//int min_index = 0;
	//for (int i = 1; i < array_size; i++)
	//{
	//	if (min > results[i])
	//	{
	//		min = results[i];
	//		min_index = i;
	//	}
	//}
	//delete[] results;
	//cout << "Need "<<min_index<< " people per hour!\n";
#pragma endregion

#pragma region chapter13
	// #1
	//Cd c1("Beatles", "Capitol", 14, 35.5);
	//Classic c2 = Classic("Piano", "Alfred Brendel", "Philips", 2, 57.17);
	//Cd* pcd = &c1;
	//cout << "Using object directly:\n";
	//c1.Report();
	//c2.Report();
	//cout << "Using type cd * pointer to objects: \n";
	//pcd->Report();
	//pcd = &c2;
	//pcd->Report();
	//cout << "Calling a function with a Cd reference argument:\n";
	//Bravo(c1);
	//Bravo(c2);
	//cout << "Testing assigment: ";
	//Classic copy;
	//copy = c2;
	//copy.Report();

	// #3
	//BaseDMA shirt("portabelly", 8);
	//LacksDMA balloon("red", "Blimpo", 4);
	//HasDMA map("Mercator", "Buffali Keys", 5);
	//DMA* ref[4]{ &shirt, &balloon, &map };
	//cout << "Choose a class: 1 - baseDMA, 2 - lacksDMA, 3 hasDMA\n";
	//int n;
	//cin >> n;
	//switch (n)
	//{
	//case 1:	ref[3] = new BaseDMA();
	//	break;
	//case 2:	ref[3] = new LacksDMA();
	//	break;
	//case 3:	ref[3] = new HasDMA();
	//	break;
	//}
	//for (int i = 0; i < 4; i++)
	//{
	//	ref[i]->View();
	//}
	//delete ref[3];

	// #4
	//Port wine("santa", "stefano");
	//cout << wine << endl;
	//Port wine2(wine), wine3;
	//wine2 += 3;
	//wine2.Show();
	//wine3 = wine2;
	//wine3 -= 2;
	//wine3 += 100;
	//cout << wine3 << endl;
	//VintagePort vw("a", 2,"b",199);
	//cout << vw << endl;
	//VintagePort vw2;
	//cout << vw2;
#pragma endregion

#pragma region chapter14

	////// virtual_base_inherit ///////

	//Worker* lolas[5];
	//int ct;
	//for (ct = 0; ct < 5; ct++)
	//{
	//	char choice;
	//	cout << "Enter the employee category:\n"
	//		<< "w: waiter s: singer "
	//		<< "t: singing waiter q: quit\n";
	//	cin >> choice;
	//	while (strchr("wstq", choice) == NULL)
	//	{
	//		cout << "Please enter a w, s, t or q: ";
	//		cin >> choice;
	//	}
	//	if (choice == 'q') break;
	//	switch (choice)
	//	{
	//	case 'w': lolas[ct] = new Waiter;
	//		break;
	//	case 's': lolas[ct] = new Singer;
	//		break;
	//	case 't': lolas[ct] = new SingerWaiter;
	//		break;
	//	}
	//	cin.get();
	//	lolas[ct]->Set();
	//}
	//cout << "\nHere is your staff:\n";
	//int i;
	//for (i = 0; i < ct; i++)
	//{
	//	cout << endl;
	//	lolas[i]->Show();
	//}
	//for (i = 0; i < ct; i++)
	//	delete lolas[i];
	//cout << "Bye!";

	////// stack_template ///////

	//TemplateStack<string> st;
	//char ch;
	//string po;
	//cout << "Please enter A to add a purchase order, \n"
	//	<< "P to process a PO, or Q to quit.\n";
	//while (cin >> ch && toupper(ch) != 'Q')
	//{
	//	while (cin.get() != '\n')
	//		continue;
	//	if (!isalpha(ch))
	//	{
	//		cout << '\a';
	//		continue;
	//	}
	//	switch (toupper(ch))
	//	{
	//	case 'A':
	//		cout << "Enter a PO number to add: ";
	//		cin >> po;
	//		if (st.isfull())
	//			cout << "stack already full\n";
	//		else
	//			st.push(po);
	//		break;

	//	case 'P':
	//		if (st.isempty())
	//			cout << "stack alreafy empty\n";
	//		else
	//		{
	//			st.pop(po);
	//			cout << "PO #" << po << " popped\n";
	//		}
	//		break;
	//	}
	//	cout << "Please enter A to add a purchase order, \n"
	//		<< "P to process a PO, or Q to quit.\n";
	//}

	////// dynamic_stack_template ///////

	//srand(time(0));
	//cout << "Please enter stack size: ";
	//int stacksize;
	//cin >> stacksize;
	//DynamicTemplateStack<const char*> st(stacksize);
	//const int num = 10;
	//const char* in[num] = {
	//	" 1: Hank Gilgamesh", " 2: Kiki Ishtar",
	//	" 3: Betty Rocker", " 4: Ian Flagranti",
	//	" 5: Wolfgang Kibble", " 6: Portia Koop",
	//	" 7: Joy Almondo", " 8: Xaverie Paprika",
	//	" 9: Juan Moore", " 10: Misha Mache"
	//};
	//const char* out[num];
	//int processed = 0;
	//int nextin = 0;
	//while (processed < num)
	//{
	//	if (st.isempty())
	//		st.push(in[nextin++]);
	//	else if (st.isfull())
	//		st.pop(out[processed++]);
	//	else if (rand() % 2 && nextin < num)
	//		st.push(in[nextin++]);
	//	else
	//		st.pop(out[processed++]);
	//}
	//for (int i = 0; i < num; i++)
	//	cout << out[i] << endl;
	//cout << "Bye!";

	////// member_template ///////

	//beta<double> guy(3.5, 3);
	//cout << "T was set to double\n";
	//guy.Show();
	//cout << "V was set to T, which is double, then V was set to int\n";
	//cout << guy.blab(10, 2.3) << endl;
	//cout << "U w as set to int\n";
	//cout << guy.blab(10.0, 2.3) << endl;
	//cout << "U w as set to double\n";

	// #1 2
	//cout << "Enter name of wine: ";
	//char lab[50];
	//cin.getline(lab, 50);
	//cout << "Enter number of years: ";
	//int yrs;
	//cin >> yrs;
	//Wine2 holding(lab, yrs);
	//holding.GetBottles();
	//holding.Show();
	//const int YRS = 3;
	//int y[YRS] = { 1993, 1995, 1998 };
	//int b[YRS] = { 48,60,72 };
	//Wine2 more("Grape Red", YRS, y, b);
	//more.Show();
	//cout << "Total bottles for " << more.Label()
	//	<< ": " << more.sum() << endl;
	//cout << "Bye\n";

	// #3
	//QueueTp<Worker*> line(3);
	//int ct;
	//Worker* newworker;
	//while (!line.isfull())
	//{
	//	char choice;
	//	std::cout << "Enter the employee category:\n"
	//		<< "w: waiter s: singer "
	//		<< "t: singing waiter q: quit\n";
	//	cin >> choice;
	//	while (strchr("wstq", choice) == NULL)
	//	{
	//		std::cout << "Please enter a w, s, t or q: ";
	//		cin >> choice;
	//	}
	//	if (choice == 'q') break;
	//	switch (choice)
	//	{
	//	case 'w': newworker = new Waiter;
	//		break;
	//	case 's': newworker = new Singer;
	//		break;
	//	case 't': newworker = new SingerWaiter;
	//		break;
	//	}
	//	line.enqueue(newworker);
	//	cin.get();
	//	newworker->Set();
	//}
	//std::cout << "\nQueue is full!\n\n";
	//while (!line.isempty())
	//{
	//	line.dequeue(newworker);
	//	cout << newworker->getName() << " deleted\n";
	//}

	// #4
	//Person14* lolas[5];
	//int ct;
	//for (ct = 0; ct < 5; ct++)
	//{
	//	char choice;
	//	cout << "Enter the employee category:\n"
	//		<< "p: person g: gunslinger "
	//		<< "t: pokerPlayer b: bad dude q: quit\n";
	//	cin >> choice;
	//	while (strchr("pgtbq", choice) == NULL)
	//	{
	//		cout << "Please enter a p, g, t, b or q: ";
	//		cin >> choice;
	//	}
	//	if (choice == 'q') break;
	//	switch (choice)
	//	{
	//	case 'p': lolas[ct] = new Person14("Arthur", "Morgan");
	//		break;
	//	case 'g': lolas[ct] = new Gunslinger("Kiki", "Ishtar", 5, 2);
	//		break;
	//	case 't': lolas[ct] = new PokerPlayer("Hank", "Gilgamesh");
	//		break;
	//	case 'b': lolas[ct] = new BadDude("Juan", "Moore", 1, 1);
	//		break;
	//	}
	//	cin.get();
	//}
	//cout << "\nHere is your staff:\n";
	//int i;
	//for (i = 0; i < ct; i++)
	//{
	//	cout << endl;
	//	lolas[i]->Show();
	//}
	//for (i = 0; i < ct; i++)
	//	delete lolas[i];
	//cout << "Bye!";

	// #5
	//employee em("Trip", "Harris", "Thumper");
	//cout << em << endl;
	//em.ShowAll();
	//cout << endl;
	//manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	//cout << ma << endl;
	//ma.ShowAll();
	//cout << endl;
	//fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	//cout << fi << endl;
	//fi.ShowAll();
	//cout << endl;
	//highfink hf(ma, "Curly Kew");
	//hf.ShowAll();
	//cout << "Press key for next phase:\n";
	//cin.get();
	//highfink hf2;
	//hf2.SetAll();
	//cout << "Using an abstr_emp * pointer:\n";
	//abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
	//for (int i = 0; i < 4; i++)
	//	tri[i]->ShowAll();
#pragma endregion

#pragma region chapter15
	// listing 15.6
	//queueTP<string> cs(5);
	//string temp;
	//while (!cs.isfull())
	//{
	//	cout << "Please enter your name. You will be served in the order of arrival.\nname: ";
	//	getline(cin, temp);
	//	cs.enqueue(temp);
	//}
	//cout << "The queue is full. Processing beggins!\n";
	//while (!cs.isempty())
	//{
	//	cs.dequeue(temp);
	//	cout << "Now processing " << temp << "...\n";
	//}

	// exceptions
	//double x, y, z;
	//cout << "Enter two numbers: ";
	//while (cin >> x >> y)
	//{
	//	try
	//	{
	//		z = hmean(x, y);
	//		cout << "Harmonic mean of " << x << " and " << y
	//			<< " is " << z << endl;
	//		cout << "Geometric mean of " << x << " and " << y
	//			<< " is " << gmean(x,y) << endl;
	//		cout << "Enter next set of numbers <q to quit>: ";
	//	}
	//	catch (bad_hmean& bg)
	//	{
	//		bg.mesg();
	//		cout << "Try again.\n";
	//		continue;
	//	}
	//	catch (bad_gmean& hg)
	//	{
	//		cout << hg.mesg();
	//		cout << "Values used: " << hg.v1 << ", " << hg.v2
	//			<< "\nSorry, you dont get to play anymore.\n";
	//		break;
	//	}
	//}

	// inherit exceptions
	/*double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};
	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};
	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);
	cout << "First try block: \n";
	try {
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{
			cout << sales1[i] << " ";
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; ++i)
		{
			cout << sales2[i] << " ";
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block1.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad_index: " << bad.bi_val() << endl;
	}
	cout << "\nNext try block:\n";
	try {
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block2.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "Done\n";*/

	// RTTI
	//srand(time(0));
	//Grand* pg;
	//Superb* ps;
	//for (int i = 0; i < 5; i++)
	//{
	//	pg = GetOne();
	//	cout << "Now processing type " << typeid(*pg).name() << ".\n";
	//	pg->Speak();
	//	if (ps = dynamic_cast<Superb*>(pg))
	//		ps->Say();
	//	if (typeid(Magnificent) == typeid(*pg))
	//		cout << "Yes, you're really magnificent.\n";
	//}

	// #1
	//Tv s42;
	//cout << "Initial settings for 42\" TV:\n";
	//s42.settings();
	//s42.onoff();
	//s42.chanup();
	//cout << "\nAdjusted settings for 42\" TV:\n";
	//s42.settings();
	//Remote grey;
	//grey.set_chan(s42, 10);
	//grey.volup(s42);
	//grey.volup(s42);
	//cout << "\n42\" setting safter using remote\n";
	//s42.settings();
	//Tv s58(Tv::On);
	//s58.set_mode();
	//grey.set_chan(s58, 28);
	//cout << "\n58\" settings:\n";
	//s58.settings();
	//grey.view_mode();
	//s58.change_remotemode(grey);
	//grey.view_mode();
	//s42.change_remotemode(grey);
	//grey.view_mode();

	// #2-3
	//double x, y, z;
	//cout << "Enter two numbers: ";
	//while (cin >> x >> y)
	//{
	//	try
	//	{
	//		z = hmean(x, y);
	//		cout << "Harmonic mean of " << x << " and " << y
	//			<< " is " << z << endl;
	//		cout << "Geometric mean of " << x << " and " << y
	//			<< " is " << gmean(x,y) << endl;
	//		cout << "Enter next set of numbers <q to quit>: ";
	//	}
	//	catch (base_exc& hg)
	//	{
	//		cout << hg.what();
	//		break;
	//	}
	//}

	// #4
	//double vals1[12] =
	//{
	//	1220, 1100, 1122, 2212, 1232, 2334,
	//	2884, 2393, 3302, 2922, 3002, 3544
	//};
	//double vals2[12] =
	//{
	//	12, 11, 22, 21, 32, 34,
	//	28, 29, 33, 29, 32, 35
	//};
	//Sales sales1(2011, vals1, 12);
	//LabeledSales sales2("Blogstar", 2012, vals2, 12);
	//cout << "First try block: \n";
	//try {
	//	int i;
	//	cout << "Year = " << sales1.Year() << endl;
	//	for (i = 0; i < 12; ++i)
	//	{
	//		cout << sales1[i] << " ";
	//		if (i % 6 == 5)
	//			cout << endl;
	//	}
	//	cout << "Year = " << sales2.Year() << endl;
	//	cout << "Label = " << sales2.Label() << endl;
	//	for (i = 0; i <= 12; ++i)
	//	{
	//		cout << sales2[i] << " ";
	//		if (i % 6 == 5)
	//			cout << endl;
	//	}
	//	cout << "End of try block1.\n";
	//}
	//catch (Sales::bad_index& bad)
	//{
	//	cout << bad.what();
	//	if (typeid(LabeledSales::nbad_index&) == typeid(bad))
	//	{
	//		LabeledSales::nbad_index& nbi = dynamic_cast<LabeledSales::nbad_index&>(bad);
	//		cout << "Company: " << nbi.label_val() << endl;
	//	}
	//	cout << "bad_index: " << bad.bi_val() << endl;
	//}
	//cout << "\nNext try block:\n";
	//try {
	//	sales2[2] = 37.5;
	//	sales1[20] = 23345;
	//	cout << "End of try block2.\n";
	//}
	//catch (Sales::bad_index& bad)
	//{
	//	cout << bad.what();
	//	if (typeid(LabeledSales::nbad_index&) == typeid(bad))
	//	{
	//		LabeledSales::nbad_index& nbi = dynamic_cast<LabeledSales::nbad_index&>(bad);
	//		cout << "Company: " << nbi.label_val() << endl;
	//	}
	//	cout << "bad index: " << bad.bi_val() << endl;
	//}
	//cout << "Done\n";
#pragma endregion

#pragma region chapter16
	// #1-2 
	//string str;
	//getline(cin, str);
	//clean_string(str);
	//cout << "Cleaned string: " << str << endl;
	//if (check_palindrome(str)) cout << "it is a palindrome!";
	//else cout << "it is not a palindrome";

	// algorithm
	//vector<string> words;
	//cout << "Enter words (enter quit to quit):\n";
	//string input;
	//while (cin >> input && input != "quit")
	//	words.push_back(input);
	//cout << "You entered the following words:\n";
	//for_each(words.begin(), words.end(), al_display);
	//cout << endl;
	//set<string> wordset;
	//transform(words.begin(), words.end(),
	//	insert_iterator<set<string> >(wordset, wordset.begin()), ToLower);
	//cout << "\nAlphabetic list of words:\n";
	//for_each(wordset.begin(), wordset.end(), al_display);
	//cout << endl;
	//map<string, int> wordmap;
	//set<string>::iterator si;
	//for (si = wordset.begin(); si != wordset.end(); si++)
	//	wordmap[*si] = count(words.begin(), words.end(), *si);
	//cout << "\nWord frequency:\n";
	//for (si = wordset.begin(); si != wordset.end(); si++)
	//	cout << *si << ": " << wordmap[*si] << endl;

	// #3
	//ifstream fin;
	//fin.open("chapter16/vwords.txt");
	//vector<string> words;
	//string str;
	//if (fin.is_open())
	//{
	//	while (!fin.eof())
	//	{
	//		fin >> str;
	//		words.push_back(str);
	//	}
	//}
	//fin.close();
	//std::srand(std::time(0));
	//char play;
	//cout << "Will you play a word game? <y/n> ";
	//cin >> play;
	//play = tolower(play);
	//while (play == 'y')
	//{
	//	string target = words[std::rand() % words.size()];
	//	int length = target.length();
	//	string attempt(length, '-');
	//	string badchars;
	//	int guesses = 6;
	//	cout << "Guess my secret word. It has " << length
	//		<< " letters, and you guess\none letter at time."
	//		<< " You get " << guesses
	//		<< " wrong guesses.\n";
	//	cout << "Your word: " << attempt << endl;
	//	while (guesses > 0 && attempt != target)
	//	{
	//		char letter;
	//		cout << "Guess a letter: ";
	//		cin >> letter;
	//		if (badchars.find(letter) != string::npos
	//			|| attempt.find(letter) != string::npos)
	//		{
	//			cout << "You already guessed that. Try again.\n";
	//			continue;
	//		}
	//		int loc = target.find(letter);
	//		if (loc == string::npos)
	//		{
	//			cout << "Oh, bad guess!\n";
	//			guesses--;
	//			badchars += letter;
	//		}
	//		else
	//		{
	//			cout << "Good guess!\n";
	//			attempt[loc] = letter;
	//			//проверить не появляется ли буква еще раз
	//			loc = target.find(letter, loc + 1);
	//			while (loc != string::npos) {
	//				attempt[loc] = letter;
	//				loc = target.find(letter, loc + 1);
	//			}
	//		}
	//		cout << "You word: " << attempt << endl;
	//		if (attempt != target)
	//		{
	//			if (badchars.length() > 0)
	//				cout << "Bad choices: " << badchars << endl;
	//			cout << guesses << " bad guesses left\n";
	//		}
	//	}
	//	if (guesses > 0)
	//		cout << "That's right!\n";
	//	else
	//		cout << "Sorry, the word is " << target << ".\n";
	//	cout << "Will you play another? <y/n> ";
	//	cin >> play;
	//	play = tolower(play);
	//}

	//  #4
	//long arr[8] = { 3,5,1,6,3,5,6,5 };
	//cout<<reduce(arr, 8);

	// #5
	//long l_arr[8] = { 3,5,1,6,3,5,6,5 };
	//cout << t_reduce(l_arr, 8) << endl;
	//string s_arr[8] = { "one", "two", "three", "one", "two", "four", "seven", "seven" };
	//cout << t_reduce(s_arr, 8) << endl;

	// #6
	//srand(time(0));
	//int qs = 10, hours = 100;
	//long cyclelimit = 60 * hours;
	//double perhour = 18;
	//queue<Customer> line;
	//cout << "Enter a range of people per hour: ";
	//int min_ph, max_ph;
	//while (cin >> min_ph >> max_ph)
	//{
	//	if (min_ph < max_ph && min_ph>0) break;
	//	else cout << "Enter correct range of people per hour: ";
	//}
	//int array_size = max_ph - min_ph + 1;
	//double* results = new double[array_size];
	//for (int ph = min_ph, i = 0; ph <= max_ph; ph++, i++)
	//{
	//	double min_per_cust;
	//	min_per_cust = 60 / ph;
	//	Item temp;
	//	long turnaways = 0;
	//	long customers = 0;
	//	long served = 0;
	//	long sum_line = 0;
	//	int wait_time = 0;
	//	long line_wait = 0;
	//	for (int cycle = 0; cycle < cyclelimit; cycle++)
	//	{
	//		if (newcustomer(min_per_cust))
	//		{
	//			if (line.size() == qs)
	//				turnaways++;
	//			else {
	//				customers++;
	//				temp.set(cycle);
	//				line.push(temp);
	//			}
	//		}
	//		if (wait_time <= 0 && !line.empty())
	//		{
	//			line.pop();
	//			wait_time = temp.ptime();
	//			line_wait += cycle - temp.when();
	//			served++;
	//		}
	//		if (wait_time > 0)
	//			wait_time--;
	//		sum_line += line.size();
	//	}
	//	results[i] = abs(1 - ((double)line_wait / served));
	//}
	//double min = results[0];
	//int min_index = 0;
	//for (int i = 1; i < array_size; i++)
	//{
	//	if (min > results[i])
	//	{
	//		min = results[i];
	//		min_index = i;
	//	}
	//}
	//delete[] results;
	//cout << "Need "<<min_index<< " people per hour!\n";

	// #7
	//vector<int> loto = Lotto(51, 6);
	//for (auto num : loto)
	//	cout << num << " ";

	// #8
	//char ch;
	//string po;
	//vector<string> matt, patt, together;
	//int c;
	//cout << "Select an action:\n"
	//	<< "M: add Matt's friends\t"
	//	<< "P: add Patt's friends\n"
	//	<< "U: unite the lists\t"
	//	<< "Q: quit\n";
	//while (cin >> ch && toupper(ch) != 'Q')
	//{
	//	while (cin.get() != '\n')
	//		continue;
	//	if (!isalpha(ch))
	//	{
	//		cout << '\a';
	//		continue;
	//	}
	//	switch (toupper(ch))
	//	{
	//	case 'M':
	//		cout << "How many friends Matt wants to invite: ";
	//		cin >> c;
	//		add_list(matt, c);
	//		cout << "Here is the list of Matt's invitees:\n";
	//		show_list(matt);
	//		break;
	//	case 'P':
	//		cout << "How many friends Patt wants to invite: ";
	//		cin >> c;
	//		add_list(patt, c);
	//		cout << "Here is the list of Patt's invitees:\n";
	//		show_list(patt);
	//		break;
	//	case 'U':
	//		together.insert(together.end(), matt.begin(), matt.end());
	//		together.insert(together.end(), patt.begin(), patt.end());
	//		sort(together.begin(), together.end());
	//		together.erase(unique(together.begin(), together.end()), together.end());
	//		cout << "This is their list:\n";
	//		show_list(together);
	//		break;
	//	}
	//	cout << "Select an action:\n"
	//		<< "M: add Matt's friends\t"
	//		<< "P: add Patt's friends\n"
	//		<< "U: unite the lists\t"
	//		<< "Q: quit\n";
	//}

	// #9
	/*int elems = 10000;
	srand(time(0));
	clock_t start, end;
	vector<int> vi0;
	for(int i=0; i< elems; i++)
		vi0.push_back(rand());
	vector<int> vi(vi0);
	list<int> li(vi.begin(), vi.end());
	start = clock();
	sort(vi.begin(), vi.end());
	end = clock();
	cout <<"Sort vector of "<<elems<<" numbers takes ~"<< (double)(end - start) / CLOCKS_PER_SEC << "sec\n";
	start = clock();
	li.sort();
	end = clock();
	cout << "Sort list of " << elems << " numbers takes ~" << (double)(end - start) / CLOCKS_PER_SEC << "sec\n"; (vi0.begin(), vi.end(), back_inserter(li));
	copy(vi0.begin(), vi0.end(), li.begin());
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	cout << "Sort list of " << elems << " numbers via vector takes ~" << (double)(end - start) / CLOCKS_PER_SEC << "sec\n"; (vi0.begin(), vi.end(), back_inserter(li));*/

	// 16.9
	//vector<Review> books;
	//
	//while (FillRewview(temp))
	//	books.push_back(temp);
	//if (books.size() > 0)
	//{
	//	cout << "Thank you. You entered the following "
	//		<< books.size() << " ratings:\n"
	//		<< "Rating\tBook\n";
	//	for_each(books.begin(), books.end(), ShowReview);
	//	sort(books.begin(), books.end());
	//	cout << "Sorted Ьу title: \nRating\tBook\n";
	//	for_each(books.begin(), books.end(), ShowReview);
	//	sort(books.begin(), books.end(), worseThan);
	//	cout << "Sorted by rating: \nRating\tBook\n";
	//	for_each(books.begin(), books.end(), ShowReview);
	//	random_shuffle(books.begin(), books.end());
	//	cout << "After shuffling: \nRating\tBook\n";
	//	for_each(books.begin(), books.end(), ShowReview);
	//}
	//else
	//	cout << "No entries.";

	// #10
	//std::vector<std::shared_ptr<Review> > books;
	//Review temp;

	//while (FillReview(temp))
	//{
	//	std::shared_ptr<Review> t(new Review);
	//	t->title = temp.title;
	//	t->rating = temp.rating;
	//	t->price = temp.price;
	//	books.push_back(t);
	//}
	//show_menu();

	//char choice;
	//while (std::cin >> choice && choice != 'q')
	//{
	//	switch (choice)
	//	{
	//	case 'a':
	//		cout << "Sort by title:\nRating\tTitle\tPrice\n";
	//		sort(books.begin(), books.end(), sortTitle);
	//		for_each(books.begin(), books.end(), ShowReview);
	//		show_menu();
	//		break;
	//	case 'b':
	//		cout << "Title reserve output:\nRating\tTitle\tPrice\n";
	//		for_each(books.rbegin(), books.rend(), ShowReview);
	//		show_menu();
	//		break;
	//	case 'c':
	//		cout << "Sort by rating:\nRating\tTitle\tPrice\n";
	//		sort(books.begin(), books.end(), sortRating);
	//		for_each(books.begin(), books.end(), ShowReview);
	//		show_menu();
	//		break;
	//	case 'd':
	//		cout << "Sort by price:\nRating\tTitle\tPrice\n";
	//		sort(books.begin(), books.end(), sortPrice);
	//		for_each(books.begin(), books.end(), ShowReview);
	//		show_menu();
	//		break;
	//	}
	//}
	//cout << "Done!";
#pragma endregion

#pragma region chapter17
	// #1
	//int characterCount = 0;
	//char ch, forbiddenCh = '$';
	//cin.get(ch);
	//while (ch != forbiddenCh)
	//{
	//	cout << ch;
	//	characterCount++;
	//	cin.get(ch);
	//}
	//cout << endl << characterCount << " characters up to "<< forbiddenCh;
	//cout << endl << "the " << ch << " character is left in the stream";

	// #2
	//if (argc == 1)
	//{
	//	cerr << "Usage: " << argv[0] << " filename(s)\n";
	//	exit(EXIT_FAILURE);
	//}
	//cout << "Enter text to file: ";
	//string txt;
	//cin >> txt;
	//ofstream fout(argv[1]);
	//fout << txt;
	//cout << "Done.";

	// #3
	//if (argc < 3)
	//{
	//	cerr << "Usage: " << argv[0] << " filename(s)\nToo few arguments";
	//	exit(EXIT_FAILURE);
	//}
	//ifstream fin(argv[1]);
	//ofstream fout(argv[2]);
	//char ch;
	//if (!fin.is_open())
	//{
	//	cerr << "Can't open "<< argv[1]<<" file";
	//	fin.clear();
	//	exit(EXIT_FAILURE);
	//}
	//while (fin.get(ch))
	//	fout << ch;
	//cout << "File copied";

	// #4
	//ifstream fin("Debug/a.txt");
	//ifstream fin2("Debug/b.txt");
	//ofstream fout("Debug/c.txt");
	//string line;
	//if (fin.is_open() && fin2.is_open())
	//{
	//	while (!fin.eof() || !fin2.eof())
	//	{
	//		string s1, s2;
	//		getline(fin, s1);
	//		getline(fin2, s2);
	//		line = s1 + ' ' + s2;
	//		fout << line << "\n";
	//	}
	//}
	//else
	//{
	//	cerr << "Can't open file";
	//	exit(EXIT_FAILURE);
	//}
	//cout << "Done";

	// #5
	//ifstream fin("chapter17/matt.txt");
	//ifstream fin2("chapter17/patt.txt");
	//if (!fin.is_open() || !fin2.is_open() )
	//{
	//	cerr << "Can't open file";
	//	exit(EXIT_FAILURE);
	//}
	//vector<string> matt, patt, mapat;
	//get_from_file(matt, fin);
	//get_from_file(patt, fin2);
	//sort_n_show(matt, "Matt");
	//cout << endl;
	//sort_n_show(patt, "Patt");
	//mapat.insert(mapat.end(), matt.begin(), matt.end());
	//mapat.insert(mapat.end(), patt.begin(), patt.end());
	//sort(mapat.begin(), mapat.end());
	//mapat.erase(unique(mapat.begin(), mapat.end()), mapat.end());
	//cout << endl;
	//sort_n_show(mapat, "Their");
	//ofstream fout("chapter17/mattnpatt.txt");
	//for (auto s : mapat)
	//	fout << s << endl;

	// #6
	//const int workers = 2;
	//abstr_emp* pc[workers];
	//int i = 0;
	//ifstream fin("chapter17/17_6.txt");
	//vector<string> lines;
	//get_from_file(lines, fin);
	//for (auto line : lines)
	//{
	//	if (line.empty()) break;
	//	vector<string> words;
	//	stringstream ssstream;
	//	ssstream << line;
	//	string word;
	//	while (ssstream >> word) words.push_back(word);
	//	switch (words[0][0])
	//	{
	//		case 'a': pc[i] = new employee(words[1], words[2], words[3]); break;
	//		case 'b': pc[i] = new manager(words[1], words[2], words[3], std::stoi(words[4])); break;
	//		case 'c': pc[i] = new fink(words[1], words[2], words[3], words[4]); break;
	//		case 'd': pc[i] = new highfink(words[1], words[2], words[3], words[4], std::stoi(words[5])); break;
	//	}
	//	i++;
	//}
	//fin.close();
	//ofstream fout("chapter17/17_6.txt");
	//for (; i < workers; i++)
	//{
	//	char choice;
	//	cout << "Choice a employee(q to quit):\n"
	//		<< "a) employee\tb) manager\n"
	//		<< "c) fink\td) highfink\n";
	//	cin >> choice;
	//	while (strchr("abcdq", choice) == NULL)
	//	{
	//		cout << "Please enter a a, b, c, d or q: ";
	//		cin >> choice;
	//	}
	//	if (choice == 'q') break;
	//	switch (tolower(choice))
	//	{
	//	case 'a': pc[i] = new employee(); break;
	//	case 'b': pc[i] = new manager(); break;
	//	case 'c': pc[i] = new fink(); break;
	//	case 'd': pc[i] = new highfink(); break;
	//	}
	//	pc[i]->SetAll();
	//	//pc[i]->WriteAll(fout);
	//	cin.get();
	//}
	//cout << "\nHere is your staff:\n";
	//for (int j = 0; j < workers; j++)
	//{
	//	pc[j]->ShowAll();
	//	pc[j]->WriteAll(fout);
	//	//delete pc[j];
	//}
	//cout << "Bye!";

	// #7
	//vector<string> vostr;
	//string temp;
	//cout << "Enter strings(empty line to quit):\n";
	//while (getline(cin, temp) && temp[0] != '\0')
	//	vostr.push_back(temp);
	//cout << "Here is your input.\n";
	//for_each(vostr.begin(), vostr.end(), ShowStr);

	//ofstream fout("chapter17/17_7.txt", ios_base::out | ios_base::binary);
	//for_each(vostr.begin(), vostr.end(), Store(fout));
	//fout.close();

	//vector<string> vistr;
	//ifstream fin("chapter17/17_7.txt", ios_base::in | ios_base::binary);
	//if (!fin.is_open())
	//{
	//	cerr << "Could not open file for input.\n";
	//	exit(EXIT_FAILURE);
	//}
	//GetStrs(fin, vistr);
	//cout << "\nHere are the strings read from file:\n";
	//for_each(vistr.begin(), vistr.end(), ShowStr);
#pragma endregion

#pragma region chapter18
	// using recursion in template functions with variable number of arguments
	//int n = 14;
	//double х = 2.71828;
	//string mr = "Mr. String objects!";
	//show_list(n, х);
	//show_list(х* х, '!', 7, mr);

	// #1
	//auto q = average_list({ 15.4, 10.7, 9.0 });
	//cout << q << endl;
	//cout << average_list({ 20, 30, 19, 17, 45, 38 }) << endl;
	//auto ad = average_list<double>({ 'A', 70, 65.33 });
	//cout << ad << endl;

	// #2
	//Cpmv apple("green", "small");
	//Cpmv melon("yellow", "big");
	//Cpmv pear(move(apple));
	//Cpmv watermelon(melon);
	//watermelon = move(pear);
	//Cpmv lime(watermelon);
	//lime = watermelon + melon;

	// #3
	cout << sum_values(2, 4, 5, 2.3);

#pragma endregion
}

#pragma region func_ch7
// #1
double garmon(double x, double y)
{
	return 2.0 * x * y / (x + y);
}
// #2
void fill_games(int arr[], int size)
{
	int i = 0;
	cout << "game N_" << i + 1 << ": ";
	while (i<size && cin >> arr[i]) {
		i++;
		if (i < size) {
			cout << "game N_" << i + 1 << ": ";
		}
	}
}
void show_games(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
double avg_games(int arr[], int size)
{
	double avg = 0.0f;
	for (int i = 0; i < size; i++)
	{
		avg += arr[i];
	}
	return avg / size;
}
// #3
void show_box(box b) {
	cout << "maker: " << b.maker << "\theight: " << b.height << "\twidth: " << b.width << "\tlenth: " << b.length << "\tvolume: " << b.volume << endl;
}
void volume_box(box* b)
{
	b->volume = b->height * b->length * b->width;
}
// #4
long double probaЬility(unsigned numbers, unsigned picks, unsigned diap)
{
	if (diap == 0) return 0;
	long double result = 1.0, n, tmp;
	unsigned р;
	for (n = numbers, р = picks; р > 0; n--, р--)
		result = result * n / р;
	tmp = result / diap;
	return tmp;
}
// #5
int fact(int n)
{
	if (n == 0 || n == 1) return 1;
	if (n > 0) return n * fact(n - 1);
}
// #6
int fill_array(double arr[], int size)
{
	int i = 0;
	cout << "N_" << i + 1 << ": ";
	while (i<size && cin >> arr[i]) {
		i++;
		if (i < size) {
			cout << "N_" << i + 1 << ": ";
		}
	}
	return i;
}
void show_array(const double arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void reverse_array(double arr[], int size)
{
	double tmp;
	for (int i = 0; i < size / 2; i++)
	{
		tmp = arr[size - i - 1];
		arr[size - i - 1] = arr[i];
		arr[i] = tmp;
	}
}
// #7
double* fill_array2(double* begin, double* end)
{
	double temp;
	int i = 0;
	double* tmp;
	for (tmp = begin; tmp != end; tmp++)
	{
		cout << "Enter value #" << (i + 1) << " : ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Input process terminated. \n";
			break;
		}
		else if (temp < 0)
			break;
		*tmp = temp;
		i++;
	}
	return tmp;
}
void show_array2(const double* begin, const double* end)
{
	const double* tmp;
	int i = 0;
	for (tmp = begin; tmp != end; tmp++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *tmp << endl;
		i++;
	}
}
void revalue(double* begin, double* end, double r)
{
	for (double* tmp = begin; tmp != end; tmp++)
		*tmp *= r;
}
// #8
void fill_seasons(double pa[])
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << ses[i] << " expenses: ";
		cin >> pa[i];
	}
}
void show_seasons(const double da[])
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << ses[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << " Total Expenses: $" << total << endl;
}
void fill_seasons(ses_array* pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << ses[i] << " expenses: ";
		cin >> pa->aue[i];
	}
}
void show_seasons(const ses_array* pa)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << ses[i] << ": $" << pa->aue[i] << endl;
		total += pa->aue[i];
	}
	cout << " Total Expenses: $" << total << endl;
}
// #9
int getinfo(student pa[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		char tmp[SLEN];
		cout << "St #" << i + 1 << ".\n\tEnter name: ";
		if (cin >> tmp)
		{
			*pa[i].fullname = *tmp;
			cout << "\tEnter hobby: ";
			cin >> pa[i].hobby;
			cout << "\tEnter oop: ";
			cin >> pa[i].ooplevel;
		}
		else {
			cin.clear();
			return i;
		}
	}
	return i;
}
void display1(student st)
{
	cout << "Name: " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "OOP: " << st.ooplevel << endl;
}
void display2(const student* ps) {
	cout << "Name: " << ps->fullname << endl;
	cout << "Hobby: " << ps->hobby << endl;
	cout << "OOP: " << ps->ooplevel << endl;
}
void displayЗ(const student ра[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Name: " << ра[i].fullname << endl;
		cout << "Hobby: " << ра[i].hobby << endl;
		cout << "OOP: " << ра[i].ooplevel << endl;
	}
}
// #10
double calculate(double (*pf)(double, double), double x, double y)
{
	return (*pf)(x, y);
}
double summation(double x, double y)
{
	return x + y;
}
double subtraction(double x, double y)
{
	return x - y;
}
double multiplication(double x, double y)
{
	return x * y;
}
double division(double x, double y)
{
	return (y == 0) ? 0 : x / y;
}

#pragma endregion

#pragma region func_ch8
// #1
void print_str(const char* str)
{
	cout << str << endl;
	call_count++;
}
void print_str(const char* str, int n)
{
	if (n != 0)
		for (int i = 0; i < call_count; i++)
			cout << str << endl;
	else cout << str << endl;
	call_count++;
}
// #2
void fill_candybar(CandyBar& candy, const char* n, double  w, int c)
{
	candy.name = n;
	candy.weight = w;
	candy.cal = c;
}
void show_candybar(const CandyBar& c)
{
	cout << " name is: " << c.name;
	cout << "\t weight is: " << c.weight;
	cout << "\t calories is: " << c.cal << endl;
}
// #3
void upper_string(string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		str[i] = toupper(str[i]);
	}
}
// #4
void _string_set(_string& str, char* chr)
{
	str.str = new char[strlen(chr) + 1];
	strcpy(str.str, chr);
	str.ct = strlen(chr);
}
void _string_show(const _string& str, int count)
{
	for (int n = 0; n < count; n++)
	{
		for (int i = 0; i < str.ct; i++)
		{
			cout << str.str[i];
		}
		cout << endl;
	}
}
void _string_show(const char* chr, int count)
{
	for (int n = 0; n < count; n++)
	{
		cout << chr << endl;
	}
}
// #5
template <class T>
T max5(T arr[5])
{
	T temp = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > temp) temp = arr[i];
	}
	return temp;
}
// #6
template <class T>
T maxn(T arr[], int n)
{
	T temp = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > temp) temp = arr[i];
	}
	return temp;
}
template <> char* maxn<char*>(char* arr[], int n)
{
	char* temp = arr[0];
	int longest = strlen(arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (strlen(arr[i]) > longest)
		{
			temp = arr[i];
			longest = strlen(arr[i]);
		}
	}
	return temp;
}
// #7
template <typename T>
T SumArray(T arr[], int n)
{
	cout << "template A\n ";
	T temp = 0;
	for (int i = 0; i < n; i++)
		temp += arr[i];
	return temp;
}
template <typename T>
T* SumArray(T* arr[], int n)
{
	cout << "template B\n ";
	T* temp = arr[0];
	for (int i = 1; i < n; i++)
		*temp += *arr[i];
	return temp;
}
#pragma endregion

#pragma region func_ch9
// #2
void strcount(string str)
{
	static int total = 0;
	int count = 0, i = 0;
	cout << "\"" << str << "\" contains\n";
	while (str[i++])
		count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
#pragma endregion

#pragma region func_ch11
// #5
void display(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		cout << st;
	}
}
#pragma endregion

#pragma region func_ch12
// #5
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
#pragma endregion

#pragma region func_ch13
// #1
void Bravo(const Cd& disk)
{
	disk.Report();
}
#pragma endregion

#pragma region func_ch15
double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean2(a, b);
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean2(a, b);
	return sqrt(a * b);
}
Grand* GetOne()
{
	Grand* p;
	switch (rand() % 3)
	{
	case 0:
		p = new Grand(rand() % 100);
		break;
	case 1:
		p = new Superb(rand() % 100);
		break;
	case 2:
		p = new Magnificent(rand() % 100, 'A' + rand() % 26);
		break;
	}
	return p;
}
#pragma endregion

#pragma region func_ch16
void clean_string(string& str)
{
	string newstr;
	for (int i = 0; i < str.size(); i++)
		if (isalpha(str[i]))
			newstr.push_back(tolower(str[i]));
	str = newstr;
}
bool check_palindrome(const string& str)
{
	if (str.size() == 0) return false;
	for (int i = 0; i < str.size() / 2; i++)
		if (str[i] != str[str.size() - i - 1])
			return false;
	return true;
}

string& ToLower(string& st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}
void al_display(const string& s)
{
	cout << s << " ";
}
// #4-5
int reduce(long ar[], int n)
{
	//for (int i = 0; i < n - 1; i++)
	//	for (int j = 0; j < n - 1 - i; j++)
	//		if (ar[j] > ar[j + 1]) 
	//		{
	//			int temp = ar[j];
	//			ar[j] = ar[j+1];
	//			ar[j + 1] = temp;
	//		}
	//int c = 1;
	//for (int i = 1; i < n; i++)
	//{
	//	if (ar[i] != ar[i - 1]) c++;
	//}

	// STL #5
	vector<long> v(ar, ar + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v.size();
}
// #7
vector<int> Lotto(int range, int count)
{
	vector<int> result, all_range;
	if (count >= range) return result;
	for (int i = 0; i <= range; i++)
		all_range.push_back(i);
	random_shuffle(all_range.begin(), all_range.end());
	//copy(all_range.begin(), all_range.end(), result.begin());
	for (int i = 0; i < count; i++)
		result.push_back(all_range.at(i));
	sort(result.begin(), result.end());
	return result;
}
// #8
void add_list(vector<string>& friend_list, int c)
{
	for (int i = 0; i < c; i++)
	{
		cout << "Enter friend's name: ";
		string name;
		cin >> name;
		friend_list.push_back(name);
	}
}
void show_list(const vector<string>& friend_list)
{
	for (auto fr : friend_list)
		cout << fr << endl;
}
// #10
bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}
bool sortRating(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	return (r1->rating < r2->rating) ? true : false;
}
bool sortTitle(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	return (r1->title < r2->title) ? true : false;
}
bool sortPrice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2)
{
	return (r1->price < r2->price) ? true : false;
}
bool FillReview(Review& rr)
{
	cout << "Enter book title(quit to quit): ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> rr.rating;
	if (!cin)
		return false;
	cout << "Enter book price: ";
	cin >> rr.price;
	if (!cin)
		return false;
	while (cin.get() != '\n')
		continue;
	return true;
}
void ShowReview(const shared_ptr<Review>& rr)
{
	cout << rr->rating << "\t" << rr->title << "\t" << rr->price << endl;
}
void show_menu()
{
	cout << "Please select the sort:\n"
		<< "a.sort by title\tb.sort by title reserve\n"
		<< "c.sort by rating\td.sort by price\t"
		<< "q.quit" << endl;
}
#pragma endregion

#pragma region func_ch17
void get_from_file(vector<string>& v, ifstream& f)
{
	while (!f.eof())
	{
		string s1;
		getline(f, s1);
		v.push_back(s1);
	}
}

void sort_n_show(vector<string>& v, string name)
{
	cout << name << "'s friends:\n";
	sort(v.begin(), v.end());
	for (auto kent : v)
		cout << kent << endl;
}

void ShowStr(const string& s)
{
	cout << s << endl;
}

void GetStrs(ifstream& f, vector<string> vs)
{
	size_t len = 0;
	string str;
	char ch;
	while (f.peek() && !f.eof())
	{
		f.read((char*)&len, sizeof(size_t));
		for (size_t i = 0; i < len; i++)
		{
			f.read(&ch, sizeof(char));
			str.push_back(ch);
		}
		vs.push_back(str);
		str.clear();
	}
}
#pragma endregion