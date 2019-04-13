#ifndef ABSTRACTFACTORY_HPP
#define ABSTRACTFACTORY_HPP
 
#include "my_project_app.h"

//abstract product : smartphones
class Smartphone {
public:
	virtual void which_smart_phone() = 0;
};

//concrete product 1: Blackberry
class Blackberry : public Smartphone {
public:
	virtual void which_smart_phone() {
		cout << "This is Blackberry phone" << endl;
	}
};

//concrete product 2: Iphone
class Iphone : public Smartphone {
public:
	virtual void which_smart_phone() {
		cout << "This is an Iphone" << endl;
	}
};

//concrete product 2: Android
class Android :public Smartphone {
public:
	virtual void which_smart_phone() {
		cout << "This is an Android phone" << endl;
	}
};

//abstract Mobile factory
class Abs_MobileFactory {
public:
	virtual Smartphone* createSmartphone() = 0;
};

//Blackberry concrete factory: hidden from user
class BlackBerryFactory : public Abs_MobileFactory {
public:
	virtual Smartphone* createSmartphone() {
		return new Blackberry;
	}
};

//concrete factory for Iphone
class IphoneFactory : public Abs_MobileFactory{
public:
	virtual Smartphone* createSmartphone() {
		return new Iphone;
	}
};

//concrete factory for product: Android

class AndroidFactory :public Abs_MobileFactory{
public:
	virtual Smartphone* createSmartphone() {
		return new Android;
	}
};

#endif // !ABSTRACTFACTORY_HPP
