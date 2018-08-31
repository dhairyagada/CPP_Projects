#include <iostream>
#include <string>
using namespace std;
int main() {

    string c;
    string paragraph;
    do {
        getline(cin, c);
        paragraph += c + "\n";
    } while (c.length() > 0);
    int j=0;
    int flag= 1;
    while(j!=paragraph.length()+1)
    {
        if(paragraph[j]=='\"' && flag==1)
        {
            paragraph.replace(j,1,"``");
            flag=0;
        }
        else if(paragraph[j]=='\"' && flag==0)
        {
            paragraph.replace(j,1,"''");
            flag=1;
        }
        j++;
    }
    cout<<paragraph;
    return 0;
}