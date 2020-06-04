//uva10010
#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
    int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; //8 direction
    int n;
    cin >> n;                   //case num
    cin.ignore();               //delete the buffer
    for (int i = 0; i < n; i++) //case loop
    {
        getchar();
        int a, b;
        cin >> a >> b; //the grid size
        cin.ignore();
        char table[a][b];
        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < b; k++)
                cin >> table[j][k];
            getchar();
        }
        int m;
        cin >> m; //target word number
        cin.ignore();
        string s[m];         //save the target word
        int ans[m][3] = {0}; //save the answer row = target word, col 0 = length, 1 = row, 2 = col
        for (int j = 0; j < m; j++)
            getline(cin, s[j]); //get target word

        for (int j = 0; j < a; j++)                                  //grid size row
            for (int k = 0; k < b; k++)                              //grid size column
                for (int g = 0; g < m; g++)                          //target num
                    if (ans[g][0] < (int)s[g].length()               /* shorter than length loop */
                        && tolower(s[g][0]) == tolower(table[j][k])) //hit char the first
                    {
                        for (int h = 0; h < 8; h++) // 8 direction
                        {
                            int step = 0;
                            while (                              /*to confirm the step size*/
                                   (j + d[h][0] * step) >= 0     /*row+direction_row*step>=0*/
                                   && (k + d[h][1] * step) >= 0  /*col+direction_y*step>=0*/
                                   && (j + d[h][0] * step) <= a  /*row+direction_x*step<=a*/
                                   && (k + d[h][1] * step) <= b) /*col+direction_x*step<=b*/

                            {
                                if (tolower(s[g][step]) == tolower(table[j + d[h][0] * step][k + d[h][1] * step]))
                                /*hit the char according with step*/
                                {
                                    ans[g][0]++; //the word length
                                    step++;
                                }
                                else
                                {
                                    ans[g][0] = 0;
                                    break;
                                }
                                if (ans[g][0] == (int)s[g].length())
                                {
                                    ans[g][1] = j + 1;
                                    ans[g][2] = k + 1;
                                    break;
                                }
                            }
                            if (ans[g][0] == (int)s[g].length())
                                break;
                            else
                                ans[g][0] = 0;
                        }
                    }
        for (int j = 0; j < m; j++)
        {
            cout << ans[j][0] << " ";
            cout << ans[j][1] << " " << ans[j][2] << endl;
        }

        if (i < n - 1)
            cout << endl;
    }
    return 0;
}