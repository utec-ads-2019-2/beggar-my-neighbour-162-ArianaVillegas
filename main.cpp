#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int main() {
    bool turn; int count;
    vector<char> player[2], deck;
    map<char, int> value;
    value['A'] = 4;
    value['K'] = 3;
    value['Q'] = 2;
    value['J'] = 1;
    string c; cin>>c;
    while(c[0]!='#') {
        turn = 0; count = 0;
        player[0].push_back(c[1]);cin>>c;player[1].push_back(c[1]);
        for (int i = 0; i < 25; ++i) {
            cin >> c; player[0].push_back(c[1]);
            cin >> c; player[1].push_back(c[1]);
        }
        while (!player[turn].empty()) {
            char c = player[turn].back();
            player[turn].pop_back();
            deck.push_back(c);
            if (value.find(c)!=value.end()) {
                count = value[c] + 1;
                turn = !turn;
            }
            if (count) {
                --count;
                if (!count) {
                    turn = !turn;
                    player[turn].insert(player[turn].begin(),deck.crbegin(),deck.crend());
                    deck.clear();
                }
            } else turn = !turn;
        }
        cout << int(turn)+1 << setw(3) << player[!turn].size() << '\n';
        player[0].clear(); player[1].clear(); deck.clear(); cin >> c;
    }
    return 0;
}