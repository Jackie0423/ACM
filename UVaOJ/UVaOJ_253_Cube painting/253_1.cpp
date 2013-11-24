/*
 Cube painting 

We have a machine for painting cubes. It is supplied with three different colors: blue, red and green. Each face of the cube gets one of these colors. The cube's faces are numbered as in Figure 1.

picture21

Figure 1.

Since a cube has 6 faces, our machine can paint a face-numbered cube in  tex2html_wrap_inline126 different ways. When ignoring the face-numbers, the number of different paintings is much less, because a cube can be rotated. See example below. We denote a painted cube by a string of 6 characters, where each character is a b, r, or g. The  tex2html_wrap_inline128 character ( tex2html_wrap_inline130 ) from the left gives the color of face i. For example, Figure 2 is a picture of rbgggr and Figure 3 corresponds to rggbgr. Notice that both cubes are painted in the same way: by rotating it around the vertical axis by 90 tex2html_wrap_inline134 , the one changes into the other.

tex2html_wrap138  tex2html_wrap140

Input

The input of your program is a textfile that ends with the standard end-of-file marker. Each line is a string of 12 characters. The first 6 characters of this string are the representation of a painted cube, the remaining 6 characters give you the representation of another cube. Your program determines whether these two cubes are painted in the same way, that is, whether by any combination of rotations one can be turned into the other. (Reflections are not allowed.)

Output

The output is a file of boolean. For each line of input, output contains TRUE if the second half can be obtained from the first half by rotation as describes above, FALSE otherwise.

Sample Input

rbgggrrggbgr
rrrbbbrrbbbr
rbgrbgrrrrrg
Sample Output

TRUE
FALSE
FALSE
*/
/*把每个面旋转到第一个面，然后第一个面与它对应的面不动再进行四次旋转，判断。*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=20;
char str[N],str1[N],str2[N];
int dir[6][6]={ {0,1,2,3,4,5},{1,5,2,3,0,4},{2,1,5,0,4,3},{3,1,0,5,4,2},
                {4,0,2,3,5,1},{5,4,2,3,1,0} };
bool fun();
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        for(int i=0;i<6;i++) str1[i]=str[i];
        for(int i=0;i<6;i++) str2[i]=str[i+6];
        if(fun()) puts("TRUE");
        else puts("FALSE");
    }
    return 0;
}
bool fun()
{
    char temp[N]={0};
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            temp[j]=str1[dir[i][j]];
        }
        for(int j=0;j<4;j++)
        {
            char cha;
            cha=temp[1];
            temp[1]=temp[2];
            temp[2]=temp[4];
            temp[4]=temp[3];
            temp[3]=cha;
            if(strcmp(temp,str2)==0) return true;
        }
    }
    return false;
}
