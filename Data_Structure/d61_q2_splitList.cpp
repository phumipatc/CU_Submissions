void splitList(list<T>& list1, list<T>& list2) {
	// Add your code here
	int cut = (mSize+1)/2;
	iterator it = begin();
	for(int i=0;i<cut;i++,it++);
	node* now = it.ptr;
	list1.mHeader->prev->next = mHeader->next;
	mHeader->next->prev = list1.mHeader->prev;
	now->prev->next = list1.mHeader;
	list1.mHeader->prev = now->prev;
	list1.mSize+=cut;

	list2.mHeader->prev->next = now;
	now->prev = list2.mHeader->prev;
	list2.mHeader->prev = mHeader->prev;
	mHeader->prev->next = list2.mHeader;
	list2.mSize+=mSize-cut;

	mSize = 0;
	mHeader->next = mHeader->prev = mHeader;
}