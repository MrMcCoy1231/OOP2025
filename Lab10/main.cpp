#include <iostream>
#include <exception>

using namespace std;
class IndexOutOfBounds : public exception
{
    const char* what() const throw() override
    {
		return "Index out of bounds";
    }
};

class CapacityExceeded : public exception
{
	const char* what() const throw() override
	{
		return "Capacity exceeded";
	}
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    T** ptr; // pointer la elementul curent
public:
    ArrayIterator() : ptr(nullptr) {}
    ArrayIterator(T** p) : ptr(p) {}

    // operator prefix ++
    ArrayIterator& operator++() {
        ptr++;
        return *this;
    }

    // operator postfix ++
    ArrayIterator operator++(int) {
        ArrayIterator temp = *this;
        ++(*this);
        return temp;
    }

    // comparatori
    bool operator==(const ArrayIterator<T>& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const ArrayIterator<T>& other) const {
        return ptr != other.ptr;
    }

    // operator de dereferentiere
    T& operator*() const {
        return **ptr;
    }

    // pentru acces suplimentar
    T* GetElement() const {
        return *ptr;
    }
};


template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array()
    {
        List = nullptr;
        Capacity = 0;
        Size = 0;
    }// Lista nu e alocata, Capacity si Size = 0
    ~Array()
    {
		for (int i = 0;i < Size;i++)
			delete List[i];
        delete[] List;
    }// destructor
    Array(int capacity)
    {
        Capacity = capacity;
        List = new T * [Capacity];
        Size = 0;
    }// Lista e alocata cu 'capacity' elemente
    Array(const Array<T>& otherArray)
    {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0;i < Size;i++)
        {
            List[i] = new T(*otherArray.List[i]);
        }
    }// constructor de copiere

    T& operator[] (int index)
    {
        if (index >= 0 && index < Size)
            return *List[index];
        else
            throw IndexOutOfBounds();
    }// arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem)
    {
        if (Size >= Capacity)
            throw CapacityExceeded();
        else
        {
            List[Size++] = new T(newElem);
        }
        return *this;
    }// adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > Size || index >= Capacity)
            throw IndexOutOfBounds();

        for (int i = Size;i > index;i--)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (index<0 || index>Size || index + otherArray.Size >= Capacity)
            throw IndexOutOfBounds();

        for (int i = Size - 1;i >= index;i--)
            List[i + otherArray.Size] = List[i];
        for (int i = 0;i < otherArray.Size;i++)
            List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index)
    {
        if (index < 0 || index >= Size)
            throw IndexOutOfBounds();
        delete List[index];
        for (int i = index;i < Size - 1;i++)
            List[i] = List[i + 1];
        Size--;
        return *this;
    }// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray)
    {
        if (this == &otherArray)
            return true;
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = new T(*otherArray.List[i]);
        return true;
    }// operator de atribuire

    void Sort()
    {
        for (int i = 0; i < Size - 1;i++)
            for (int j = i + 1;j < Size;j++)
                if (*List[i] > *List[j])
                    swap(*List[i], *List[j]);
    }// sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size - 1;i++)
            for (int j = i + 1;j < Size;j++)
                if (compare(*List[i], *List[j]) > 0)
                    swap(*List[i], *List[j]);
    }// sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator)
    {
        for (int i = 0; i < Size - 1;i++)
            for (int j = i + 1;j < Size;j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    swap(*List[i], *List[j]);
    }// sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem)
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int mid = (st + dr) / 2;
            if (*List[mid] == elem)
                return mid;
            else
                if (*List[mid] < elem)
                    st = mid + 1;
                else
                    dr = mid - 1;
        }

        return -1;
    }// cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int mid = (st + dr) / 2;
			int c = compare(*List[mid], elem);
			if (c == 0)
				return mid;
			else
				if (c < 0)
					st = mid + 1;
				else
					dr = mid - 1;
        }

        return -1;
    }
    //  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare* comparator)
    {
		int st = 0, dr = Size - 1;
		while (st <= dr)
		{
			int mid = (st + dr) / 2;
			int c = comparator->CompareElements(List[mid],(void*) & elem);
			if (c == 0)
				return mid;
			else
				if (c < 0)
					st = mid + 1;
				else
					dr = mid - 1;
		}
		return -1;
    }//  cauta un element folosind binary search si un comparator

    int Find(const T& elem)
    {
        for (int i = 0;i < Size;i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }// cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
		for (int i = 0;i < Size;i++)
			if (compare(*List[i], (void*) &elem) == 0)
				return i;
		return -1;
    }//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator)
    {
		for (int i = 0;i < Size;i++)
			if (comparator->CompareElements(List[i],(void*) & elem) == 0)
				return i;
		return -1;
    }//  cauta un element folosind un comparator

    int GetSize() {
        return Size;
    }
    int GetCapacity() {
        return Capacity;
    }

    ArrayIterator<T> begin() {
        return ArrayIterator<T>(List);
    }
    ArrayIterator<T> end() {
        return ArrayIterator<T>(List + Size);
    }

};

template<class T>
class CompareT : public Compare
{
public:
    int CompareElements(void* e1, void* e2) override
	{
		T* t1 = (T*)e1;
		T* t2 = (T*)e2;
		if (*t1 == *t2)
			return 0;
		else
			if (*t1 < *t2)
				return -1;
			else
				return 1;
	}
};

int main()
{
    try {
        // 1. Cream un Array<int> cu capacitate 10
        Array<int> a(10);

        // 2. Adaugam elemente
        a += 5;
        a += 2;
        a += 8;
        a += 1;
        a += 3;

        // 3. Afisam elementele
        cout << "Elemente initiale: ";
        for (int i = 0; i < a.GetSize(); ++i)
            cout << a[i] << ' ';
        cout << endl;

        // 4. Sortare cu comparator
        CompareT<int> cmp;
        a.Sort(&cmp);

        cout << "Dupa sortare: ";
        for (int i = 0; i < a.GetSize(); ++i)
            cout << a[i] << ' ';
        cout << endl;

        // 5. Cautare: BinarySearch
        int poz = a.BinarySearch(3, &cmp);
        cout << "BinarySearch(3) -> pozitia: " << poz << endl;

        // 6. Find
        int poz2 = a.Find(8, &cmp);
        cout << "Find(8) -> pozitia: " << poz2 << endl;

        // 7. Inseram pe pozitia 2 valoarea 10
        a.Insert(2, 10);
        cout << "Dupa Insert(2, 10): ";
        for (int i = 0; i < a.GetSize(); ++i)
            cout << a[i] << ' ';
        cout << endl;

        // 8. Stergem pozitia 3
        a.Delete(3);
        cout << "Dupa Delete(3): ";
        for (int i = 0; i < a.GetSize(); ++i)
            cout << a[i] << ' ';
        cout << endl;

        // 9. Parcurgere cu iterator
        cout << "Parcurgere cu iterator: ";
        for (auto it = a.begin(); it != a.end(); ++it)
            cout << *it << ' ';

        cout << endl;
    }
    catch (exception& e) {
        cout << "Exceptie: " << e.what() << endl;
    }

	return 0;
}