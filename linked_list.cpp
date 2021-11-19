#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node *l, *r;
    Node(){
        l = nullptr;
        r = nullptr;
    }
};

struct LinkedList{
    int size;
    Node *first, *last;

    LinkedList(){
        last = new Node();
        first = last;
        size = 0;
    }

    void addBack(int el){
        if(size == 0){
            last = new Node();
            first = last;
            last->val = el;
        }
        else {
            Node *node = new Node();
            node->val = el;
            last->r = node;
            node->l = last;
            last = node;
        }
        size++;
    }

    void addFront(int el){
        if(size == 0){
            last = new Node();
            first = last;
            last->val = el;
        }
        else {
            Node *node = new Node();
            node->val = el;
            first->l = node;
            node->r = first;
            first = node;
        }
        size++;
    }

    void showList(){
        Node *t = first;
        while(t != nullptr){
            cout << t->val << " ";
            t = t->r;
        }
        cout << endl;
    }

    void del_back(){
        if(size != 0){
            Node *tmp = last;
            last = nullptr;
            last = tmp->r;
            size --;
        }
    }

    void del_front(){
        if(size != 0){
            Node *tmp = first;
            first = nullptr;
            first = tmp->l;
            size --;
        }
    }

    int begin(){
        return first -> val;
    }

    int end(){
        return last -> val;
    }

    void bol(){
         Node *t = first;
         int max = 0;
        while(t != nullptr){
            if (t->val>max) max = t->val;
            t = t->r;
        }
        cout << max << endl;
    }

    void mal(){
         Node *t = first;
         int min = 2000000000;
        while(t != nullptr){
            if (t->val<min) min = t->val;
            t = t->r;
        }
        cout << min << endl;
    }

    void len(){
    cout << size << endl;
    }

    void isEmpty(int el){
        Node *t = first;
        while(t != nullptr){
            if (t->val==el) {cout << 1 << endl; return ;}
            t = t->r;
        }
        cout << 0 << endl;
    }
};

int toInt(string s){
    int ans = 0, r = 1;
    for(int i = (int)s.size() - 1; i >= 0; i--){
        ans += (s[i] - '0') * r;
        r *= 10;
    }
    return ans;
}

int main(){

    LinkedList *l = new LinkedList();

    int n;
    cin >> n;

    vector<int> ans;

    for(int i = 0; i < n; i++){

        int c;
        cin >> c;

        if(c == 1){
            int s;
            cin >> s;
            l->addFront(s);
        }
        if(c == 2){
            int s;
            cin >> s;
            l->addBack(s);
        }
        if(c == 3){
            int u = l->begin();
            ans.push_back(u);
            l->del_front();
        }
        if(c == 4){
            int u = l->end();
            ans.push_back(u);
            l->del_back();
        }

    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

}
