#include <iostream>
#include <queue>
using namespace std;

typedef vector<vector<long long>> Edge;
typedef vector<long long> Time;


class Solver{
    private:
        Edge edgesPrevToNext;
        Time inDegree;
        Time times;
        Time waitTimes;
        long long N, K;
        long long target;
        
    public:

        Solver(){
            // cout<<idx<<"th constructor is called"<<"\n";
            cin>>N>>K;

            edgesPrevToNext = Edge(N+1, vector<long long>());
            times = Time(N+1, 0);
            inDegree = Time(N+1, 0);
            waitTimes = Time(N+1, 0);

            for(long long i=1; i<N+1; ++i){
                cin>>times[i];
            }

            for(long long i=0; i<K; ++i){
                this->getEdges();
            }

            cin>>target;
        }




        void getEdges(){
            long long prev, next;

            cin>>prev>>next;

            // edgesNextToPrev[next].push_back(prev);    
            edgesPrevToNext[prev].push_back(next);

            ++inDegree[next];
        }


        long long solve(){
            

            queue<pair<long long, long long>> q;

            for(long long (size_t)id=1; id<inDegree.size(); ++id){
                if(inDegree[id]==0 && id != target){
                    q.push({id, times[id]});
                }
            }

            long long answer=INT64_MAX;

            while(!q.empty()){
                auto now = q.front();

                q.pop();

                long long id = now.first, time = now.second;

                if(id==this->target){
                    
                    answer = min(answer, time);
                    }

                for(auto next : edgesPrevToNext[id]){
                    --inDegree[next];
                    waitTimes[next] = max(waitTimes[next], time + times[next]);    
                    if(!inDegree[next])
                        q.push({next, waitTimes[next]});
                }
            }

            return answer>0?answer:0;
        }

        
};



long long main(){
    long long T;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;

    Solver *test_cases = new Solver[T];


    // for(auto &test : test_cases){
    //     test.test_prlong long();
    // }
    for(long long i=0; i<T; ++i){
        // cout<<"Test";
        cout<<test_cases[i].solve()<<"\n";
        
    }

}