#include <iostream>
#include "cstdlib"

using namespace std;

template<typename Object>
class Vector
{
public:
		Vector(int initSize=0)
			:theSize(initSize),theCapacity(initSize+SPARE_CAPACITY)
		{
			objects=new Object[theCapacity];
		}
		Vector(const Vector & rhs):objects(NULL)
		{
			operator=(rhs);
		}
		~Vector()
		{
			delete[] objects;
		}
		const Vector & operator=(const Vector & rhs)
		{
		  if(this!=&rhs)
		  {
		      delete[] objects;
			  
			  theSize=rhs.size();
			  
			  theCapacity=rhs.theCapacity;
			  
			  objects=new Object[capacity()];
			  
			  for(int k=0;k<size();k++)
				  objects[k]=rhs.objects[k];
		  }
		  return *this;
		}
		void resize(int newSize)
		{
		  	if(newSize>theCapacity)
			  reserve(newSize*2+1);
		  
		  	theSize=newSize;
		}
		void reserve(int newCapacity)
		{
			if(newCapacity<theSize)
			  return;
		    Object * oldArray=objects;

		    objects=new Object[newCapacity];
		    
		    for(int k=0;k<theSize;k++)
			    objects[k]=oldArray[k];
		    
		    theCapacity=newCapacity;

		  delete[] oldArray;
		}
		Object & operator[](int index)
		{
			return objects[index];
		}
		const Object & operator[](int index) const
		{
			return objects[index];
		}
		
		bool empty() const
		{
			return size() == 0;
		}
		
		int size() const
		{
			return theSize;
		}
		
		int capacity() const
		{
			return theCapacity;
		}
		void push_back(const Object & x)
		{
		  	if(theSize==theCapacity)
			  reserve(2*theCapacity+1);
		  	objects[theSize++]=x;
		}
		void pop_back()
		{
			theSize--;
		}
		const Object & back() const
		{
			return objects[theSize-1];
		}
		
		typedef Object * iterator;
		typedef const Object* const_iterator;
		
		iterator begin()
		{
			return &objects[0];
		}
		
		const_iterator begin()const
		{
			return &objects[0];
		}
		
		iterator end()
		{
			return &objects[size()];
		}
		
		const_iterator end() const
		{
			return &objects[size()];
		}

		enum{SPARE_CAPACITY=16};

private:
		int theSize;
		int theCapacity;
		Object * objects;

};
int main()
{
	int a[]={11,22,33,44};
	int itemNumber=4;
	
	Vector<int> v;
	for(int i=0;i<itemNumber;i++)
		v.push_back(a[i]);
	
	cout<<"The List elements are:"<<endl;
	
	for(int i=0;i!=v.size();++i)
		cout<<v[i]<<endl;
	
	cout<<"Print elements using iterator:"<<endl;
	
	Vector<int>::iterator itr=v.begin();
	
	while(itr!=v.end())
		cout<<*itr++<<endl;
	
	system("PAUSE");
}