#include<stdio.h>
#include<iostream>

using namespace std;

//---strategy interface for walk ---//
class WalkRobot {
    public:
    virtual void walk() = 0;
    virtual ~WalkRobot() {};
};

//--concrete strategy for walk ---//
class WalkNormally : public WalkRobot {
    public:
    void walk() {
        cout << "Walk normally" << endl;
    }
};

class NoWalk : public WalkRobot {
    public:
    void walk() {
        cout << "No walk" << endl;
    }
};

//strategy interface for talk ---//
class TalkRobot {
    public:
    virtual void talk() = 0;
    virtual ~TalkRobot() {};
};

//--concrete strategy for talk ---//
class TalkNormally : public TalkRobot {
    public:
    void talk() {
        cout << "Talk normally" << endl;
    }
};

class NoTalk: public TalkRobot{
    public:
    void talk() {
        cout << "No talk" << endl;
    }
};

//strategy interface for fly ---//
class FlyRobot {
    public:
    virtual void fly() = 0;
    virtual ~FlyRobot() {};
};

//--concrete strategy for fly ---//
class FlyNormally : public FlyRobot {
    public:
    void fly() {
        cout << "Fly normally" << endl;
    }
};

class NoFly: public FlyRobot {
    public:
    void fly() {
        cout << "No fly" << endl;
    }
};

class Robot {
    private: 
    WalkRobot *walkStrategy;
    TalkRobot *talkStrategy;
    FlyRobot *flyStrategy;

    public: 
    Robot (WalkRobot *w, TalkRobot *t, FlyRobot *f) {
        this->walkStrategy = w;
        this->talkStrategy = t;
        this->flyStrategy = f;
    }

    void walk() {
        walkStrategy->walk();
    }

    void talk() {
        talkStrategy->talk();
    }

    void fly() {
        flyStrategy->fly();
    }

    virtual void projection() = 0;
};

class CompanionRobot : public Robot {
    public:
    CompanionRobot (WalkRobot *w, TalkRobot *t, FlyRobot *f) : Robot(w,t,f) {}
    // CompanionRobot (WalkRobot *w, TalkRobot *t, FlyRobot *f) {
    //     Robot(w,t,f) 
    // }

    void projection() {
        cout << "Projection of companion robot" << endl;
    }
};

class WarkRobot : public Robot {
    public:
    WarkRobot (WalkRobot *w, TalkRobot *t, FlyRobot *f) : Robot(w,t,f) {}

    void projection() {
        cout << "Projection of war robot" << endl;
    }
};

int main() {
    Robot *robot1 = new CompanionRobot(new WalkNormally(), new TalkNormally(), new NoFly());
    Robot *robot2 = new WarkRobot(new NoWalk(), new NoTalk(), new FlyNormally());

    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout<<"------------------"<<endl;

    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;


}