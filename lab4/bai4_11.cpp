#include <bits/stdc++.h>
using namespace std;

// Ho Sy The - 20200614

struct battlefield {
    int attack, defense;
};

int n, s;
battlefield warfare[100007];
int max_enemy;

auto prior = [](const battlefield&a, const battlefield&b) -> bool {
        int rank_a, rank_b;
        if(a.attack <= a.defense) 
            rank_a = a.attack;
        else rank_a = a.defense;

        if(b.attack <= b.defense) 
            rank_b = b.attack;
        else rank_b = b.defense;

        return rank_a < rank_b;
    };

priority_queue<battlefield, vector<battlefield>, decltype(prior)> pq(prior);

int main() {
    cout << "Ho Sy The - 20200614\n";

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> warfare[i].attack >> warfare[i].defense;
        pq.push(warfare[i]);
        max_enemy += warfare[i].attack;
    }

    while(s && !pq.empty()) {
        auto i = pq.top();
        pq.pop();
        if(i.attack <= i.defense) {
            --s;
            max_enemy -= i.attack;
        } else {
            int warior = min(s, i.attack / i.defense);
            int remain_enemy = i.attack - i.defense * warior;

            if(remain_enemy) pq.push(battlefield{remain_enemy, i.defense});

            max_enemy -= warior * i.defense;
            s -= warior;
        }
    }

    cout << max(0, max_enemy);

    return 0;
}
