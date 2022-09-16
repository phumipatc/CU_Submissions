#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
	//write your code here
	int oldSize = mSize;
	mSize = oldSize * 2;
	ensureCapacity(oldSize*2);
	for(int i=0;i<oldSize;i++)
		mData[mSize-i-1] = mData[i];
}

#endif
