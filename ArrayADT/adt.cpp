#include <iostream>

using namespace std;

int main() {
    int cap;
    cout << "Enter array capacity: ";
    cin >> cap;

    if (cap <= 0) return 1;


    int* arr = new int[cap];
    int n = 0; 
    int action;

    while (true) {
        cout << "\n1. Print\n2. Push\n3. Insert\n4. Delete\n5. Search\n6. Exit\nYour Choice: ";
        cin >> action;

        if (action == 6) {
            break;
        }

        if (action == 1) {
            if (n == 0) {
                cout << "Empty." << endl;
                continue;
            }
            cout << "Items: ";
            for (int i = 0; i < n; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else if (action == 2) {
            if (n >= cap) {
                cout << "Full!" << endl;
                continue;
            }
            int val;
            cout << "Val: ";
            cin >> val;
            arr[n++] = val;
        }
        else if (action == 3) {
            int idx, val;
            cout << "Index: "; cin >> idx;
            cout << "Value: "; cin >> val;

            if (idx < 0 || idx > n || n >= cap) {
                cout << "Can't insert there." << endl;
                continue;
            }


            int j = n;
            while (j > idx) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[idx] = val;
            n++;
        }
        else if (action == 4) {
            int idx;
            cout << "Index: "; 
            cin >> idx;

            if (idx < 0 || idx >= n) {
                cout << "Invalid Index." << endl;
                continue;
            }

            for (int i = idx; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
        }
        else if (action == 5) {
            int target, loc = -1;
            cout << "Target: "; 
            cin >> target;

            for (int i = 0; i < n; i++) {
                if (arr[i] == target) {
                    loc = i;
                    break;
                }
            }

            if (loc != -1) cout << "At position: " << loc << endl;
            else cout << "Missing." << endl;
        }
        else {
            cout << "Try again." << endl;
        }
    }

    delete[] arr;
    return 0;
}
