#pragma once
#include <iostream>

using namespace std;


template <class T>
class clsDynamicArray
{

protected:

	int _Size = 0;
	T* _TempArray;

public:

	T* OriginalArray;

	clsDynamicArray(int Size = 0) {

		if (Size < 0)
			Size = 0;

		_Size = Size;

		OriginalArray = new T[_Size];
	}

	~clsDynamicArray() {

		delete[] OriginalArray;
	}

	bool SetItem(int index, T value) {

		if (index >= _Size || _Size < 0) {

			return false;
		}

		OriginalArray[index] = value;

		return true;
	}

	bool IsEmpty() {

		return (_Size == 0 ? true : false);
	}

	int Size() {

		return _Size;
	}

	void Resize(int NewSize) {

		if (NewSize < 0) {

			NewSize = 0;

		}

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++) {

			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;

	}

	T GetItem(int Index) {

		return OriginalArray[Index];
	}

	void Reverse() {

		_TempArray = new T[_Size];

		int counter = 0;

		for (int i = _Size - 1; i >= 0; i--) {

			_TempArray[counter] = OriginalArray[i];
			counter++;
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear() {

		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int Item) {

		if (Item >= _Size || Item < 0) {

			return false;
		}

		_Size--;

		_TempArray = new T[_Size];

		for (int i = 0; i < Item; i++) {


			_TempArray[i] = OriginalArray[i];

		}

		for (int i = Item + 1; i < _Size + 1; i++) {

			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void Print() {

		for (int i = 0; i < _Size; i++) {

			cout << OriginalArray[i] << " ";
		}

		cout << "\n";
	}

	void DeleteFirstItem() {

		DeleteItemAt(0);

	}

	void DeleteLastItem() {

		DeleteItemAt(_Size - 1);
	}

	int Find(T value) {

		for (int i = 0; i < _Size; i++) {

			if (OriginalArray[i] == value)

				return i;

		}

		return -1;
	}

	bool DeleteItem(T value) {

		int Index = Find(value);

		if (Index == -1) {

			return false;
		}

		DeleteItemAt(Index);
		return true;
	}

	void InsertAt(int Index, T Val)
	{
		_Size++;
		for (int i = _Size - 1; i > Index; i--)
		{
			OriginalArray[i] = OriginalArray[i - 1];
		}
		OriginalArray[Index] = Val;
	}

	void InsertAtBeginning(T value) {

		InsertAt(0, value);
	}

	void InsertBefor(int Index, T Value) {

		if (Index < 1)
			InsertAt(0, Value);
		else
			InsertAt(Index - 1, Value);
	}

	void InsertAfter(int Index, T Value) {

		if (Index >= _Size)
			InsertAt(_Size, Value);

		else

			InsertAt(Index + 1, Value);
	}

	void InsertAtEnd(T value) {

		InsertAt(_Size, value);
	}
};

