#include "./Include/Word.hpp"

#include<iostream>
using namespace std;

class A{
public:
    int a;
    // void max(){
        // printf("max\n");
    // }
//
    // virtual void mix(){
        // printf("mix\n");
    // }
    virtual void print(){
        printf("A\n");
    }
};

class B : public A{
public:
    int a;
    int b;
    void printB(){
        printf("xxxxxxxxx\n");
    }


    virtual void printa(){
        printf("xxxxxxxx\n");
    }

    void print(){
        printf("B\n");
    }

    void printb(){
        printf("xxxxxxxxxxxxxxx\n");
    }

};

void funcB(B * b){
    b->print();

}

void funcA(A * b){
    b->print();
    cout << (typeid(b) == typeid(B *)) << endl;
    printf("%d\n", typeid(b) == typeid(A *) );

    B * x = dynamic_cast<B *>(b);
    if(x == nullptr){
        printf("%s\n", "is A");
    }else{
        printf("%s\n", "is B");
    }
}

int main(int argc, const char *argv[]){
    // A * pa = new A();
    // B * pb = new B();
    // pa->a = 111111;
    // pb->a = 222222;
    
    // A ppa;
    // B ppb = *( (B*)(&ppa) );
    // ppa.print();
    // ppb.print();

    // pa->print();
    // pb->print();


    // A * pp = pb;
    // pp->print();



    // B * pp3 = dynamic_cast<B *>(pa);
    // if(pp3 == nullptr){
        // printf("%s\n", "shit");
    // }else{
        // pp3->print();
    // }



    // B * pp2 = (B *)(pa);
    // pp2->printa();

    // funcB(pa);
    // funcA(pb);
    // funcA(pa);
    
    int i = 8;
    printf("%d %d %d\n", i = i + 1000, i = i + 100, i = i + 10);

    return 0;
}
