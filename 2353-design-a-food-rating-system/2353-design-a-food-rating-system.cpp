class FoodRatings {
    unordered_map<string,int>FoodRating;
    unordered_map<string,string>FC;
    struct comp{
        bool operator()(const pair<int,string>&a,const pair<int,string>&b)const{
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        }
    };
    unordered_map<string,set<pair<int,string>,comp>>highestRate;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            FoodRating[foods[i]]=ratings[i];
            FC[foods[i]]=cuisines[i];
            highestRate[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cuis=FC[food];
        highestRate[cuis].erase({FoodRating[food],food});
        FoodRating[food]=newRating;
        highestRate[cuis].insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        return highestRate[cuisine].begin()->second;

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */