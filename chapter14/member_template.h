#pragma once
using namespace std;
template <typename T>
class beta
{
private:
	template <typename V>
	class hold
	{
	private:
		V val;
	public:
		hold(V v = 0) : val(v) {}
		void show() const { cout << val << endl; }
		V Value() const { return val; }
	};
	hold<T> q;
	hold<int> n;
public:
	beta(T t, int i): q(t), n(i) {}
	template <typename U>
	U blab(U u, T t) { return (n.Value() + q.Value()) * u / t; }
	void Show() const { q.show(); n.show(); }
};