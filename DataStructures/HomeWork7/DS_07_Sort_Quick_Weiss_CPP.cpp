/*
	Function£ºQuicksort
	Compiler£ºVisual C++ 6.0		Developer£ºJingxiang Zhang
	Date: November 17, 2015			Version: 2.0

	References£ºData Structures and Algorithm Analysis in C++ (3rd Ed & 4th Ed)
	Author: Mark Allen Weiss
	Pages: 74, 76, 81, 82, 88, 263, 285 (3rd Ed)
	Pages: 80, 82, 88, 89, 96, 293, 316 (4th Ed)
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//	Figure 3.7 - 3.8 vector class
//	PP81-82 (3rd Ed) or PP88-89 (4th Ed)

template <typename Object>
class Vector {
  private:
    struct Node {
        Object  ID;
        string  Data;
    }; // End of Figure 3.13 Nested Node class for List class

  public:
    explicit Vector(int InitSize = 0 )
        : theSize( InitSize ), theCapacity( InitSize + SPARE_CAPACITY ) {
        Nodes = new Node[ theCapacity ];
    }
    Vector( const Vector &rhs ) : Nodes( NULL ) {
        operator=( rhs );
    }
    ~Vector() {
        delete [] Nodes;
    }

    const Vector &operator= ( const Vector &rhs ) {
        if( this != &rhs ) {
            delete [] Nodes;
            theSize = rhs.size();
            theCapacity = rhs.theCapacity;

            Nodes = new Node[ capacity() ];
            for( int k = 0; k < size(); k++ )
                Nodes[ k ] = rhs.Nodes[ k ];
        }
        return *this;
    }

    void reserve( int newCapacity ) {
        if( newCapacity < theSize )
            return;

        Node *oldArray = Nodes;

        Nodes = new Node[ newCapacity ];
        for( int k = 0; k < theSize; k++ )
            Nodes[ k ] = oldArray[ k ];

        theCapacity = newCapacity;

        delete [] oldArray;
    } // End of Figure 3.14 Nested const_iterator class for List class

    Node &operator[]( int index ) {
        return Nodes[ index];
    }
    const Node &operator[]( int index ) const {
        return Nodes[ index];
    }

    bool empty( ) const {
        return size() == 0;
    }

    int size( ) const {
        return theSize;
    }

    int capacity() const {
        return theCapacity;
    }

    void push_back( Object &x, string &y ) {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        Nodes[ theSize ].ID = x;
        Nodes[ theSize ].Data = y;
        theSize++;
    }

    void pop_back( ) {
        theSize--;
    }

    const Node &back () const {
        return Nodes[ theSize - 1];
    }

    typedef Node *iterator;
    typedef const Node *const_iterator;

    iterator begin( ) {
        return &Nodes[ 0 ];
    }
    const_iterator begin() const {
        return &Nodes[ 0 ];
    }
    iterator end( ) {
        return &Nodes[ size() ];
    }
    const_iterator end( ) const {
        return &Nodes[ size() ];
    }

    enum { SPARE_CAPACITY = 16 };

  private:
    int theSize;
    int theCapacity;
    Node *Nodes;
}; // End of Figure 3.15 Nested iterator class for List class


// Fig 7.2 & 7.4 on P263 (3rd) or P293 (4th)
/**
 * Simple insertion sort.
 */
template <typename Comparable>
void insertionSort( Vector<Comparable> &a, int begin, int end ) {
	for (int p = 1; p< a.size(); ++p) {
		Comparable tmp = std::move(a[p]);
		int j;
		for (j = p; j > 0 && tmp < a[j - 1].ID; --j)
			a[j] = std::move(a[j-1]);
		a[j] = std::move(tmp);
	}
}

// Fig 7.14 on P285 (3rd) or P316 (4th)
/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quicksort( Vector<Comparable> &a ) {
    quicksort( a, 0, a.size( ) - 1 );
}

// Fig 7.14 on P285 (3rd) or P316 (4th)
/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable &median3( Vector<Comparable> &a, int left, int right ) {
    // Add codes here ...
    int center = (left + right) / 2;
    if (a[center].ID < a[left].ID)
    	std::swap(a[left], a[center]);
    if (a[right] < a[left])
    	std::swap(a[left], a[right]);
    if (a[right] < a[center])
    	std::swap(a[center], a[right]);
    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}

// Fig 7.16 on P286 (3rd) or Fig 7.19 on P322 (4th)
/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quicksort( Vector<Comparable> &a, int left, int right ) {
    // Add codes here ...
	if (left + 10 <= right) {
		const Comparable &pivot = median3(a, left, right);
		int i = left, j = right - 1;
		for (; ;) {
			while (a[++i] < pivot){}
			while (pivot < a[--j]){}
				if (i < j)
					std::swap(a[i], a[j]);
				else
					break;
		}
		std::swap(a[i], a[right - 1]);

		quicksort(a, left, i - 1);
		quicksort(a, i + 1, right);

	}
	else
		insertionSort(a, left, right);
}

/**
 * ########################  Main Entry  ########################
*/
int main() {
    int itemNumber = 10;
    int aa[] = { 8, 1, 4, 9, 0, 3, 5, 2, 7, 6 };
    string bb[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J" };

    Vector<int> v;

    for ( int i = 0; i < itemNumber; i++ )
        v.push_back( aa[i], bb[i] );

    cout << "The vector elements before sorting are: " << endl;
    for ( int i = 0; i != v.size(); i++ )	// P76 (3rd Ed) P82 (4th Ed)
        cout << v[i].ID << v[i].Data << " ";
    cout << endl;

    quicksort(v);

    cout << "The vector elements after sorting are: " << endl;
    for ( int i = 0; i != v.size(); i++ )	// P76 (3rd Ed) P82 (4th Ed)
        cout << v[i].ID << v[i].Data << " ";
    cout << endl;
    return 0;
}