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
    //S�� ���� ��� �������� ���� ��� ���� ���� �ε���
    for (int i = 0; i < nums.size(); i++)
    {
        tree[S + i] = nums[i]; //S~S+n-1
    }
    //Leaf�� �� �ݿ�
    for (int i = S - 1; i > 0; i--) { //�Ʒ������� ���� ä�� �ö�!
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    return;
    //���� ��� ä�� 
}


void updateBU(int target, ll value) 
{
    //leaf���� target�� ã��
    int node = S + target - 1;

    //value �ݿ�
    tree[node] = value;

    //Root�� ���� �Ҷ� ���� �θ� �� �ݿ�
    node /= 2;
    while (node > 0)//��Ʈ �����Ҷ� ����
    {
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; //value�� ����� �� �ݿ��ϱ� ����
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
    //Leaf���� left, right ����
    int left = S + queryLeft - 1;
    int right = S + queryRight - 1;
    ll sum = 0;

    while (left <= right)
    {
        //���� ��尡 Ȧ���̸� ���� ��� �� ����ϰ� ��ĭ ������
        if (left % 2 == 1) 
        {
            sum += tree[left++];
        }
        // ���� ��尡 ¦�� �̸� ���� ��� �� ����ϰ� ��ĭ ������
        if (right % 2 == 0) 
        {
            sum += tree[right--];
        }
        //����, ����, ��� �θ�� �̵�
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
    cin >> n; // ���� �մ� Ƚ��

    S = 1;
    while (S < max) S *= 2; //S�� ����8
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