class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minLandEnd = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++)
            minLandEnd = min(minLandEnd,
                             landStartTime[i] + landDuration[i]);

        int ans1 = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); j++)
            ans1 = min(ans1,
                       max(minLandEnd, waterStartTime[j]) +
                       waterDuration[j]);

        int minWaterEnd = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); j++)
            minWaterEnd = min(minWaterEnd,
                              waterStartTime[j] + waterDuration[j]);

        int ans2 = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++)
            ans2 = min(ans2,
                       max(minWaterEnd, landStartTime[i]) +
                       landDuration[i]);

        return min(ans1, ans2);

    }
};