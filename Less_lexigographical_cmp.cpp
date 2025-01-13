// Öyle bir Less fonksiyonu ki iki tane dizi alır ve bu dizileri lexicographical compare eder. 
// Dizilerin türleri aynı fakat boyutları farklı olabilir.


	template <typename T, int N, int M>
	constexpr bool Less(const T(&x)[N], const T(&x)[M])
	{
		for(int i = 0; i < N && i < M; ++i) { // taşmaması iiçin
			if(x[i] < y[i])
				return true;

			if(y[i] < x[i])
				return false;
		}

		return N < M;
	}

	int main()
	{
		int a[] = { 1, 5, 8 };
		int b[] = { 1, 5, 8, 6 };

		Less(a, b);	// template argument deduction ile explicit template argümanı kullanmasak da fonksiyonu bu şekilde çağırmış olacağız: Less<int, 3, 5>(a, b);

	}
