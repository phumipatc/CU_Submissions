#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
	//write your code here
	vector<bool > mark(mSize);
	for(auto x:pos)
		mark[x] = true;
	vector<T> res;
	for(int i=0;i<mSize;i++){
		if(mark[i])	continue;
		res.push_back(mData[i]);
	}
	this->operator=(res);
}

#endif
