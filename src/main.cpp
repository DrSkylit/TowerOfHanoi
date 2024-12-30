#include <cstdio>
#include<TowerOfHanoi.h>
int main(){
    TowerOfHanoi towerOfHanoi(5);
    towerOfHanoi.draw();
   while(towerOfHanoi.next() != "completed"){
        towerOfHanoi.draw();
   }
}
