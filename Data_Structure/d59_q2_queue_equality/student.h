#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
	//write your code here
	//
	// YOU CANNOT CALL push or pop
	if(mSize != other.mSize)	return false;
	for(int i=0,idx1 = mFront,idx2 = other.mFront;i<mSize;i++,idx1++,idx2++,idx1%=mCap,idx2%=other.mCap){
		if(mData[idx1] != other.mData[idx2])
			return false;
	}
	return true;
}

#endif
