/*
 * SmtPtr.h
 *
 *  Created on: Dec 8, 2015
 *      Author: amakumar
 */

#ifndef SMTPTR_H_
#define SMTPTR_H_

#include "RefCount.h"
#include "my_project_app.h"

using namespace std;

//Implementation of smart pointers
template <class T> class SmartPtr {
	T* pData;
	RefCount* reference;
public:
	T& operator * (){
		return *pData;
	}
	T* operator -> (){
		return pData;
	}
	SmartPtr (): pData(nullptr), reference (0){
		reference = new RefCount();
		reference->AddRef();

		cout << "SmartPtr C-tor\n";
	}
	SmartPtr(T* data): pData(data), reference(0){
		reference= new RefCount();

		reference->AddRef();
		cout << "SmartPtr C-tor\n";
	}
	SmartPtr (const SmartPtr<T>& sp ): pData(sp.pData), reference(sp.reference){
		cout << "SmartPtr copy c-tor\n";
	}
	SmartPtr<T>& operator= (const SmartPtr<T>& rhs) {
		if (this != &rhs) {
			if (reference->DecRef() == 0) {
				delete pData;
				delete reference;
			}
				pData = rhs.pData;
				reference = rhs.reference;
				reference->AddRef();
		}
		cout << "SmartPtr assign-op\n";
		return *this;
	}
	~SmartPtr(){
		// Destructor
		// Decrement the reference count
		// if reference become zero delete the data
		if(reference->DecRef() == 0)
		{
			delete pData;
			delete reference;
		}
		cout << "SmartPtr D-tor\n";
	}
};

#endif /* SMTPTR_H_ */
