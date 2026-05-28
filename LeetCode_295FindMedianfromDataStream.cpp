//Approach1 : Bruteforce
class MedianFinder {
public:
    vector<int> vec;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        vec.push_back(num);
    }
    
    double findMedian() {
        vector<int> temp = vec;//original array ko disturb nhi kra 

        sort(begin(temp) , end(temp));

        int n = temp.size();

        if(n%2 == 1){
            //odd case
            return temp[n/2];
        }else{
            return (temp[n/2]+temp[n/2-1])/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


//T.C : O(nlogn)
//S.C : O(n)

//Approach2 : Better
class MedianFinder {
public:
    vector<int> vec;
    int i = 0;
    MedianFinder() {
        vec.resize(5*10000*1);
    }
    
    void addNum(int num) {
        if(i == 0){
            vec[i++] = num;
            return;
        }
        int j = i-1;
        while(j >= 0 && vec[j] < num){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = num;
        i++;
    }
    
    double findMedian() {
        int n = i;

        if(n%2==0){
            //even
            return (vec[n/2] + vec[n/2-1])/2.0;
        }
        return vec[n/2];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//T.C : O(n)
//s.C :(N)

//Approach3: 
class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int,vector<int> , greater<int>> rightMinHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //step1 . compare from leftMaxHeap.top() , if greater put in rightMinHeap
        if(leftMaxHeap.empty() || leftMaxHeap.top() >= num){
            leftMaxHeap.push(num);
        }else{
            rightMinHeap.push(num);
        }

        //always maintain leftMaxHeap.size() - rightMinHeap.size() = 1(mtlb sirf ek ka different , usme bhi leftMaxHeap bada) || both equal
        if(leftMaxHeap.size() > rightMinHeap.size() + 1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }else if(rightMinHeap.size() > leftMaxHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        //case1 . jb dono heaps me same no of elements ->even
        if(leftMaxHeap.size() == rightMinHeap.size()){
            double mean = (leftMaxHeap.top() + rightMinHeap.top())/2.0;
            return mean;
        }else{
            int median = leftMaxHeap.top();
            return median;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//T.C : O(logn)
//S.C :O(N)
