#ifndef GC_HPP
#define GC_HPP
#include "my_project_app.h"

//class  gc :public Utilities //Utilities sections are removed
class gc {
public:
	gc();
	~gc();
	void* operator new (size_t size);
	void operator delete(void*);
};

#endif // !GC_HPP