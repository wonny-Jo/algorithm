#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (answer.empty() || answer[answer.size() - 1] < a)
            answer.push_back(a);
        else
        {
            int index = lower_bound(answer.begin(), answer.end(), a) - answer.begin();
            answer[index] = a;
        }
    }
    cout << answer.size() << '\n';
    return 0;
}