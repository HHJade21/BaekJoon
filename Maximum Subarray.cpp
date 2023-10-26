#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//sub-array의 정보를 담은 구조체. 
//find-max-array 함수에서 재귀적으로 리턴할때 해당 구조체를 이용해 최대부분배열의 정보를 상위 프로시저로 전달한다.
struct sa{
    int low;
    int high;
    int sum;
};

sa FMCS(vector<int>& a, int low, int mid, int high){//find max cross subarray. mid에 걸친 최대부분배열을 찾는 함수
    int i = mid, j = mid+1;//base case일 때는 해당 함수가 호출되지 않으므로 mid를 기준으로 두 영역으로 나누어도 된다.
    int lMax = INT_MIN, rMax = 0;//원소가 하나라도 포함되어야 하므로 lMax는 -∞로, 여기서 오른쪽 부분배열이 포함되지 않아도 FMS에서 최대배열 골라지니까 rMax는 0으로 초기화
    int sum = 0, lIndex = mid, rIndex = mid+1; //sum은 mid에서 양방향으로 더해나가며 저장할 임시 변수. 얘랑 양쪽 max랑 비교해서 더 커질때마다 갱신
    for(;i>=low;i--){
        sum += a[i];//mid부터 왼쪽으로 하나씩 이동하며 전부 더해준다.
        if(sum > lMax){//합이 lMax보다 커질때마다 왼쪽부분배열의 최대합과, 최대부분배열 low인덱스 갱신
            lMax = sum;
            lIndex = i;
        }
    }

    sum = 0;//여기서도 sum 똑같이 써야되니까 초기화
    for(;j<=high;j++){//mid에 붙어있는 오른쪽 부분배열 중 합이 최대인 값과 인덱스 구하기. 위에랑 똑같은데 진행방향이 오른쪽인것만 다름.
        sum+=a[j];
        if(sum > rMax){
            rMax = sum;
            rIndex = j;
        }
    }

    return {lIndex, rIndex, lMax + rMax};
}

//low~mid에 있는 최대배열,mid+1~high에 있는 최대배열, 양쪽에 걸친 최대배열을 비교하여 가장 큰 것을 리턴하는 함수
sa FMS(vector<int>&a, int low, int high){
    if(low == high) return {low, high, a[low]}; //크기가 1인 베이스 케이스일 경우 원소 하나의 값을 리턴

    int mid = (low+high)/2;
    sa left = FMS(a, low, mid);//왼쪽에 있는 최대부분배열
    sa right = FMS(a, mid+1, high);//오른쪽에 있는 최대부분배열
    sa cross = FMCS(a, low, mid, high);//mid에 걸쳐있는(low<=i<=mid, mid+1<=j<=high인) 최대부분배열

    //셋 중 가장 sum이 큰 부분배열을 찾아서
    if(left.sum >= right.sum && left.sum >= cross.sum) //왼쪽 부분배열의 최대합이 가장 크면
        return left;//걔를 리턴
    else if(right.sum >= left.sum && right.sum >= cross.sum) //오른쪽 부분배열의 최대합이 가장 크면
        return right;//걔를 리턴
    else    //mid에 걸친 부분배열의 최대합이 가장 크면
        return cross;//걔를 리턴

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    cin >> t;
    for(int test = 0; test < t; test++){
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        cout << FMS(arr, 0, n-1).sum << "\n";
    }
}