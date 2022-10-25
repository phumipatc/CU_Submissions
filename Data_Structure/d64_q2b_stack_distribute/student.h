#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
	//write your code here
	std::vector<std::vector<T > > res(k);
	int num = size()/k;
	int remaining = size() - (num*k);
	int idx = size()-1;
	for(auto &x:res){
		for(int i=1;i<=num+(remaining > 0);i++)
			x.push_back(mData[idx--]);
		remaining--;
	}
	return res;
}
#endif
