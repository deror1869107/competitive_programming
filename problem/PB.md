# 全球最大的男性同性交友網站上線啦！(Time Limit:5s)

## 題目
Github(aka. 全球最大的男性同性交友網站)使用了 Linus Torvalds 所寫的版本控制軟體 git。身為一個男性同性交友網站的開發人員，你要設計一種簡化版的 git，每次 Commit 只能新增一行或刪除一行 code ，並且為了讓 code 能有可讀性，你限制了每行 code 的字數。

## 輸入與輸出
首先輸入一整數N(1<=N<=2000)，代表總共有幾次 Commit，接下來是一整數L(1<=L<=2000)，代表原始版本(第0版本)程式碼的行數，接下來有L行，每行不超過80字元，代表原始版本的程式碼。

接下來有 N 行，代表 N 次 Commit ，分成兩種輸入：
在第 i 次 Commit 中( i 為 one-based )
第一種：
+T
code
代表在第 i - 1 版本的第 T 行前插入一行不超過80字元的字串 code ，成為第 i 版本
第二種：
-T
代表刪除第 i - 1 版本的第 T 行，成為第 i 版本

接下來有一整數Q(1<=Q<=1000)，代表總共有幾次詢問。

接下來有 Q 個數字 Ai (0<=Ai<=N)，代表詢問第 Ai 個版本的程式碼。
輸出第 Ai 個版本的程式碼，每筆輸出中間需要一個換行隔開，最後不用額外輸出換行。

## Sample Input
```
6
1
#include <iostream>
+2
using namespace std;
+3
int main(){
+4
cout << "Hello, world" << endl;
+5
}
-4
+4
cout << "hello, world" << endl;
7
0
1
2
3
4
5
6
```
## Sample Output
```
#include <iostream>

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
int main(){

#include <iostream>
using namespace std;
int main(){
cout << "Hello, world" << endl;

#include <iostream>
using namespace std;
int main(){
cout << "Hello, world" << endl;
}

#include <iostream>
using namespace std;
int main(){
}

#include <iostream>
using namespace std;
int main(){
cout << "hello, world" << endl;
}
```
