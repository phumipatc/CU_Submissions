#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
	//write your code here
	std::sort(data.begin(),data.end());
	auto it = data.begin();
	auto temp = *this;
	clear();
	for(int i=0;i<temp.size();i++){
		if(it != data.end() && (*it).first == i){
			push_back((*it).second);
			it++;
		}
		push_back(temp[i]);
	}
	if(it != data.end()){
		push_back((*it).second);
		it++;
	}
}

#endif
