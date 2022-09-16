#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
	//write your code here
	auto temp = *this;
	temp.clear();
	for(auto it = begin();it != end(); it++){
		if(it == position)
			for(auto it2 = first;it2 != last;it2++)
				temp.push_back(*it2);
		temp.push_back(*it);
	}
	if(position == end()){
		for(auto it2 = first;it2 != last;it2++)
			temp.push_back(*it2);
	}
	operator=(temp);
}

#endif
