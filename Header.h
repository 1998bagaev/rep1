template <class T = int>
__interface __declspec(dllexport) IQ
{
	void push(const T &val);
	void pop();
	T &top();
};
