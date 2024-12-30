#include "TowerOfHanoi.h"
#include <cstdio>

TowerOfHanoi::TowerOfHanoi(int size){
    this->step = 0;
    this->size = size;
    this->isEven = ((size % 2) == 0);
    this->initializeRod(size,this->rod1);
}

std::string TowerOfHanoi::next(){
    this->step++;
    if(this->rod2.size() == this->size || this->rod3.size() == this->size){
        return "completed";
    }
    if(isEven == 1){
        if((1 % this->step) == 0){
            if(this->rod1.size() > 0 && (this->rod2.size() == 0 || this->rod1.back().size < this->rod2.back().size)){
                this->addToRod(this->rod2,this->rod1);
            }else if(this->rod1.size() == 0 || this->rod2.back().size < this->rod1.back().size){
                this->addToRod(this->rod1,this->rod2);
            }       
        }else if((2 % this->step) == 0){
            if(this->rod1.size() > 0 && (this->rod3.size() == 0 || this->rod1.back().size < this->rod3.back().size)){
                this->addToRod(this->rod3,this->rod1);
            }else if(this->rod1.size() == 0 || this->rod3.back().size < this->rod1.back().size){
                this->addToRod(this->rod1,this->rod3);
            }

        }else if((3 % this->step) ==0){
            if(this->rod2.size() > 0 && (this->rod3.size() == 0 || this->rod2.back().size < this->rod3.back().size)){
                this->addToRod(this->rod3,this->rod2);
            }else if(this->rod2.size() == 0 || this->rod3.back().size < this->rod2.back().size){
                this->addToRod(this->rod2,this->rod3);
            }
        }
    }else{
        if((1 % this->step) == 0){
            if(this->rod1.size() > 0 && (this->rod3.size() == 0 || this->rod1.back().size < this->rod3.back().size)){
                this->addToRod(this->rod3,this->rod1);
            }else if(this->rod1.size() == 0 || this->rod3.back().size < this->rod1.back().size){
                this->addToRod(this->rod1,this->rod3);
            }   
        }else if((2 % this->step) == 0){
            if(this->rod1.size() > 0 && (this->rod2.size() == 0 || this->rod1.back().size < this->rod2.back().size)){
                this->addToRod(this->rod2,this->rod1);
            }else if(this->rod1.size() == 0 || this->rod2.back().size < this->rod1.back().size){
                this->addToRod(this->rod1,this->rod2);
            }
    
        }else if((3 % this->step) ==0){
            if(this->rod3.size() > 0 && (this->rod2.size() == 0 || this->rod3.back().size < this->rod2.back().size)){
                this->addToRod(this->rod2,this->rod3);
            }else if(this->rod3.size() == 0 || this->rod2.back().size < this->rod3.back().size){
                this->addToRod(this->rod3,this->rod2);
            }
        }
    }

    if(this->step == 3){
        this->step = 0;
    }
    return "";
}

void TowerOfHanoi::draw(){
     printf("Rod 1\n");
    for(int i =0; i < this->rod1.size();i++){
        printf("%i\n",this->rod1[i].size);
    }
    printf("Rod 2\n");
    for(int i =0; i < this->rod2.size();i++){
        printf("%i\n",this->rod2[i].size);
    }
    printf("Rod 3\n");
    for(int i =0; i < this->rod3.size();i++){
        printf("%i\n",this->rod3[i].size);
    }
    printf("\n\n");
}

void TowerOfHanoi::initializeRod(int size,std::vector<Disk>& rod){
    for(int i = size-1; i >= 0; i--){
        TowerOfHanoi::Disk disk;
        disk.size=i;
        rod.push_back(disk);
    }
}

void TowerOfHanoi::addToRod(std::vector<Disk>& recivingRod,std::vector<Disk>& givingRod){
    Disk disk = givingRod.back();
    givingRod.pop_back();
    recivingRod.push_back(disk);
}
