#include <iostream>
#include <ext/rope>
#include <cstring>

using namespace std;
using namespace __gnu_cxx;

const int maxn = 2005;
const int code_size = 100;
rope<char> *git[maxn];

void add_newline(char *str)
{
    int len = strlen(str);
    str[len] = '\n';
    for(int i = len + 1; i < code_size + 1; ++i){
        str[i] = '\0';
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    int line_num;
    cin >> line_num;
    char str[code_size + 1];
    cin.ignore(10, '\n');
    git[0] = new rope<char>;
    for(int i = 0; i < line_num; ++i){
        cin.getline(str, code_size);
        add_newline(str);
        for(int j = 0; j < code_size; ++j){
            git[0]->insert(i * code_size + j, str[j]);
        }
    }
    char code[code_size + 1];
    for(int i = 1; i <= N; ++i){
        git[i] = new rope<char>(*git[i - 1]);
        char op;
        int line;
        cin >> op >> line;
        cin.ignore(10, '\n');
        if(op == '+'){
            cin.getline(code, code_size);
            add_newline(code);
            for(int j = 0; j < code_size; ++j){
                git[i]->insert((line - 1) * code_size + j, code[j]);
            }
        } else {
            git[i]->erase((line - 1) * code_size, code_size);
        }
    }
    int Q;
    cin >> Q;
    bool is_printed = false;
    for(int i = 0; i < Q; ++i){
        if(is_printed) cout << '\n';
        is_printed = true;
        int version;
        cin >> version;
        for(auto c : *git[version]){
            if(c != '\0') cout << c;
        }
    }
}
