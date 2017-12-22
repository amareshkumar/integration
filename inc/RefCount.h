/*
 * RefCount.h
 *
 *  Created on: Dec 8, 2015
 *      Author: amakumar
 */

#ifndef REFCOUNT_H_
#define REFCOUNT_H_

#include "my_project_app.h"

class RefCount
{
private:
    int count; // Reference count

public:
    void AddRef(){
        // Increment the reference count if pointers to the same object increases
		count++;
    }

    int DecRef(){
        // Decrement the reference count and
        // return the reference count.
        return --count;
    }
	int ref_count() const { return count;  }
};

#endif /* REFCOUNT_H_ */
