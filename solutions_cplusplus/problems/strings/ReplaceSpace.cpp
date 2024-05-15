#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
#include "../../common/timer.h"
#include "../../common/arraysUtils.h"
#include "../../common/generateUtils.h"
#include "../../common/testUtils.h"
using namespace std;

int replaceSpace(char *str)
{
    int spaces = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i]==' '){
            spaces +=1;
        }
    }

    // hello_every_one len= 15
    // hello%20every%20one, 4 more= 19  

    int maxlen = strlen(str)+2*spaces;
    // str[maxlen]= '\0';
// start from right to left bc our array in extends at right side
    for (int i=strlen(str)-1; i >=0; i--)
    {
        /* code */
        if(str[i]==' '){
            str[maxlen-1]='0'; 
            str[maxlen-2]='2';
            str[maxlen-3]='%';
            maxlen-=3;

        }else{
            str[maxlen-1]= str[i];
            maxlen--;
        }
    }
    

}

int main()
{
    char input[1000]= "hello every one";
    replaceSpace(input);
    cout<<input<<endl;
}