#include <iostream>

using namespace std;
//wyszukiwanie poprzednika i następnika

struct wez{
    wez* left;
    wez* right;
    wez* up;
    int val;
};

struct drzew{
    wez* root;

    drzew(){
        root = nullptr;
    }

    void add(wez* &temp, int x) {
        if (temp == nullptr) {
                temp = new wez;
                temp->val = x;
                temp->left = nullptr;
                temp->right = nullptr;
                
        }
        else {
            if (x >= temp->val) {//w prawo
                add(temp->right,x);
            }
            else{//w lewo
                add(temp->left,x);
            }
        }
    }

    void find(wez* temp, int num){
        int x = num;

        if(temp != nullptr){
            if(x == temp->val){
                cout<<temp<<"\n";
                cout<<temp->val<<"\n";
                
            }

            else if(x > temp->val){
                temp = temp->right;
                find(temp, x);
            }

            else if(x < temp->val){
                temp = temp->left;
                find(temp, x);
            }
        }
        else{
            cout<<"Nie znaleziono elementu"<<"\n";
        }
    }

    int min(wez* temp){
        while(temp->left!=nullptr){
            temp = temp->left;
        }
        return temp->val;
    }

    int max(wez* temp){
        while(temp->right!=nullptr){
            temp = temp->right;
        }
        return temp->val;
    }

    void print_inorder(wez* root){
        if(root != nullptr){
            print_inorder(root->left);
            cout << root->val<<"\n";
            print_inorder(root->right);
        }
    }
};

int main()
{
    drzew bst;

    int tab[10]={12,16,25,14,3,8,22,16,10,27};

    for(int i =0; i<10; i++){
        bst.add(bst.root, tab[i]);
    }

    cout<<"max = "<<bst.max(bst.root)<<"\n";
    cout<<"min = "<<bst.min(bst.root)<<"\n";
    bst.find(bst.root, bst.min(bst.root));

    cout<<"\n";

    bst.print_inorder(bst.root);
}