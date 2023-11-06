#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
	// Your code here
	if(index == mSize) {
		mData.push_back(value);
		aux.push_back(aux[aux.size()-1] + value.size());
		mSize = mCap = aux[aux.size()-1];
		return ;
	}

	int i = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
    if (i > 0)
    	index -= aux[i - 1];
	//return mData[i][index]

	// move mData[i] to mData[i+1], mData[i+2], ..., mData[n] to mData[n+1]
	mData.push_back(std::vector<T>());
	for (int j = mData.size()-2; j >= i; j--) {
		mData[j+1] = std::move(mData[j]);
	}
	
	// move some elements in mData[i+1] back to mData[i]
	mData[i] = std::move(std::vector<T>(mData[i+1].begin(), mData[i+1].begin() + index));
	mData[i+1].erase(mData[i+1].begin(), mData[i+1].begin() + index);

	// insert value to mData[i]
	for(int j = 0; j < value.size(); j++) {
		mData[i].push_back(value[j]);
	}

	// update aux
	aux.push_back(0);
	for(int j = i; j < mData.size(); j++) {
		if(j == 0)
			aux[j] = mData[j].size();
		else
			aux[j] = aux[j-1] + mData[j].size();
	}

	// update mSize, mCap
	mCap = mSize = aux[aux.size()-1];
	// debug();
}

#endif