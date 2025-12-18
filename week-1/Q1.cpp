/*#include <iostream>
using namespace std;
int main() {
	const int rows = 7;
	const int cols = 5;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == 0 || i == 3 || i == 6) cout << '*';
			else if (j == 0 || j == cols - 1) cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}*/
#include <iostream>
using namespace std;

/*int main() {
    const int rows = 7;
    const int cols = 6;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // Top, middle, and bottom horizontal bars
            if ((i == 0 || i == 3 || i == 6) && j < cols - 1)
                cout << "*";

            // Left vertical bar
            else if (j == 0)
                cout << "*";

            // Right vertical bar (only for B curves)
            else if ((i == 1 || i == 2 || i == 4 || i == 5) && j == cols - 1)
                cout << "*";

            // Empty spaces
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}*/
int main() {
    cout << "***** " << endl;
    cout << "*    *" << endl;
    cout << "*    *" << endl;
    cout << "***** " << endl;
    cout << "*    *" << endl;
    cout << "*    *" << endl;
    cout << "***** " << endl;
    return 0;
}
