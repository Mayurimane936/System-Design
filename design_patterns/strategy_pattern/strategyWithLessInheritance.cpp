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

//--concrete strategy for projection ---//
class Projectable{
    public:
    virtual void projection() = 0;
    virtual ~Projectable() {};
};

class CompanionRobot : public Projectable {
    public:
    void projection() {
        cout << "Projection of companion robot" << endl;
    }
};

class WarkRobot : public Projectable {
    public:
    void projection() {
        cout << "Projection of war robot" << endl;
    }
};


class Robot {
    private: 
    WalkRobot *walkStrategy;
    TalkRobot *talkStrategy;
    FlyRobot *flyStrategy;
    Projectable *projectionStrategy;

    public: 
    Robot (WalkRobot *w, TalkRobot *t, FlyRobot *f, Projectable *p) {
        this->walkStrategy = w;
        this->talkStrategy = t;
        this->flyStrategy = f;
        this->projectionStrategy = p;
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

    void projection() {
        projectionStrategy->projection();
    }
};

int main() {
    Robot *robot1 = new Robot(new WalkNormally(), new TalkNormally(), new NoFly(), new CompanionRobot());
    Robot *robot2 = new Robot(new NoWalk(), new NoTalk(), new FlyNormally(), new WarkRobot());

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