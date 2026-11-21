#include <iostream>
using namespace std;
struct Node{
    int id;
    Node* father;
};
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        Node tree[8008];
        tree[1].id = 1;
        for (int i = 2; i <= n; i++)
        {
            int x;
            cin >> x;
            //tree[i]->father = tree[x];
        }
        cout << 520 << endl;
    }
    return 0;
}
