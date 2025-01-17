/********************************************
作者:Alfeim
题目:二进制手表
时间消耗:8ms
解题思路:可以直接遍历一遍所有情况再判断,也可以直接
用回溯的方法
********************************************/
class Solution {
public:
    bitset<10> Bits;
    vector<string> res;
    vector<string> readBinaryWatch(int num) {
        Solve(0,num);
        return res;
    }
    
    void Solve(int begin,int left){
        if(left == 0){
            string tmp = Bits.to_string();
            bitset<4> hours(tmp);
            bitset<6> minute(tmp.substr(4));
            int front = hours.to_ulong();
            int back = minute.to_ulong();
            if(front <= 11 && back <= 59){
                string m;
                string h = to_string(front);
                
                if(back < 10)
                    m = "0" + to_string(back);
                else
                    m = to_string(back);
                res.push_back(h + ":" + m);
            }
        }
        
        if(begin >= 10)
            return;
        
        
        for(int i = begin ; i < 10 ;++i){
            Bits[i] = 1;
            Solve(i+1,left-1);
            Bits[i] = 0;
        }
        
    }
    
    
};
