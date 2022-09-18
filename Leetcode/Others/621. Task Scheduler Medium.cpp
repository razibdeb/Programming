/*

621. Task Scheduler Medium

Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].
*/
/*
Runtime: 129 ms, faster than 52.94% of C++ online submissions for Task Scheduler.
Memory Usage: 34.5 MB, less than 71.70% of C++ online submissions for Task Scheduler.

*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        let's say A is the item which is maximum times, let's say 4
        now n could be from 1 to many
        A _ _ _
        A _ _ _
        A _ _ _
        A ??? -> don't need this because there will be no A next
        
        now let's say B, if B's count could be maximum 4 minimum 1
        if 4 then we can put it right after A, first 3 will take idle spots, and last one is right after A
        A B _ _
        A B _ _
        A B _ _
        A B
        if n is 1 then we have nothing to worry, we already fixed A & B, and just like this all future item will follow this, and will satisfy the condition, as new future item will have equal or less count
        
        if n is bigger like 10 still no worries, 
        
        now let's say we have C whose count is 2
        we will just put after B, if there is idle(n > 2, then there is idle spot) we can put them in 
        idle spot, if not, then just after B
        
        A B C _
        A B C _
        A B _ _
        A B
        
        now let's say we have D can have maximum count 2
        n = 4
        we are filling the spot instead of consuming the new spot
        putting it in idle spot will always satisfy the condition 
        A B C D _
        A B C _ _
        A B D _ _
        A B
        
        now E 2 times
        
        A B C D _
        A B C E _
        A B D E _
        A B
        
        A B C D F
        A B C E G
        A B D E H
        A B
        
        so after filling all character, if we don't have any idle spots left that means, 
        count of tasks is enough, no idle spot needed
        
        A B C D _
        A B C E _
        A B D E _
        A B
        if there are some idle spots left to fill up, then 
        result = tasks count + leftover of idle spots
        
        idle spots count will be the maximum count of particular tasks - 1
        for last tasks we don't need any idle spot
        A _ _ _
        A _ _ _
        A _ _ _
        A -> no need here
        
        */
        
        vector<int> taskCount(26, 0); // 26 character 
        for(int i = 0; i < tasks.size(); i++) {
            taskCount[tasks[i] - 'A']++;
        }
        //O(26log26)
        sort(taskCount.rbegin(), taskCount.rend());
        
        int maxTaskCount = taskCount[0];
        
        int idleSpots = (maxTaskCount - 1) * n;
        
        //starting from 1 cause for first one we created idle spots
        for(int i = 1; i < 26; i++) {
            if(taskCount[i] == maxTaskCount) {
                idleSpots -= maxTaskCount - 1;//if it's count is same as maximum one, then just like that one, we need one less idle spot for this
            } else {
                idleSpots -= taskCount[i];
            }
            
        }
        if(idleSpots > 0) {
            return tasks.size() + idleSpots;
        } else {
            return tasks.size(); // we don't need extra spots
        }
    }
};

/*
["A", "A", "A", "A", "A", "B", "B", "B", "B", "B", "C", "C", "C", "C", "C", "D", "D", "D"],
A 5
B 5
C 5
D 3

ABCD
ABCD
ABCD
ABC
ABC
Hi @lubiflash Only if the frequency of "B", "C" and "D" is not greater than "A". The first solution should work. Thinking about the idle_time = (f_max - 1) * n is under control of the cool down period. In this case, we can just down the idle time to zero when we iterate "B". Because "B" just fill up the idle time holes between As. (the last 'B' is after the last 'A'). So for the remaining part of "C". we can insert them one by one to every interval between As which of course will not break the cooling down policy. And also "D" is. So CPU would not have new idle time. So the result is the length of tasks. Hope this is helpful.
*/