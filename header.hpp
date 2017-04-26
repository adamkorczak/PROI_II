#ifndef header_hpp
#define header_hpp


class intSet
{
	struct node
	{
		int a;
		struct node *nextPointer;
	};
	int size;

public:
	
	node *lastPointer;

	intSet() { lastPointer = NULL; size = 0; }
	intSet(const intSet &t);

	void addNodeAtTheEnd(int aInput);
	void addNodeAtTheBegining(int aInput);
	void addNodeAfterValue(int aInput, int valueInput);
	void addNodeAfterIndex(int aInput, int index);
	void deleteNodeAtTheIndex(int index);
	void deleteNodeWithValue(int value);
	void deleteNodeWithValueInRange(int low, int high);
	void clear();
	void display();
	int checkSize();
	void deleteTheSameValue();
	int getValue(int index);
	void setValueInElement(int aInput, int index);

	bool operator==(const intSet &t);
	bool operator!=(const intSet &t);

	intSet operator+(const intSet &t) const;
	intSet operator-(const intSet &t) const;
	intSet &operator=(const intSet &t);


	friend bool operator>(const intSet &t1, const intSet &t2);
	friend bool operator<(const intSet &t1, const intSet &t2);
	friend bool operator>=(const intSet &t1, const intSet &t2);
	friend bool operator<=(const intSet &t1, const intSet &t2);
	friend std::ostream& operator<<(std::ostream &out, const intSet &t);
	friend std::istream& operator>>(std::istream &in, intSet &t);
		
};

#endif
