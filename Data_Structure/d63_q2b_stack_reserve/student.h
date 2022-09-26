#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
	int remaining = mCap - mSize;
	int otherRemaining = other.mCap - other.mSize;
	int dif = remaining - otherRemaining;
	return ((dif > 0)?1:((dif < 0)?-1:0));
}

#endif
