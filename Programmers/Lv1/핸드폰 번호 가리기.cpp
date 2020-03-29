#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int plen = phone_number.length() - 4;
    for (int i = 0; i < plen; i++){
        phone_number[i] = '*';
    }
    return phone_number;
}
