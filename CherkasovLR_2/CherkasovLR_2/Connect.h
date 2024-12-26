#pragma once
#include <vector>
#include <cmath>

using namespace std;

class Conn
{
public:
    int diametr;
    int connin;
    int connout;
    int length;
    int repair;
    int profit;

    void updateProfit() {
        profit = calculateProfit();
    }


private:
    int calculateProfit() {
        if (length > 0) { 
            if (repair == 0){
                return static_cast<int>(sqrt(5000 * diametr / length));
            }
            else {
                return 0;
            }
        }
        return 0; 
    }
};