#pragma once

#include "SelfOrderedListADT.h"
#include "llist.h"
template <typename E>
class Count :public SelfOrderedListADT<E> {
private:
	LList<E> llist;
	int compareNum;
public:
	Count() {
		
		compareNum = 0;
	}
	~Count() {
	}
	//Look for 'it'.  If found return true and execute the self-ordering
	//heuristic used for ordering the list: count, move-to-front, or transpose.
	//Increments the compare instance variable every time it compares 'it' to
	//other members of the list. Returns true if 'it' is found.
	bool find(const E& it) {
		bool isFound = false;
		int index = 0;
		llist.moveToStart();
		for (int i = 0; i < size(); i++)
		{
			compareNum++;
			if (llist.getValue() == it)
			{
				isFound = true;
				llist.incFrequency();
				index = i; 
				reorder();
				
				return true;
			}
			llist.next();
		}
		if (!isFound)
		{
			add(it);
		}
		
		return isFound;
	}

	//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is 
	//read without your re-order method being called (or the number of compares
	//being incremented.
	void add(const E& it) override {
		llist.append(it);
	}


	int getCompares() const override
	{
		return compareNum;
	}
	int size() const override
	{
		return llist.length();
	}
	
	//Print the list
	//In order print of the list.  printlist() prints the entire list
	//whereas printlist(n) prints n nodes.
	void printlist()
	{
		llist.moveToStart();
		for (int i = 0; i < size(); i++)
		{
			cout << llist.getValue() << "-" << llist.getFrequency() << " ";
			llist.next();
		}
	}

	void printlist(int n) {
		llist.moveToStart();
		for (int i = 0; i < n; i++)
		{
			cout << llist.getValue() << "-" << llist.getFrequency() << " ";
			llist.next();
		}
	};
	
	void reorder()
    {
		E tempVal = llist.getValue(); 
		int tempFrequency = llist.getFrequency(); 

		llist.prev();

		while (llist.getFrequency() < tempFrequency)
		{
			E tempVal2 = llist.getValue();
			int tempFrequency2 = llist.getFrequency();

			llist.setValue(tempVal);
			llist.setFrequency(tempFrequency);

			llist.next();

			llist.setValue(tempVal2);
			llist.setFrequency(tempFrequency2);

			llist.prev();

			tempVal = llist.getValue();
			tempFrequency = llist.getFrequency();

			llist.prev();

		}
    }

	void transposeOrdering(int index)
	{
		llist->moveToPos(index);
		if (llist->currPos() != 0)
		{
			if (llist->getFrequency() != 0) {

				E tempVal = llist->getValue();
				llist->remove();
				llist->prev();
				llist->insert(tempVal);
			}
		}
		
	}
	void MTFOrdering(int index)
	{
		llist->moveToPos(index);
		if (llist->currPos() != 0)
		{
			E tempVal = llist->getValue();
			llist->remove();
			llist->moveToStart();
			llist->insert(tempVal);

		}


	}
};