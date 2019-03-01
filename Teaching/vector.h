#ifndef INCLUDED_VECTOR_H
#define INCLUDED_VECTOR_H
#include <stddef.h>

typedef int Type;
typedef size_t size_type;

enum ErrorType{
	Success,
	MemoryLimit,//内存不足
	ArrayIsEmpty //数组为空
};
struct T_Vector{
	Type * m_base; //数组元素的基址
	size_type m_len; //数组的长度
	size_type m_capacity; //数组实际能存储多大长度
};

typedef struct T_Vector vector;

void initVector(vector * v); //初始化数组
void destroyVector(vector * v); //销毁数组
ErrorType pushBackVector(vector * v , Type value); //放数组尾后添加元素
ErrorType popBackVector(vector * v); //从数组后面删除一个元素
Type * getIndexVector(vector * v , size_type pos);//返回数组第POS位置的元素的地址
size_type sizeVector(vector * v); //返回数组的长度
size_type capacityVector(vector * v); //返回数组可容纳的空间

#endif
