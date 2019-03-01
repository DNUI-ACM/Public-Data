#ifndef INCLUDED_VECTOR_H
#define INCLUDED_VECTOR_H
#include <stddef.h>

#include <new>

class Exception{
	const char * msg = "123";
public:
	Exception() = default;
	const char * getMessage()const{
		return msg;
	}
};

namespace mystl{
		
	template<typename T>
	class Vector{
	public:
		Vector() = default;
		explicit Vector(size_t size);
		explicit Vector(size_t size,const T & value);
		Vector(const Vector & v);
		~Vector() = default;
		void push_back(const T & value);
0		void pop();
		T & operator[](int pos);
		const T & operator[](int pos)const;
		size_t size() const ;
		size_t capacity() const ;
		Vector & operator = (const Vector & v);
	private:
		void increase_memory();
		void decrease_memory();
	private:
		shared_ptr<T> _base = nullptr;
		size_t _len = 0;
		size_t _capacity = 0;
	};
	
	
	template<typename T>
	Vector<T> & Vector<T>::operator = (const Vector<T> & v) {
		Vector<T> tmp(v);
		this->swap(tmp);
		return *this;
	}
	
	template<typename T>
	Vector<T>::~Vector(){
		if(_base){
			delete _base;
		}
	}
	
	template<typename T>
	void Vector<T>::push_back(const T & value){
		if(_len == _capacity){
			try{
				increase_memory();
			}catch(const char * msg){
				throw;
			}
		}
		_base[_len++] = value;
	}
	
	template<typename T>
	void Vector<T>::increase_memory(){
		if(_capacity == 0){
			_base = new T[1];
			if(_base == nullptr){
				throw "invite memory fail";
			}
			_capacity = 1;
		}else{
			T * new_base = new(std::nothrow) T[_capacity * 2];
			if(_base == nullptr){
				throw "invite memory fail";
			}
			delete[] base;
			memcpy(new_base , _base , _capacity * sizeof(T));
			base = new_base;
			_capacity *= 2;
		}
	}
}
#endif
template<typename T>
void f(Vector<T> const & v) {
	
}

int main(){
	Vector<int> v;
	v.~Vector();
	new (&v) Vector<int>;
	
	
	Vector<int> v2 = v;
	Vector<int> v2(v);
	f({10,5});
	
	vector<int> v3 = vector<int>(5);
	
}
