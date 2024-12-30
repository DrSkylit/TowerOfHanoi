#pragma once

#include<vector>
#include<string>
//struct Disk{
//    int size;
//};

class TowerOfHanoi{
    public:
        TowerOfHanoi(int size);
        std::string next();
        void draw();
    private:
        struct Disk{
            int size;
        };
        int step;
        int size;
        bool isEven;
        std::vector<Disk> rod1;
        std::vector<Disk> rod2;
        std::vector<Disk> rod3;
        
        void initializeRod(int size,std::vector<Disk>& rod);
        void addToRod(std::vector<Disk>& recivingRod,std::vector<Disk>& givingRod);
};
