#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "my_project_app.h"

//reference https://medium.com/datadriveninvestor/design-patterns-a-quick-guide-to-observer-pattern-d0622145d6c2

//main subject which acts like publisher
//model: Football game

class Subject {
private:
	vector <class Observer*> observers;
	bool scored; //event: team scored a goal
public:
	void notify();

	//registers observers
	void attach(Observer *obs) {
		observers.push_back(obs);
	}

	//this is the event. if it changes, observers changes their states by notify()
	void setScored(bool score) {
		scored = score;
		notify();
	}

	bool getScored() {
		return scored;
	}
};


class Observer {
	//list of subjects, pointers of Subject class
private:
	Subject *subj;
	//state
	int excitmentLevel;
public:
	Observer(Subject *sub, int excLevel) :subj(sub), excitmentLevel(excLevel) {
		//observers registers themselves to the subject
		subj->attach(this); //understand it better
	}

	virtual void update() = 0; //have to be implemented by concrete classes
protected:
	Subject* getSubject() {
		return subj;
	}

	void setExcitmentLevel(int level) {
		excitmentLevel = level;
	}

	int getExcitmentLevel() {
		return excitmentLevel;
	}
};

//why the places of this definition matters so much. 
void Subject::notify() {
	for (int i = 0; i < observers.size(); i++)
		observers[i]->update();
}

//class dor Concrete observers
class OldConcreteObserver : public Observer {
public:
	//call parents c-tor to register with subject
	OldConcreteObserver(Subject *sub, int level) : Observer(sub, level) {}

	//if level > 150, danger for older people
	void update() {
		//is scored
		bool scored = getSubject()->getScored();
		setExcitmentLevel(getExcitmentLevel() + 1);

		if (scored && getExcitmentLevel() > 150) {
			cout << "Relax. it's just a goal" << endl;
		}
		else {
			cout << "Its a Goal!" << endl;
		}
	}
};

class YoungConcreteObserver : public Observer {

public:
	//register for subject calling its parent c-tor
	YoungConcreteObserver(Subject *sub, int level) :Observer(sub, level) {}

	//update its state on event's trigger
	void update() {
		bool scored = getSubject()->getScored();
		setExcitmentLevel(getExcitmentLevel() + 1);

		if (scored && getExcitmentLevel() > 100) {
			cout << "Dont drink and drive " << endl;
		}
		else {
			cout << "Cheers, It's Goal" << endl;
		}
	}
};

#endif //OBSERVER_HPP