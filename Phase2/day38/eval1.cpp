#include <iostream>
#include <vector>
#include <thread>
#include <climits>
#include <future>

using namespace std;



void findSum(const vector<int> &input, promise<int> result){
    int sum = 0;
    for (int element : input){
        sum += element;
    }
    result.set_value(sum);
}

void findMin(const vector<int> &input, promise<int> result){
    int min = INT_MAX;
    for (int element : input){
        min = (element < min) ? element : min; 
    }
    result.set_value(min);
}

int main(){
    int n;
    cout << "enter no.of elements in the araay: "; 
    cin >> n ;
    vector<int> input;
    for(int i=0;i<=n;i++){
        cout << "enter element at : " << i <<": ";
        int num;
        cin << num ;
        input.pushback(num);
}
    promise<int> sumPromise,minPromise;
    future<int> sum = sumPromise.get_future();
    future<int> min = minPromise.get_future();
    thread thrFindSum(findSum, ref(input), move(sumPromise));
    thread thrFindMin(findMin, ref(input), move(minPromise));

    thrFindMin.join();
    thrFindSum.join();

    cout << "Sum: " << sum.get() << endl;
    cout << "Min: " << min.get() << endl;

    return 0;
}