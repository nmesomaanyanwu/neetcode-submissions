class Twitter {
public:
    /*what to do 
    usersId -> tweetID 
    
    */    
    unordered_map<int, vector<int>> following; //we have a map from follower to followee(people the follower follows)

    vector<pair<int, int>> storage;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        storage.push_back({userId, tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        /*we can use a deque to put new more recent tweets and pop less recent ones*/
        vector<int> news;
        
        for (int i = storage.size()-1 ; i >=0 && news.size() < 10;i--) {
            // we start from the most recent twwets at the back of storage 
            int tweetUserId = storage[i].first;
            int tweetId = storage[i].second;


            //if the tweet is the usersId tweet or cuurentID is in userid flowee kist         
            if (tweetUserId == userId ||
                                                                    find(following[userId].begin(),following[userId].end(),tweetUserId)!=following[userId].end()){
                news.push_back(tweetId);
            }


        }


        return news;
        
    }
    
    void follow(int followerId, int followeeId) {
        if ((followerId != followeeId) &&find(following[followerId].begin(),following[followerId].end(), followeeId)== following[followerId].end() ){
            following[followerId].push_back(followeeId);
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = find(following[followerId].begin(), following[followerId].end(),followeeId);
        if (it != following[followerId].end()){
            following[followerId].erase(it);
        }
        
        
    }
};
