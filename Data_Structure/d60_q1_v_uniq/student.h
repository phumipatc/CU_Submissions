#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include<unordered_map>

template <typename T>
void CP::vector<T>::uniq() {
	//do someting here
	std::unordered_map<T ,bool > mp;
	auto temp = *this;
	clear();
	for(auto x:temp){
		if(mp[x])	continue;
		mp[x] = true;
		push_back(x);
	}
}

#endif
