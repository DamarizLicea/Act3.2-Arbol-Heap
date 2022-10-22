#include "hps.h"
using namespace std;

int main(){
    Priority_queue Q(11);
    Q.push(5);
    cout<< Q.top()<<endl;
    Q.push(12);
    Q.push(13);
    Q.push(11);
    
    
    cout<<Q.pop()<<endl;
    cout<<Q.top()<<endl;
    cout<<Q.tam()<<endl;





}