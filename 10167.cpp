#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;





// long long sum_if(auto first, auto last){
//     long long total=0;
//     for(auto i=first; i!=last+1; i++){
//         if(max((*first).at(1), (*last).at(1))>=(*i).at(1) &&
//             min((*first).at(1), (*last).at(1))<=(*i).at(1))
//             total+=(*i).at(2);
//     }
//     return total;
// }

// int main(){
//     cin.tie(NULL)->sync_with_stdio(false);

//     int N;
//     cin>>N;
//     vector<vector<int>> x_sorted;

//     int x_temp, y_temp, gain_temp;
//     for(int i=0; i<N; i++){
//         cin>>x_temp>>y_temp>>gain_temp;
//         x_sorted.push_back(vector<int> {x_temp, y_temp, gain_temp});
    
//     }
    
    

//     auto x_cmp = [](auto &a, auto &b){
//         return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
//     };

//     sort(x_sorted.begin(), x_sorted.end(), x_cmp);
//     // sort(y_sorted.begin(), y_sorted.end(), y_cmp);

//     for(auto i:x_sorted)cout<<i.at(0)<<" "<<i.at(1)<<" "<<i.at(2)<<'\n';
//     // for(auto i:y_sorted)cout<<i.at(1)<<" ";
//     long long max_gain=0;

    
//     // for(auto i=x_sorted.begin(); i!=x_sorted.end();){
//     //     for(auto j=(i+1); j!=x_sorted.end(); j++){
//     //         long long t_gain;

//     //         cout<<(*i).at(0)<<","<<(*i).at(1)<<" "<<(*j).at(0)<<","<<(*j).at(1)<<" gain : "<<t_gain<<"\n";
//     //         if(max_gain<t_gain){
//     //             max_gain=t_gain;}   
            
//     //         int x_2 = (*j).at(0);
//     //         while(x_2==(*j).at(0))j++;   
//     //     }
//     //     int x = (*i).at(0);
//     //     while(x==(*i).at(0))i++;
//     // }

//     cout<<max_gain;
// }