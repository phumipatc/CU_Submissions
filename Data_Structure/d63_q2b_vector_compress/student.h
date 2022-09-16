#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
	//write your code here
	T *res = new T[mSize]();
	for(int i=0;i<mSize;i++)
		res[i] = mData[i];
	
	delete [] mData;
	mData = res;
	mCap = mSize;
}

#endif
