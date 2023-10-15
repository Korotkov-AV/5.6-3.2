// 5.6-3-2.cpp 

#include <iostream>

template <class T>
class vector {
private:
	T* arr;
	unsigned int using_index;
	unsigned int size;

public:
	vector() {
		arr = new T[3];
		using_index = 0;
		size = 3;
	}

	vector(int size1) {
		arr = new T[size1];
		using_index = 0;
		size = size1;
	}

	void push_back(T value) {
		if (size - 1 < using_index) {
			size += 3;

			T* copy_arr = new T[size];
			for (int i = 0; i < using_index; i++) {
				copy_arr[i] = arr[i];
			}

			std::swap(copy_arr, arr);

			delete[] copy_arr;
		}
		arr[using_index++] = value;
	}

	T at(int index) const {
		if (index >= using_index || index < 0) throw std::runtime_error("this index doesn't exist");

		return arr[index];
	}

	int sizee() const {
		return using_index;
	}

	int capacity() const {
		return size;
	}

	~vector() {
		delete[] arr;
	}

	void swap(vector<T>& other) noexcept {
		std::swap(arr, other.arr);
		std::swap(using_index, other.using_index);
		std::swap(size, other.size);
	}

	vector& operator=(const vector<T> V) {
		vector<int> copy(V.size);
		copy.using_index = V.using_index;

		for (int i = 0; i < V.using_index; i++) {
			copy.arr[i] = V.arr[i];
		}

		swap(copy);
		return *this;
	}

	vector(const vector<T>& V) {
		arr = new T[V.size];
		using_index = V.using_index;
		size = V.size;

		for (int i = 0; i < using_index; i++) {
			arr[i] = V.arr[i];
		}
	}
};

int main() {
	try {
		vector<int> Z;

		Z.push_back(2);
		Z.push_back(3);
		Z.push_back(2);
		Z.push_back(3);

		std::cout << Z.at(2) << " " << Z.capacity() << " " << Z.sizee();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}