#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
	//write your code here
	while(!empty() && K--)
		pop();
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
	//write your code here
	//
	//don't forget to return an std::stack
	std::vector<T > temp;
	while(!empty() && K--)
		temp.push_back(top()),pop();
	std::stack<T > res;
	while(!temp.empty())
		res.push(temp.back()),temp.pop_back();
	return res;
}

#endif
