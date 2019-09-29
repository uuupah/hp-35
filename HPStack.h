#ifndef HPSTACK_H
#define HPSTACK_H

class HPStack
{
    public:
        HPStack();
        void push(double);
        double pop();
        double peek();
        //double get_mem();
        //void set_mem(double);
    private:
        double stack_[4];
        //double mem_;
};

#endif /*HPSTACK_H_*/