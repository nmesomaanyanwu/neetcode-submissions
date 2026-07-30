class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        we use a maxheap to keep the most frquent tasks shown 
        and a queue to store [taks remaining , what time to add it]
        the way the algorith works 
        1) first find the count of each taks 
        2) arrange the max heap by count 
        3) while our heap isnt done or queue isnt done  then weupdate are time bacause were about to use a unit 
        4) if max heap we pop the top  and if the current  frewuency is not 0 after -1 we add it back to out queue with the current time it would be able to work 
        5) we check if time is equal to the top od ythe queue and pop off the queue and put in the max heap 
        6) We return time 

        */
        unordered_map<char, int> counter;
        for (auto& task : tasks){
            counter[task]++;
        }

        priority_queue<int> maxHeap;
        deque<pair<int , int>> schedule; //contains [remaining tasks , when task can resume ]

        for (auto& count : counter){
            maxHeap.push(counter[count.first]);
        } 

        int time = 0;
        
        while (!maxHeap.empty() || !schedule.empty()){
            time++;

            if(!maxHeap.empty()){
                int count = maxHeap.top() - 1;
                maxHeap.pop();

                if (count != 0){
                    schedule.push_back({count , time+ n});
                }
            }  

            if (schedule[0].second == time){
                int next = schedule[0].first;
                schedule.pop_front();
                maxHeap.push(next);

            }



        }
        

        return time;
    }
};
