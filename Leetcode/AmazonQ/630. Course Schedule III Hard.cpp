/*
630. Course Schedule III
Hard

There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

You will start on the 1st day and you cannot take two or more courses simultaneously.

Return the maximum number of courses that you can take.

 

Example 1:

Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
Example 2:

Input: courses = [[1,2]]
Output: 1
Example 3:

Input: courses = [[3,2],[4,3]]
Output: 0
 

Constraints:

1 <= courses.length <= 104
1 <= durationi, lastDayi <= 104


*/

class Solution {
public:
    
    /*
    Runtime: 310 ms, faster than 81.20% of C++ online submissions for Course Schedule III.
Memory Usage: 57.2 MB, less than 63.17% of C++ online submissions for Course Schedule III.
    */
    int scheduleCourse(vector<vector<int>>& courses) {
    /*
    we sort the courses based on end time
    keep a variable time which will hold the current time, after taking course
    now from begining to end
        pick a course
        check if it is possible to take
        if possible to take then take it -> update the time
        
        -> previously taken courses can be stored on a priority queue, max heap
        we only need the maximum of the courses taken
        this way we can reduce form N^2 to NlogN
        
        
        if not possible, then check previously taken courses, with which this can be swaped,
            previous course time should be bigger then this to be able to swap, find the biggest one
            main purpose is to minimize the course duration, take the smallest possible courses                 based on duration, 
            update the time if swaped
            
            
        first loop N, second loop N
        complexity N^2
    */        
        
        //TIME LIMIT EXCEEDED
        sort(courses.begin(), courses.end(), [](vector<int> &lhs, vector<int> &rhs) {
           return lhs[1] < rhs[1]; 
        });
        
        int time = 0;
        int courseCount = 0;
        vector<bool> courseTaken(courses.size(), false);
        
        auto cmp= [](pair<int, int> &lhs, pair<int, int> &rhs) {
          return lhs.first < rhs.first;  
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
            
        for(int i = 0; i < courses.size(); i++)  {
            int courseDuration = courses[i][0];
            int courseTime = courses[i][1];
            
            if(courseDuration > courseTime) continue;
            
            if(time + courseDuration <= courseTime) {
                //possibble to take
                time += courseDuration;
                courseCount++;
                courseTaken[i] = true;
                pq.push(make_pair(courseDuration, i));
                
            } else if(!pq.empty()) { //************* if none of the course taken
                //check from begining
                //find the maximum course duration that is bigger then this
                //this won't be empty
                
                int maxCourseIndex = pq.top().second;
                int maxCourseDuration = pq.top().first;
                
                //now swap if valid
                if(maxCourseDuration > courseDuration) {
                    
                    courseTaken[maxCourseIndex] = false;
                    time -= courses[maxCourseIndex][0];
                    
                    time += courseDuration;
                    pq.pop();
                    pq.push(make_pair(courseDuration, i));
                    courseTaken[i] = true;
                }
                
            }
        }
        return courseCount;
    }
    
    //TIME LIMIT EXCEEDED
    int scheduleCourse2(vector<vector<int>>& courses) {
    /*
    we sort the courses based on end time
    keep a variable time which will hold the current time, after taking course
    now from begining to end
        pick a course
        check if it is possible to take
        if possible to take then take it -> update the time
        if not possible, then check previously taken courses, with which this can be swaped,
            previous course time should be bigger then this to be able to swap, find the biggest one
            main purpose is to minimize the course duration, take the smallest possible courses                 based on duration, 
            update the time if swaped
            
            
        first loop N, second loop N
        complexity N^2
    */        
        
        //TIME LIMIT EXCEEDED
        sort(courses.begin(), courses.end(), [](vector<int> &lhs, vector<int> &rhs) {
           return lhs[1] < rhs[1]; 
        });
        
        int time = 0;
        int courseCount = 0;
        vector<bool> courseTaken(courses.size(), false);
        
        for(int i = 0; i < courses.size(); i++)  {
            int courseDuration = courses[i][0];
            int courseTime = courses[i][1];
            
            if(time + courseDuration <= courseTime) {
                //possibble to take
                time += courseDuration;
                courseCount++;
                courseTaken[i] = true;
            } else {
                //check from begining
                //find the maximum course duration that is bigger then this
                int maxCourseIndex = -1;
                int maxCourseDuration = 0;
                for(int j = 0; j < i; j++) {
                    if(courseTaken[j] == true && courses[j][0] > courseDuration ){
                       if(maxCourseDuration < courses[j][0]) {
                           maxCourseDuration = courses[j][0];
                           maxCourseIndex = j;
                       }
                    }
                }
                
                //now swap if valid
                if(maxCourseIndex != -1) {
                    courseTaken[maxCourseIndex] = false;
                    time -= courses[maxCourseIndex][0];
                    
                    time += courseDuration;
                    courseTaken[i] = true;
                }
                
            }
        }
        return courseCount;
    }
};

