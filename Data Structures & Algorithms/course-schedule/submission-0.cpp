enum class CStatus : uint8_t {NOTATTEMPT, ATTEMPTING, COMPLETED};

class Course {
    
    int numC;
    std::vector<std::vector<int>> prereq;

    public:
        Course(int n): numC(n), prereq(n) {}

        void addCourse(int crs, int pre ){
            prereq[crs].push_back(pre);
        }

        bool canFinish() {
            std::vector<CStatus> states(numC, CStatus::NOTATTEMPT); 
            for (int i=0; i < numC ; i++){
                if ( states[i] == CStatus::NOTATTEMPT){
                    std::stack<int> stck;
                    stck.push(i); 
                    while (!stck.empty()){
                        int curr = stck.top();
                        if (states[curr] == CStatus::NOTATTEMPT){
                            states[curr] = CStatus::ATTEMPTING;
                            for(int pre : prereq[curr]){
                                if (states[pre] == CStatus::ATTEMPTING ) return false;  // cycle detected
                                if (states[pre] == CStatus::NOTATTEMPT) stck.push(pre);                                        
                            }
                        } else {
                            states[curr] = CStatus::COMPLETED;
                            stck.pop();
                        }
                    }
                }
            }
            return true;
        }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Course crs(numCourses);
        for (auto& pre :prerequisites) crs.addCourse(pre[0], pre[1]);
        return crs.canFinish();
    }
};
