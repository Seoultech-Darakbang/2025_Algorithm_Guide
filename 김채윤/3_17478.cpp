#include <iostream>

using namespace std;

int N;

string s1 = "\"재귀함수가 뭔가요?\"\n";
string s2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
string s3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
string s4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";

void recursion(const string& indent, int n) {
    cout << indent << s1;

    if (n == N) {
        cout << indent << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        cout << indent << "라고 답변하였지.\n";
        return;
    }
    cout << indent << s2;
    cout << indent << s3;
    cout << indent << s4;
    
    recursion(indent + "____", n + 1);
    cout << indent << "라고 답변하였지.\n";

}

int main() {
    cin >> N;
    
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

    string indent = "";

    recursion(indent, 0);
    return 0;
}

