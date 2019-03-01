#include "vector.h"
#include <stdlib.h>
#include <string.h>

void initVector(vector * v){
	v -> m_base = NULL;
	v -> m_len = 0;
	v -> m_capacity = 0;
}

void destroyVector(vector * v){
	if(v -> m_base != NULL){
		free(v -> m_base);
	}
}

ErrorType pushBackVector(vector * v , Type value){
	if(v -> m_len < v -> m_capacity){
		v -> m_base[v -> m_len] = value;
		v -> m_len++;
	}else{
		if(v -> m_base == NULL){
			v -> m_base = (Type*)malloc(sizeof(Type));
			if(v -> m_base == NULL){
				return MemoryLimit;
			}
			v -> m_capacity = 1;
		}else{
			Type * new_base = (Type*)malloc(sizeof(Type) * ((v -> m_capacity) * 2));
			if(new_base == NULL){
				return MemoryLimit;
			}
			memcpy(new_base , v -> m_base , sizeof(Type) * (v -> m_capacity));
			free(v -> m_base);
			v -> m_base = new_base;
			v -> m_capacity *= 2;
		}
		v -> m_base[v -> m_len] = value;
		v -> m_len++;
	}
	return Success;
}

ErrorType popBackVector(vector * v){
	if(v -> m_len == 0){
		return ArrayIsEmpty;
	}
	if(v -> m_len == 1){
		free(v -> m_base);
		v -> m_base = NULL;
		v -> m_len = 0;
		v -> m_capacity = 0;
	} else if (v -> m_len - 1 == v -> m_capacity / 2){
		Type * new_base = (Type*)malloc(sizeof(Type) * v -> m_len);
		memcpy(new_base , v -> m_base , v -> m_len - 1);
		free(v -> m_base);
		v -> m_base = new_base;
		v -> m_len--;
		v -> m_capacity = v -> m_len;
	} else{
		v -> m_len--;
	}
	
	return Success;
}

Type * getIndexVector(vector * v , size_type pos){
	if(pos >= v -> m_len){
		return NULL;
	}
	return v -> m_base + pos;
}

size_type sizeVector(vector * v){
	return v -> m_len;
}
size_type capacityVector(vector * v){
	return v -> m_capacity;
}
