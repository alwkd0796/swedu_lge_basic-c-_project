#include<iostream>

//
////1번 문제
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

////2번 문제
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
//	Point p = {1,2};	//1. error 나와야 함
//
//	const Point p1{ 1,1 };
//	const Point p2{ 5,5 };
//
//	std::cout << p2.get_x() << std::endl; //2.5 나와야 함
//
//	const Point p3 = p1 + p2;
//
//	std::cout << p3 << std::endl; // 6,6 으로 출력되어야 함
//}

////3번 문제
//#include<vector>
//#include<algorithm>
//#include<functional>
//
//int main()
//{
//	std::vector<int> v;
//
//	//1. 난수를 10개 구해서 v에 넣으세요
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
//		// 2. cmd가 1이면 v의 모든 내용을 화면에 출력
//		if (cmd == 1)
//		{
//			for_each(v.begin(), v.end(), [](const int& n) {std::cout << n << " "; });
//		}
//
//		// 3. cmd가 2이면 v를 오름 차순으로 정렬한 후 v의 내용을 화면 출력
//		//	비교 정책으로 함수 객체를 사용
//		else if (cmd == 2)
//		{
//			sort(v.begin(), v.end());
//			for_each(v.begin(), v.end(), [](const int& n) {std::cout << n << " "; });
//		}
//
//		// 4. cmd가 3이면 v를 내림 차순으로 정렬한 후 v의 내용을 화면 출력
//		//	비교 정책으로 람다 표현식 사용
//		else if (cmd == 3)
//		{
//			sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
//			for_each(v.begin(), v.end(), [](const int& n) {std::cout << n << " "; });
//		}
//
//		// 5. cmd가 4이면 또 다른 숫자를 하나 입력 받으세요
//		//	해당 숫자가 vector에 있으면 제거한 후 vector를 다시 출력
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
//		// 6. cmd가 5이면 또 다른 숫자를 하나 입력 받으세요
//		//	해당 숫자를 찾아서 0으로 변경한 후 vector를 다시 출력
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
//		// 7. cmd가 6이면 size를 20개로 늘린 후 v의 내용을 출력
//		else if (cmd == 6)
//		{
//			v.resize(20);
//			for_each(v.begin(), v.end(), [](const int& n){std::cout << n << " ";});
//		}
//	}
//}


//4번 문제
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
	Buffer<int> b2 = b1;	//현재는 shallow copy 발생
							// 문제가 없도록 복사 생성자를 만들어서
							// deep copy로 구현
}