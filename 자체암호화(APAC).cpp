#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define MAX 1001

int arr[MAX];
char trans[MAX];
int numbering = 0;

char key_code[26] = {
    'a','b','c','d','e','f','g','h','i','j',
    'k','l','m','n','o','p','q','r','s','t',
    'u','v','w','x','y','z'
};

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void decomposition(int n){
    if(isPrime(n)){
        arr[numbering++] = n;
        return;
    }
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            arr[numbering++] = i;
            decomposition(n / i);
            break;
        }
    }
}

void encryption(int N){
    numbering = 0;
    memset(arr, 0, sizeof(arr));
    memset(trans, 0, sizeof(trans));
    decomposition(N);

    for(int i = 0; i < numbering; i++){
        if(arr[i] < 26)
            trans[i] = key_code[arr[i]];
        else
            trans[i] = '?';
    }

    for(int i = 0; i < numbering; ){
        char current = trans[i];
        int count = 1;
        while(i + count < numbering && trans[i + count] == current){
            count++;
        }

        if(current == '?'){
            cout << arr[i];
        } else {
            if(count > 1)
                cout << count << current;
            else
                cout << current;
        }
        i += count;
    }
    cout << " ";
}

int strToInt(const string& s) {
    int num = 0;
    for(size_t i=0; i<s.size(); i++){
        char c = s[i];
        if(c >= '0' && c <= '9'){
            num = num*10 + (c - '0');
        } else {
            return 0;
        }
    }
    return num;
}

// 한 블록(예: "3cn") 복호화 시뮬레이션
int decryptBlock(const string& s) {
    int ascii = 1;
    size_t i = 0;

    while (i < s.size()) {
        // 반복횟수 숫자 여러 자리 읽기
        string countStr = "";
        while (i < s.size() && isdigit(s[i])) {
            countStr += s[i++];
        }
        int count = (countStr.empty()) ? 1 : strToInt(countStr);

        if (i >= s.size()) {
            // 숫자만 있는 경우
            ascii *= count;
            break;
        }

        char ch = s[i++];
        if (ch >= 'a' && ch <= 'z') {
            int prime = ch - 'a';
            for (int j = 0; j < count; j++) {
                ascii *= prime;
            }
        } else {
            // 만약 '?' 같은 특수 문자나 숫자가 뒤에 더 있으면 여기에 처리 가능
            // 현재 예시에는 필요 없음
        }
    }
    return ascii;
}


void decryption(const string& input){
    string temp = "";
    for(size_t i=0; i<=input.size(); i++){
        if(i == input.size() || input[i] == ' '){
            if(!temp.empty()){
                int ascii = decryptBlock(temp);
                cout << (char)ascii;
                temp = "";
            }
        } else {
            temp += input[i];
        }
    }
    cout << "\n";
}

int main() {
    int po;
    cout << "Choose option: 1 (encrypt) or 2 (decrypt): ";
    cin >> po;
    cin.ignore();

    cout << "Input text (for encrypt: raw text, for decrypt: encoded blocks separated by spaces):\n";
    string line;
    getline(cin, line);

    if(po == 1){
        for(size_t i = 0; i < line.size(); i++){
            char c = line[i];
            if(c == '\n') continue;
            encryption((int)c);
        }
        cout << "\n";
    } else if(po == 2){
        decryption(line);
    } else {
        cout << "Invalid option.\n";
    }

    system("pause");
}

