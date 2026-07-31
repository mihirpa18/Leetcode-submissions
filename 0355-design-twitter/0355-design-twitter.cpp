class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> post;
    unordered_map<int,set<int>> followers;
    int timer;

    Twitter() {
       timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;\
        for(auto &p : post[userId]){
            pq.push({p.first,p.second});
        }
        for(auto &f : followers[userId]){
            for(auto &p : post[f]){
                pq.push({p.first,p.second});
            }
        }

        int k = 10;
        vector<int>res;
        while(k>0 && !pq.empty()){
            auto [time,tweet] = pq.top();
            pq.pop();

            res.push_back(tweet);
            k--;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */