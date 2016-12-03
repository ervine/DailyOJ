#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    struct item {
        int num;
        int frequency;
        item *next;
    };
    item *HashTable[100];
public:
    int topKFrequent(int nums, int k) {
        for(int i = 0; i<100; i++) {
            HashTable[i]->num = 0;
            HashTable[i]->frequency = 0;
            HashTable[i]->next = NULL;  cout << i << endl;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
