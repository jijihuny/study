#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


#define arr(X) X[0], X[1], X[2], X[3], X[4], X[5]

double get_distance(
    double r, double h,
    double d1, double A1,
    double d2, double A2
){
    double angle_cone = abs(A2-A1)>180.0?360.0 - abs(A2-A1):abs(A2-A1);
    double radian_cone = angle_cone / (180.0)  * M_PI;


    double length_bottom_arc = radian_cone * r;


    double radian_circular_sector = length_bottom_arc / (sqrt(r*r+h*h));

    double x1 = d1, y1 = 0.0;
    double x2 = d2 * cos(radian_circular_sector), y2 = d2 * sin(radian_circular_sector);


    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    double input[6];
    vector<double> answer;
    
    int cnt=0;
    while(cin>>input[(cnt)%6]){
        if((cnt++)%6==5) answer.push_back(get_distance(arr(input))); 
    }
    
    
    cout<<fixed;
    cout.precision(2);
    for(auto o : answer)cout<<o<<"\n";
}
