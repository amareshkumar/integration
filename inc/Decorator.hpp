#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include "my_project_app.h"

//Abstract Girl
class IGirl {
public:
	virtual void girl_type() = 0;
	virtual ~IGirl() {}
};

//Normal girl
class Girl : public IGirl {
public:
	virtual void girl_type() {
		cout << "A Simple Brunette with good smile ";
	}
};

//Abstract Decorator for Girl: make the Girl sophisticated
class GirlMakeUp : public IGirl {
public:
	GirlMakeUp(IGirl* igirl) : m_igirl(igirl) {}

	virtual void girl_type() {
		m_igirl->girl_type();
	}

private:
	IGirl* m_igirl;
};


//concrete decorator1 for Girl with...HighHills
class GirlWithHighHills : public GirlMakeUp {
public:
	//call base class c-tor 
	GirlWithHighHills(IGirl* igirl) : GirlMakeUp(igirl) {}

	virtual void girl_type() {
		GirlMakeUp::girl_type();
		cout << " + High Hills ";
	}
};


//concrete decorator2 for Girl with...
class GirlWithNecklace : public GirlMakeUp {
public:
	GirlWithNecklace(IGirl* igirl) : GirlMakeUp(igirl) {}

	virtual void girl_type() {
		GirlMakeUp::girl_type();
		cout << " + wearing Necklace ";
	}
};


//concrete decorator3 for Girl with...
class GirlWithExpensiveDress : public GirlMakeUp {
public:
	GirlWithExpensiveDress(IGirl* igirl) : GirlMakeUp(igirl) {}

	virtual void girl_type() {
		GirlMakeUp::girl_type();
		cout << " + in a attractive red dress ";
	}
};

class GirlDrivingHarleyBike : public GirlMakeUp {
public:
	GirlDrivingHarleyBike(IGirl* igirl) : GirlMakeUp(igirl) {}

	virtual void girl_type() {
		GirlMakeUp::girl_type();
		cout << " And she drives a Harley Davidson. ";
	}
};

#endif //DECORATOR_HPP