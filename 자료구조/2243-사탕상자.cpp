#include<iostream>
#include<vector>

using namespace std;
#define ll long long
#define max 1000000

vector<ll> tree;
vector<ll> nums;
ll S;

typedef struct{
    ll first;
    ll second;
    ll third;
}three;

vector<three> v;

void initBU(ll S) 
{
    //S는 리프 노드 개수이자 리프 노드 제일 왼쪽 인덱스
    for (int i = 0; i < nums.size(); i++)
    {
        tree[S + i] = nums[i]; //S~S+n-1
    }
    //Leaf에 값 반영
    for (int i = S - 1; i > 0; i--) { //아래서부터 위로 채워 올라감!
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    return;
    //내부 노드 채움 
}


void updateBU(int target, ll value) 
{
    //leaf에서 target을 찾음
    int node = S + target - 1;

    //value 반영
    tree[node] = value;

    //Root에 도닫 할때 까지 부모에 값 반영
    node /= 2;
    while (node > 0)//루트 도달할때 까지
    {
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; //value로 변경된 값 반영하기 위함
        node /= 2;
    }
}

void updateTD(int left, int right, int node, int index, ll diff)
{
    if (left <= index && index <= right) 
    {
        tree[node] += diff;

        if (left != right) 
        {
            int mid = (left + right) / 2;
            updateTD(left, mid, node * 2, index, diff);
            updateTD(mid + 1, right, node * 2 + 1, index, diff);
        }
    }
}

ll queryBU(int queryLeft, int queryRight) 
{
    //Leaf에서 left, right 설정
    int left = S + queryLeft - 1;
    int right = S + queryRight - 1;
    ll sum = 0;

    while (left <= right)
    {
        //좌측 노드가 홀수이면 현재 노드 값 사용하고 한칸 옆으로
        if (left % 2 == 1) 
        {
            sum += tree[left++];
        }
        // 우측 노드가 짝수 이면 현재 노드 값 사용하고 한칸 옆으로
        if (right % 2 == 0) 
        {
            sum += tree[right--];
        }
        //좌측, 우측, 모두 부모로 이동
        left /= 2;
        right /= 2;
    }
    return sum;
}

ll queryTD(int left, int right, int node, int count) 
{
    if (left == right) 
    {
        return left;
    }

    int mid = (left + right) / 2;

    if (tree[node * 2] >= count) 
    {
        return queryTD(left, mid, node * 2, count);
    }
    else 
    {
        return queryTD(mid + 1, right, node * 2 + 1, count - tree[node * 2]);
    }
}
void init(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(void)
{
    init();
    int n;
    cin >> n; // 사탕 손댄 횟수

    S = 1;
    while (S < max) S *= 2; //S는 현재8
    tree.resize(S * 2, 0);

    for (int i = 0; i < n; i++) 
    {
        int a, b;
        int c = 0;
        cin >> a;

        if (a == 2) 
        {
            cin >> b >> c;
            updateTD(1, S, 1, b, c);
        }
        else if (a == 1) 
        {
            cin >> b;
            int index = queryTD(1, S, 1, b);
            updateTD(1, S, 1, index, -1);
            cout << index << '\n';
        }
    }
    return 0;
}