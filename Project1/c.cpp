#include<iostream>

//
////1�� ����
//namespace utils
//{
//	template<class T>
//	T min(const T& first, const T& second)
//	{
//		auto compA = first <=> second;
//		if (compA < 0) return first;
//		else if (compA > 0) return second;
//	}
//}
//
//int main()
//{
//	std::cout << utils::min(3, 4) << std::endl;
//	std::cout << utils::min(3.1, 2.3) << std::endl;
//}

////2�� ����
//class Point
//{
//public:
//	int x{ 0 }, y{0};
//
//	auto get_x() const
//	{
//		float temp = x / (float)2;
//		return temp;
//	}
//
//	Point operator+(const Point& p) const
//	{
//		Point pt{ p.x + x , p.y + y };
//		return pt;
//	}
//
//	friend std::ostream& operator<<(std::ostream& os, const Point& pt)
//	{
//		return os << pt.x << ", " << pt.y;
//	}
//};
//
//int main()
//{
//	Point p = {1,2};	//1. error ���;� ��
//
//	const Point p1{ 1,1 };
//	const Point p2{ 5,5 };
//
//	std::cout << p2.get_x() << std::endl; //2.5 ���;� ��
//
//	const Point p3 = p1 + p2;
//
//	std::cout << p3 << std::endl; // 6,6 ���� ��µǾ�� ��
//}

////3�� ����
//#include<vector>
//#include<algorithm>
//#include<functional>
//
//int main()
//{
//	std::vector<int> v;
//
//	//1. ������ 10�� ���ؼ� v�� ��������
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(rand() % 100);
//	}
//
//	int cmd = 0, cmd2 = 0, cmd3 = 0;
//
//	while (1)
//	{
//		std::cin >> cmd;
//
//		// 2. cmd�� 1�̸� v�� ��� ������ ȭ�鿡 ���
//		if (cmd == 1)
//		{
//			for_each(v.begin(), v.end(), [](const int& n) {std::cout << n << " "; });
//		}
//
//		// 3. cmd�� 2�̸� v�� ���� �������� ������ �� v�� ������ ȭ�� ���
//		//	�� ��å���� �Լ� ��ü�� ���
//		else if (cmd == 2)
//		{
//			sort(v.begin(), v.end());
//			for_each(v.begin(), v.end(), [](const int& n) {std::cout << n << " "; });
//		}
//
//		// 4. cmd�� 3�̸� v�� ���� �������� ������ �� v�� ������ ȭ�� ���
//		//	�� ��å���� ���� ǥ���� ���
//		else if (cmd == 3)
//		{
//			sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
//			for_each(v.begin(), v.end(), [](const int& n) {std::cout << n << " "; });
//		}
//
//		// 5. cmd�� 4�̸� �� �ٸ� ���ڸ� �ϳ� �Է� ��������
//		//	�ش� ���ڰ� vector�� ������ ������ �� vector�� �ٽ� ���
//		else if (cmd == 4)
//		{
//			std::cin >> cmd2;
//			auto ret = std::find(v.begin(), v.end(), cmd2);
//			if (ret != v.end())
//			{
//				v.erase(v.begin()+cmd2);
//			}
//			for_each(v.begin(), v.end(), [](const int& n) {std::cout << n << " "; });
//		}
//
//		// 6. cmd�� 5�̸� �� �ٸ� ���ڸ� �ϳ� �Է� ��������
//		//	�ش� ���ڸ� ã�Ƽ� 0���� ������ �� vector�� �ٽ� ���
//		else if (cmd == 5)
//		{
//			std::cin >> cmd3;
//			auto ret = std::find(v.begin(), v.end(), cmd3);
//			
//			if (ret != v.end())
//			{
//				*ret = 0;
//			}
//			for_each(v.begin(), v.end(), [](const int& n) {std::cout << n << " "; });
//		}
//
//		// 7. cmd�� 6�̸� size�� 20���� �ø� �� v�� ������ ���
//		else if (cmd == 6)
//		{
//			v.resize(20);
//			for_each(v.begin(), v.end(), [](const int& n){std::cout << n << " ";});
//		}
//	}
//}


//4�� ����
template<typename T>
class Buffer
{
	T* ptr;
	std::size_t size;
public:
	Buffer(std::size_t sz) : size(sz)
	{
		ptr = new T[sz];
	}
	~Buffer() { delete[] ptr; }

	Buffer(const Buffer& other)
		:size(other.size)
	{
		ptr = new T[size];
		memcpy(ptr, other.ptr, sizeof(int) * size);
	}
};

int main()
{
	Buffer<int> b1(1024);
	Buffer<int> b2 = b1;	//����� shallow copy �߻�
							// ������ ������ ���� �����ڸ� ����
							// deep copy�� ����
}